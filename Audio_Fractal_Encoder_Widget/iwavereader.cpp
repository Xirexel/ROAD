#include "iwavereader.h"
#include "wave_parser.h"


IWaveReader::IWaveReader(QString filePath)
    : _isWaveFile(false), _readSampleCount(0), _fullSampleCount(0)
{
    do
    {

        _file.setFileName(filePath);

        if(!_file.open(QIODevice::ReadOnly))
            return;

        _dataStream.setDevice(&_file);

        auto result = Wave_parser::getInstance().parse(_dataStream);

        if(!std::get<0>(result))
            break;

        __WAVEFORMAT lwaveformat = std::get<1>(result).getWaveformat();

        if(lwaveformat.format != 1 || lwaveformat.channels != 2)
                break;

        __WAVEDESCRDATA ldescrdata = std::get<1>(result).getWavedescrdata();

        _fullSampleCount = ldescrdata.chunkHead.size / lwaveformat.blockAlign;

        _isWaveFile = true;

    }
    while(false);

    if(!_isWaveFile)
        _file.close();
}

IWaveReader::~IWaveReader()
{
    _file.close();
}

bool IWaveReader::isOpen()
{
    return _isWaveFile;
}

qint32 IWaveReader::getPercentOfProcessedFile()
{
    qint32 result = -1;

    do
    {
        if(!_isWaveFile)
            break;

        qreal lproportion = static_cast<qreal>(_readSampleCount) / static_cast<qreal>(_fullSampleCount);

        quint32 lprocessedPercent =  lproportion * 100;

        result = lprocessedPercent;
    }
    while(false);

    return result;
}
