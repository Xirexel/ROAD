#ifndef WAVE_PARSER_H
#define WAVE_PARSER_H

#include <QString>
#include <QFile>
#include <QDataStream>



struct __WAVECHUNKHEAD
{
        char id[4];   // идентификатор типа файла
        quint32 size;   // размер оставшейся части файла

};

struct __WAVEDESCR
{
        __WAVECHUNKHEAD chunkHead;   // размер оставшейся части файла
        char wave[4];  // формат файла

};

struct __WAVEFORMAT
{
        __WAVECHUNKHEAD chunkHead;
        quint16 format;     // аудио формат
        quint16 channels;    // число каналов
        quint32 sampleRate;    // частота дискретизации
        quint32 byteRate;     // скорость потока
        quint16 blockAlign;  // смещение блока выборки
        quint16 bitsPerSample;   // разрядность выборки

};

struct __WAVEDESCRDATA
{
        __WAVECHUNKHEAD chunkHead;
};

class WaveFormatData
{
public:
    WaveFormatData()
        : _dataPosition(-1){}

    WaveFormatData(__WAVEDESCR aWavedescr,
                   __WAVEFORMAT aWaveformat,
                   __WAVEDESCRDATA aWavedescrdata,
                   qint64 aDataPosition)
        : _wavedescr(aWavedescr),
          _waveformat(aWaveformat),
          _wavedescrdata(aWavedescrdata),
          _dataPosition(aDataPosition)
    {

    }

    __WAVEDESCR getWavedescr()
    {
        return _wavedescr;
    }

    __WAVEFORMAT getWaveformat()
    {
        return _waveformat;
    }

    __WAVEDESCRDATA getWavedescrdata()
    {
        return _wavedescrdata;
    }

    qint64 getPosition()
    {
        return this->_dataPosition;
    }

private:

    __WAVEDESCR _wavedescr;

    __WAVEFORMAT _waveformat;

    __WAVEDESCRDATA _wavedescrdata;

    qint64 _dataPosition;

};



class Wave_parser
{
public:

    static Wave_parser &getInstance();

    std::tuple<bool, WaveFormatData> parse(QDataStream &dataStream);

private:

    Wave_parser();

    ~Wave_parser();

    Wave_parser(const Wave_parser&);

    std::tuple<bool, __WAVEDESCR> parseWaveDescr(QDataStream &dataStream);

    std::tuple<bool, __WAVEFORMAT> parseWaveFormat(__WAVECHUNKHEAD aHead, QDataStream &dataStream);

};

#endif // WAVE_PARSER_H
