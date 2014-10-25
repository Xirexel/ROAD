#include "wavefractalreader.h"
#include "roadoverwave.h"


#include <fstream>



WaveFractalReader::WaveFractalReader(QString filePath, quint32 samplesPerRange, quint32 bitsPerSample, QObject *parent) :
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
        FILE * pFile;

        pFile = fopen (filePath.toStdString().c_str() , "r");

        WaveFractalFormatData lWaveFractalFormatData = WaveFractal_parser::getInstance().parse(pFile);

        fclose(pFile);

        if(!lWaveFractalFormatData.isWaveFractal())
            break;

        _waveFractalFormatData = lWaveFractalFormatData;

        __WAVEFORMAT lWAVEFORMAT = _waveFractalFormatData.getWaveformat();

        __WAVEDESCRDATA lWAVEDESCRDATA = _waveFractalFormatData.getWavedescrdata();


        if(lWAVEFORMAT.format == 0)
            break;

        _ready = true;

        if(_waveFractalFormatData.isWaveFractal())
        {
            ROADover::ROADoverDecodingOptions options;

            __FRACDESCR lFractDescr = _waveFractalFormatData.getFracdescr();

            options.setAmountOfChannels(lFractDescr._format._originalAmountOfChannels);

            options.setFrameRangLength(lFractDescr._format._frameRangeLength);


            ROADover::MixingChannelsMode lMixingChannelMode = ROADover::NONE;

            switch(lFractDescr._format._averDiffMode)
            {
            case 0:
            default:
                lMixingChannelMode = ROADover::LplusR;
                break;

            case 1:
                lMixingChannelMode = ROADover::LminusR;
                break;

            case 2:
                lMixingChannelMode = ROADover::NONE;
                break;

            }



            options.setMixingChannelsMode(lMixingChannelMode);

            options.setRelativeDomainShift(lFractDescr._format._domainShift);

            options.setSamplesPerRang(samplesPerRange);

            options.setSuperframeLength(lFractDescr._format._superFrameLength);

            options.setScaleDomainShift(lFractDescr._format._domainShiftScale);

            options.setBitsPerSample(lWAVEFORMAT.bitsPerSample);


            switch(lWAVEFORMAT.bitsPerSample)
            {

            case 8:
                _IReader = new ROADoverWAVE<quint8, quint8>(options, _waveFractalFormatData, filePath.toStdString());
                break;

            case 16:

                switch(bitsPerSample)
                {
                case 16:
                default:
                    _IReader = new ROADoverWAVE<qint16, qint16>( options,_waveFractalFormatData, filePath.toStdString());
                    break;
                case 32:
                    _IReader = new ROADoverWAVE<qint16, qint32>( options,_waveFractalFormatData, filePath.toStdString());

                    break;
                }


                break;

            case 32:
                _IReader = new ROADoverWAVE<qint32, qint32>( options,_waveFractalFormatData, filePath.toStdString());
                break;

            default:
                _IReader = nullptr;
                break;
            }

            qint64 l = lWAVEDESCRDATA.chunkHead.size * lFractDescr._format._originalAmountOfChannels;

            l *= samplesPerRange;

            qint64 g = bitsPerSample / lWAVEFORMAT.bitsPerSample;

            qint64 k = l * g;

            _sizeOfData = k;

            lWAVEFORMAT.bitsPerSample = bitsPerSample;

            lWAVEFORMAT.sampleRate = lWAVEFORMAT.sampleRate * samplesPerRange;

            lWAVEFORMAT.channels = lFractDescr._format._originalAmountOfChannels;

            lWAVEFORMAT.blockAlign = (bitsPerSample >> 3) * lFractDescr._format._originalAmountOfChannels;




        }

        if(_IReader != nullptr)
        {

            _format.setChannelCount(lWAVEFORMAT.channels);

            _format.setCodec("audio/pcm");

            _format.setSampleRate(lWAVEFORMAT.sampleRate);

            _format.setSampleSize(lWAVEFORMAT.bitsPerSample);

            _format.setSampleType(QAudioFormat::SignedInt);

            _format.setByteOrder(QAudioFormat::LittleEndian);



            _bitsPerSample = lWAVEFORMAT.bitsPerSample;

            _blockAlign = lWAVEFORMAT.blockAlign;

            _byteRate = lWAVEFORMAT.sampleRate * lWAVEFORMAT.blockAlign;

            _channels = lWAVEFORMAT.channels;

            open(QIODevice::ReadOnly);
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
    qint64 result = 0;

    if(_IReader != nullptr)
        result = _IReader->readData(data, maxlen);

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
    return _readSizeOfData;
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
    bool result = true;

    return result;
}

void WaveFractalReader::setRelatedPosition(qreal value)
{
    if(value > 1.0)
        return;

    qint64 pos = static_cast<qint64>(static_cast<qreal>(getSampleAmount()) * value);

    _IReader->setPosition(pos);
}

void WaveFractalReader::emitSignalPosition(qint64 value)
{    
    qreal result = static_cast<qreal>(value) / static_cast<qreal>(getSampleAmount());

    emit relatedPosition(result);
}
