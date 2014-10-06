#include "wavefractalreader.h"
#include "wavereader.h"
#include "fractalreader.h"



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

        _file.setFileName(filePath);

        if(!_file.open(QIODevice::ReadOnly))
            break;

        _dataStream.setDevice(&_file);

        _dataStream.setByteOrder(QDataStream::LittleEndian);

        auto result = WaveFractal_parser::getInstance().parse(_dataStream);

        if(!std::get<0>(result))
            break;

        _waveFractalFormatData = std::get<1>(result);

        __WAVEFORMAT lWAVEFORMAT = _waveFractalFormatData.getWaveformat();

        __WAVEDESCRDATA lWAVEDESCRDATA = _waveFractalFormatData.getWavedescrdata();


        if(lWAVEFORMAT.format == 0)
            break;

        _ready = true;

        if(!_waveFractalFormatData.isWaveFractal())
        {
            switch(lWAVEFORMAT.bitsPerSample)
            {

            case 8:
                _IReader = new WaveReader<quint8>(&_dataStream, _waveFractalFormatData, this);
                break;

            case 16:
                _IReader = new WaveReader<qint16>(&_dataStream, _waveFractalFormatData, this);
                break;

            case 32:
                _IReader = new WaveReader<qint32>(&_dataStream, _waveFractalFormatData, this);
            break;

            default:
                _IReader = nullptr;
                break;
            }

            _sizeOfData = lWAVEDESCRDATA.chunkHead.size;


        }
        else
        {
            FractalDecoding::FractalDecodingOptions options;

            __FRACDESCR lFractDescr = std::get<1>(_waveFractalFormatData.getFracdescr());

            options.setAmountOfChannels(lFractDescr._format._originalAmountOfChannels);

            options.setFrameLength(lFractDescr._format._frameRangeLength);


            FractalDecoding::MixingChannelMode lMixingChannelMode = FractalDecoding::LPLUSR;

            switch(lFractDescr._format._averDiffMode)
            {
            case 0:
            default:
                lMixingChannelMode = FractalDecoding::LPLUSR;
                break;

            case 1:
                lMixingChannelMode = FractalDecoding::LMINUSR;
                break;

            case 2:
                lMixingChannelMode = FractalDecoding::NONE;
                break;

            }



            options.setMixingChannelMode(lMixingChannelMode);

            options.setRelativeDomainShift(lFractDescr._format._domainShift);

            options.setSamplesPerRang(samplesPerRange);

            options.setSuperFrameLength(lFractDescr._format._superFrameLength);

            options.setScaleDomainShift(lFractDescr._format._domainShiftScale);



            switch(lWAVEFORMAT.bitsPerSample)
            {

            case 8:
                _IReader = new FractalReader<quint8, quint8>(&_dataStream, _waveFractalFormatData, options, this);
                break;

            case 16:

                switch(bitsPerSample)
                {
                case 16:
                default:
                    _IReader = new FractalReader<qint16, qint16>(&_dataStream, _waveFractalFormatData, options, this);
                    break;
                case 32:
                    _IReader = new FractalReader<qint16, qint32>(&_dataStream, _waveFractalFormatData, options, this);

                    break;
                }


                break;

            case 32:
                _IReader = new FractalReader<qint32, qint32>(&_dataStream, _waveFractalFormatData, options, this);
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
            connect(_IReader, SIGNAL(finish()), SIGNAL(finish()));

            connect(_IReader, SIGNAL(pos(qint64)), SLOT(emitSignalPosition(qint64)));


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
    _file.close();

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
