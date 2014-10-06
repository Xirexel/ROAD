#include "roadoverwavecoder.h"
#include "../../ListItem/interfaces.h"
#include "WaveFractalWriter.h"
#include "IDoubleDataContainer.h"


ROADoverWAVECoder::ROADoverWAVECoder(QString outputFile, IROADoverRawReader *aPtrReader, IOriginalAudioStreamOptions *aOriginalAudioStreamOptions, std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> &aOptions)
    :ROADcoder::ROADoverCoder::ROADover(aOptions),
      ptrReader(aPtrReader)
{
    temp = QVarLengthArray<double*>(aOriginalAudioStreamOptions->getAmountOfChannels());

    __WAVEDESCR aWaveDesc;
    __WAVEFORMAT awaveformat;
    __WAVEDESCRDATA aWaveData;

    awaveformat.bitsPerSample = aOriginalAudioStreamOptions->getBPS();

    awaveformat.blockAlign = aOriginalAudioStreamOptions->getBPS() >> 3;

    awaveformat.byteRate = (aOriginalAudioStreamOptions->getBPS() >> 3) *
            (aOriginalAudioStreamOptions->getFrequency()/getRangSampleLength());

    awaveformat.channels = 1;

    awaveformat.format = 1;

    awaveformat.sampleRate = aOriginalAudioStreamOptions->getFrequency()/getRangSampleLength();

    awaveformat.chunkHead.size = 16;



    switch(getBitsPerSample())
    {
        case 8:

        _unique_ptrAWaveFractalWriter.reset(new WaveFractalWriter<quint8>(outputFile, aWaveDesc, awaveformat, aWaveData));

        break;

    case 16:
    default:

        _unique_ptrAWaveFractalWriter.reset(new WaveFractalWriter<qint16>(outputFile, aWaveDesc, awaveformat, aWaveData));

        break;

    case 32:

        _unique_ptrAWaveFractalWriter.reset(new WaveFractalWriter<qint32>(outputFile, aWaveDesc, awaveformat, aWaveData));

        break;

    }
}


bool ROADoverWAVECoder::lockResource()
{
    return true;
}

bool ROADoverWAVECoder::unlockResource()
{
    return true;
}
ROADcoder::ROADoverCoder::Result ROADoverWAVECoder::readRawData(ROADcoder::ROADoverCoder::RawDataBuffer &aRawDataBuffer)
{

    quint32 lsuperFrameSampleLength;

    ROADcoder::ROADoverCoder::Result result = ROADcoder::ROADoverCoder::ERROR;

    temp.clear();

    for(decltype(aRawDataBuffer.getCount()) index = 0;
        index < aRawDataBuffer.getCount();
        ++index)
    {
        auto lptrIDoubleDataContainer = aRawDataBuffer.getIDoubleDataContainer(index);

        lsuperFrameSampleLength = lptrIDoubleDataContainer->getLength();

        temp.append( lptrIDoubleDataContainer->getData());
    }

    Result r = ptrReader->readData(temp, lsuperFrameSampleLength);

    switch(r)
    {
    case ERROR:
        result = ROADcoder::ROADoverCoder::ERROR;
        break;

    case DONE:
        result = ROADcoder::ROADoverCoder::DONE;
        break;

    case FINISHFILE:
        result = ROADcoder::ROADoverCoder::FINISHFILE;
        break;

    }

    return result;
}

unsigned int ROADoverWAVECoder::convertDoubleArrayIntoByteArray(const double* aDoubleData, unsigned int aLengthDoubleArray, unsigned char* aByteData)
{
    return _unique_ptrAWaveFractalWriter->convertDoubleArrayToByteArray(aDoubleData, aLengthDoubleArray, aByteData);
}

void ROADoverWAVECoder::writePreListening(double* aDoubleData, unsigned int aLength)
{
    _unique_ptrAWaveFractalWriter->writePrelistening(aDoubleData, aLength);
}

void ROADoverWAVECoder::writeROADdata(unsigned char* aByteData, unsigned int aLength)
{
    _unique_ptrAWaveFractalWriter->writeROADdata(aByteData, aLength);
}

Result ROADoverWAVECoder::doEncoding()
{
    Result result = ERROR;

    ROADcoder::ROADoverCoder::Result resultROAD = this->doOneStepEncoding();

    switch(resultROAD)
    {
    case ROADcoder::ROADoverCoder::ERROR:
        result = ERROR;
        break;

    case ROADcoder::ROADoverCoder::DONE:
        result = DONE;
        break;

    case ROADcoder::ROADoverCoder::FINISHFILE:
        result = FINISHFILE;
        break;

    }

    return result;
}

void ROADoverWAVECoder::flushAndCloseFile()
{
    auto lptrFractalFormatRawData = getFractalFormatRawData();

    _unique_ptrAWaveFractalWriter->flushAndCloseFile(std::get<0>(lptrFractalFormatRawData),
                                                     std::get<1>(lptrFractalFormatRawData));
}

void ROADoverWAVECoder::reject()
{
    _unique_ptrAWaveFractalWriter->reject();
}
