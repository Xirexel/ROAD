#include "roadoverwavecoder.h"
#include "../../ListItem/interfaces.h"
#include "WaveFractalWriter.h"


ROADoverWAVECoder::ROADoverWAVECoder(QString outputFile, IROADoverRawReader *aPtrReader, IOriginalAudioStreamOptions *aOriginalAudioStreamOptions, ROADoverEncoding::ROADoverEncodingOptions aOptions)
    :ROADoverEncoding::AROADover(aOptions),
      ptrReader(aPtrReader),
      _superFrameSampleLength(aOptions.getFrameSampleLength() * aOptions.getSuperframeLength())
{
    temp = QVarLengthArray<double*>(aOptions.getChannels());

    __WAVEDESCR aWaveDesc;
    __WAVEFORMAT awaveformat;
    __WAVEDESCRDATA aWaveData;
    __FRACDESCR aFractalFormat;


    awaveformat.bitsPerSample = aOriginalAudioStreamOptions->getBPS();

    awaveformat.blockAlign = aOriginalAudioStreamOptions->getBPS() >> 3;

    awaveformat.byteRate = (aOriginalAudioStreamOptions->getBPS() >> 3) *
            (aOriginalAudioStreamOptions->getFrequency()/aOptions.getShortestRangSampleLength());

    awaveformat.channels = 1;

    awaveformat.format = 1;

    awaveformat.sampleRate = aOriginalAudioStreamOptions->getFrequency()/aOptions.getShortestRangSampleLength();

    awaveformat.chunkHead.size = 16;


    switch(aOptions.getMixingChannelsMode())
    {
    case ROADoverEncoding::LplusR:
    default:
        aFractalFormat._format._averDiffMode = 0;
        break;

    case ROADoverEncoding::LminusR:
        aFractalFormat._format._averDiffMode = 1;
        break;

    case ROADoverEncoding::NONE:
        aFractalFormat._format._averDiffMode = 2;
        break;

    }

    aFractalFormat._format._domainShift = aOptions.getDomainShift();

    aFractalFormat._format._domainShiftScale = aOptions.getShortestRangSampleLength();

    aFractalFormat._format._encriptionCode = aOptions.getEncryptionFromat();

    aFractalFormat._format._frameRangeLength = aOptions.getFrameSampleLength() / aOptions.getShortestRangSampleLength();

    aFractalFormat._format._originalAmountOfChannels = aOptions.getChannels();

    aFractalFormat._format._superFrameLength = aOptions.getSuperframeLength();


    aFractalFormat._chunkHead.size = sizeof(__FRACFORMAT);

    switch(aOptions.getFormat())
    {
    case ROADoverEncoding::EXPEREMENTAL:
        aFractalFormat._format._format = 0;
        break;
    }





    switch(aOptions.getBitsPerSample())
    {
        case 8:

        _unique_ptrAWaveFractalWriter.reset(new WaveFractalWriter<quint8>(outputFile, aWaveDesc, awaveformat, aWaveData, aFractalFormat));

        break;

    case 16:
    default:

        _unique_ptrAWaveFractalWriter.reset(new WaveFractalWriter<qint16>(outputFile, aWaveDesc, awaveformat, aWaveData, aFractalFormat));

        break;

    case 32:

        _unique_ptrAWaveFractalWriter.reset(new WaveFractalWriter<qint32>(outputFile, aWaveDesc, awaveformat, aWaveData, aFractalFormat));

        break;

    }
}


ROADoverEncoding::Result ROADoverWAVECoder::readRawData(ROADoverEncoding::IRawDataBuffer* aBuffer)
{
    ROADoverEncoding::Result result = ROADoverEncoding::ERROR;

    temp.clear();

    for(decltype(aBuffer->getCount()) index = 0;
        index < aBuffer->getCount();
        ++index)
    {
        temp.append(aBuffer->getData(index));
    }

    Result r = ptrReader->readData(temp, _superFrameSampleLength);

    switch(r)
    {
    case ERROR:
        result = ROADoverEncoding::ERROR;
        break;

    case DONE:
        result = ROADoverEncoding::DONE;
        break;

    case FINISHFILE:
        result = ROADoverEncoding::FINISHFILE;
        break;

    }


    return result;
}

unsigned int ROADoverWAVECoder::convertDoubleArrayToByteArray(double* aDoubleData, unsigned int aLength, char* aByteData)
{
    unsigned int result = 0;

    result = _unique_ptrAWaveFractalWriter->convertDoubleArrayToByteArray(aDoubleData, aLength, aByteData);

    return result;
}

void ROADoverWAVECoder::writePrelistening(double* aData, unsigned int aLength)
{
    _unique_ptrAWaveFractalWriter->writePrelistening(aData, aLength);
}
void ROADoverWAVECoder::writeROADdata(char* aData, unsigned int aLength, unsigned int aPrelisteningCRC, unsigned int aROADdataCRC)
{
    _unique_ptrAWaveFractalWriter->writeROADdata(aData, aLength, aPrelisteningCRC, aROADdataCRC);
}

Result ROADoverWAVECoder::doEncoding()
{
    Result result = ERROR;

    ROADoverEncoding::Result resultROAD = this->doOneStepEncoding();

    switch(resultROAD)
    {
    case ROADoverEncoding::ERROR:
        result = ERROR;
        break;

    case ROADoverEncoding::DONE:
        result = DONE;
        break;

    case ROADoverEncoding::FINISHFILE:
        result = FINISHFILE;
        break;

    }

    return result;
}

void ROADoverWAVECoder::flushAndCloseFile()
{
    _unique_ptrAWaveFractalWriter->flushAndCloseFile();
}

void ROADoverWAVECoder::reject()
{
    _unique_ptrAWaveFractalWriter->reject();
}
