#include "wavefractalreader.h"
#include "roadoverwave.h"
#include "roadoverwavedecryptorstub.h"
#include "ROADoverDecodingOptionsExperemental.h"


#include <fstream>
#include <iostream>


#define UNUSED(x) (void)x;


WaveFractalReader::WaveFractalReader(QString filePath, quint32 scaleOfFrequency, quint32 bitsPerSample, QObject *parent) :
    QIODevice(parent),
    _ready(false),
    _IReader(nullptr),
    _readSizeOfData(0),
    _bitsPerSample(0),
    _blockAlign(0),
    _byteRate(0)
{

    do
    {
        using namespace ROADdecoder::ROADover;

        FILE * pFile;

        pFile = fopen (filePath.toStdString().c_str() , "r");

        auto lWaveFractalFormatData = WaveFractal_parser::getInstance().parse(pFile);

        fclose(pFile);

        if(!lWaveFractalFormatData)
            break;

        _waveFractalFormatData = *lWaveFractalFormatData;

        __WAVEFORMAT lWAVEFORMAT = _waveFractalFormatData.getWaveformat();

        __WAVEDESCRDATA lWAVEDESCRDATA = _waveFractalFormatData.getWavedescrdata();


        if(lWAVEFORMAT.format == 0)
            break;

        int loutputFrequency = lWAVEFORMAT.sampleRate;


        if(_waveFractalFormatData.isWaveFractal())
        {
            __FRACDESCR lFractDescr = _waveFractalFormatData.getFracdescr();

            auto lFractalDecdingOptions = lFractDescr._format;

            quint32 lsamplesPerRang = lFractalDecdingOptions->getOriginalMinSamplesPerRang() * scaleOfFrequency;

            int ltempFrequency = lsamplesPerRang * lWAVEFORMAT.sampleRate;

            int ltempDecFrequency = ltempFrequency / 10;

            int ldiffFrequency = ltempFrequency - ltempDecFrequency * 10;

            int ladditionFrequency = 10 - ldiffFrequency;

            loutputFrequency = ltempFrequency + ladditionFrequency;

            lFractalDecdingOptions->setFrequencyScale(lsamplesPerRang);

            unsigned int lencriptionCode = lFractalDecdingOptions->getEncryptionFormat();

            switch(lFractalDecdingOptions->getROADFormatMode())
            {
                case ROADdecoder::ROADover::EXPEREMENTAL:
                {
                    auto lexperementalOptions = dynamic_cast<ROADoverDecodingOptionsExperemental*>(lFractalDecdingOptions);

                    _bitsPerSample = bitsPerSample;

                    _blockAlign = (bitsPerSample >> 3)
                            * (lexperementalOptions->getAmountOfChannels());

                    _byteRate = lWAVEFORMAT.sampleRate
                            * (bitsPerSample >> 3)
                            * lexperementalOptions->getAmountOfChannels()
                            * lsamplesPerRang;

                    _channels = lexperementalOptions->getAmountOfChannels();

                    lexperementalOptions->setOriginalBitsPerSample(lWAVEFORMAT.bitsPerSample);


                    qint64 l = lWAVEDESCRDATA.chunkHead.size * lexperementalOptions->getAmountOfChannels();

                    l *= lsamplesPerRang;

                    qint64 g = bitsPerSample / lWAVEFORMAT.bitsPerSample;

                    qint64 k = l * g;

                    _sizeOfData = k;

                }
                break;

            case ROADdecoder::ROADover::MAIN:
            {
            //    auto lexperementalOptions = dynamic_cast<ROADoverDecodingOptionsExperemental*>(lFractalDecdingOptions);

                _bitsPerSample = bitsPerSample;

                _blockAlign = (bitsPerSample >> 3)
                        * (lFractalDecdingOptions->getAmountOfChannels());

                _byteRate = lWAVEFORMAT.sampleRate
                        * (bitsPerSample >> 3)
                        * lFractalDecdingOptions->getAmountOfChannels()
                        * lsamplesPerRang;

                _channels = lFractalDecdingOptions->getAmountOfChannels();

           //     lexperementalOptions->setOriginalBitsPerSample(lWAVEFORMAT.bitsPerSample);


                qint64 l = lWAVEDESCRDATA.chunkHead.size * lFractalDecdingOptions->getAmountOfChannels();

                l *= lsamplesPerRang;

                qint64 g = bitsPerSample / lWAVEFORMAT.bitsPerSample;

                qint64 k = l * g;

                _sizeOfData = k;

            }
                break;

            case ROADdecoder::ROADover::UNKNOWN:
            default:
                return;
            }


            try
            {
            switch(lWAVEFORMAT.bitsPerSample)
            {

            case 8:

                _IReader = lencriptionCode == 0? new ROADoverWAVE<quint8, quint8>(lFractalDecdingOptions, _waveFractalFormatData, filePath.toStdString()):
                                                 new ROADoverWAVEDecryptorStub<quint8, quint8>(lFractalDecdingOptions, _waveFractalFormatData, filePath.toStdString());
                break;

            case 16:

                switch(bitsPerSample)
                {
                case 16:
                default:

                    _IReader = lencriptionCode == 0? new ROADoverWAVE<qint16, qint16>(lFractalDecdingOptions, _waveFractalFormatData, filePath.toStdString()):
                                                     new ROADoverWAVEDecryptorStub<qint16, qint16>(lFractalDecdingOptions, _waveFractalFormatData, filePath.toStdString());

                    break;
                case 32:

                    _IReader = lencriptionCode == 0? new ROADoverWAVE<qint16, qint32>(lFractalDecdingOptions, _waveFractalFormatData, filePath.toStdString()):
                                                     new ROADoverWAVEDecryptorStub<qint16, qint32>(lFractalDecdingOptions, _waveFractalFormatData, filePath.toStdString());

                    break;
                }



              break;

            case 32:

                _IReader = lencriptionCode == 0? new ROADoverWAVE<qint32, qint32>(lFractalDecdingOptions, _waveFractalFormatData, filePath.toStdString()):
                                                 new ROADoverWAVEDecryptorStub<qint32, qint32>(lFractalDecdingOptions, _waveFractalFormatData, filePath.toStdString());

                break;

            default:
                _IReader = nullptr;
                break;
            }

            }
            catch(std::exception aException)
            {
                std::cerr << aException.what() << std::endl;

                return;
            }
        }

        if(_IReader != nullptr)
        {

            _format.setChannelCount(_channels);

            _format.setCodec("audio/pcm");

            _format.setSampleRate(loutputFrequency);

            _format.setSampleSize(bitsPerSample);

            _format.setSampleType(QAudioFormat::SignedInt);

            _format.setByteOrder(QAudioFormat::LittleEndian);

            open(QIODevice::ReadOnly);


            _ready = true;
        }

    }
    while(false);


}

WaveFractalReader::~WaveFractalReader()
{
    delete _IReader;
}

void WaveFractalReader::start()
{

}

void WaveFractalReader::stop()
{

}

qint64 WaveFractalReader::readData(char *data, qint64 maxlen)
{



    std::cerr << "maxlen: " << maxlen << std::endl;

    qint64 result = 0;

    if(_IReader != nullptr)
        result = _IReader->readData(data, (maxlen >> 1) << 1);


    if( result < 0)
    {
        emit finish();

        return 0;
    }

    this->_readSizeOfData += (result / this->_blockAlign);

    emitSignalPosition(this->_readSizeOfData);

    return result;
}

qint64 WaveFractalReader::writeData(const char *data, qint64 len)
{
    Q_UNUSED(data);
    Q_UNUSED(len);

    return 0;
}

qint64 WaveFractalReader::bytesAvailable() const
{
    qint64 result = 0;

    return result + QIODevice::bytesAvailable();
}

QAudioFormat WaveFractalReader::getFormat() const
{
    return _format;
}

bool WaveFractalReader::atEnd() const
{
    return true;
}

qint64 WaveFractalReader::getSizeOfData()
{
    return _sizeOfData;
}

qint64 WaveFractalReader::getReadSizeOfData()
{
    return this->_readSizeOfData;
}

qint32 WaveFractalReader::getBitsPerSample()
{
    return this->_bitsPerSample;
}

qint32 WaveFractalReader::getBlockAlign()
{
    return this->_blockAlign;
}

quint32 WaveFractalReader::getByteRate()
{
    return this->_byteRate;
}

quint16 WaveFractalReader::getChannels()
{
    return this->_channels;
}

qint64 WaveFractalReader::getSampleAmount()
{
    return _IReader->getSampleAmount();
}

bool WaveFractalReader::seek(qint64 pos)
{
    UNUSED(pos);

    bool result = true;

    return result;
}

void WaveFractalReader::setRelatedPosition(qreal value)
{
    if(value > 1.0)
        return;

    qint64 pos = static_cast<qint64>(static_cast<qreal>(getSampleAmount()) * value);

    this->_readSizeOfData = pos;

    _IReader->setPosition(pos);
}

void WaveFractalReader::emitSignalPosition(qint64 value)
{    
    qreal result = static_cast<qreal>(value) / static_cast<qreal>(getSampleAmount());

    emit relatedPosition(result);
}
