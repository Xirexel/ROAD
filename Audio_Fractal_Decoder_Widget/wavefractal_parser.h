#ifndef WAVEFRACTAL_PARSER_H
#define WAVEFRACTAL_PARSER_H

#include "wave_parser.h"

struct __FRACFORMAT
{
        quint32 _format;
        quint32 _superFrameLength;
        quint32 _frameRangeLength;
        quint32 _domainShift;
        quint32 _domainShiftScale;
        quint32 _originalAmountOfChannels;
        quint32 _averDiffMode;
        quint32 _encriptionCode;
};

struct __FRACDESCR
{

    __FRACDESCR()
    {
        _chunkHead.id[0] = 'R';

        _chunkHead.id[1] = 'O';

        _chunkHead.id[2] = 'A';

        _chunkHead.id[3] = 'D';
    }

    bool operator == (const __FRACDESCR &arg)
    {
        return this->_chunkHead.id[0] == arg._chunkHead.id[0]
                && this->_chunkHead.id[1] == arg._chunkHead.id[1]
                && this->_chunkHead.id[2] == arg._chunkHead.id[2]
                && this->_chunkHead.id[3] == arg._chunkHead.id[3];
    }

        __WAVECHUNKHEAD _chunkHead;

        __FRACFORMAT _format;
};

struct __FRACMAP
{

    __FRACMAP()
    {
        _chunkHead.id[0] = 'M';

        _chunkHead.id[1] = 'A';

        _chunkHead.id[2] = 'P';

        _chunkHead.id[3] = ' ';

    }

    bool operator == (const __FRACMAP &arg)
    {
        return this->_chunkHead.id[0] == arg._chunkHead.id[0]
                && this->_chunkHead.id[1] == arg._chunkHead.id[1]
                && this->_chunkHead.id[2] == arg._chunkHead.id[2]
                && this->_chunkHead.id[3] == arg._chunkHead.id[3];
    }
        __WAVECHUNKHEAD _chunkHead;
};

struct __FRACDESCRINDECES
{

    __FRACDESCRINDECES()
    {
        _chunkHead.id[0] = 'F';

        _chunkHead.id[1] = 'I';

        _chunkHead.id[2] = 'N';

        _chunkHead.id[3] = 'D';

    }

    bool operator == (const __FRACDESCRINDECES &arg)
    {
        return this->_chunkHead.id[0] == arg._chunkHead.id[0]
                && this->_chunkHead.id[1] == arg._chunkHead.id[1]
                && this->_chunkHead.id[2] == arg._chunkHead.id[2]
                && this->_chunkHead.id[3] == arg._chunkHead.id[3];
    }
        __WAVECHUNKHEAD _chunkHead;
};


class WaveFractalFormatData
{
public:
    WaveFractalFormatData(){}

    WaveFractalFormatData(__WAVEDESCR aWavedescr,
                          __WAVEFORMAT aWaveformat,
                          __WAVEDESCRDATA aWavedescrdata,
                          qint64 dataPos)
        : _wavedescr(aWavedescr),
          _waveformat(aWaveformat),
          _wavedescrdata(aWavedescrdata),
          _fractal(false),
          _dataPos(dataPos)
    {

    }

    WaveFractalFormatData(__WAVEDESCR aWavedescr,
                          __WAVEFORMAT aWaveformat,
                          __WAVEDESCRDATA aWavedescrdata,
                          qint64 dataPos,
                          __FRACDESCR aFracdescr,
                          __FRACMAP aFractMap,
                          __FRACDESCRINDECES aFractDescrIndeces,
                          qint64 aFractalMapPos,
                          qint64 aFractDescrIndecesPos)
        : _wavedescr(aWavedescr),
          _waveformat(aWaveformat),
          _wavedescrdata(aWavedescrdata),
          _fractDescr(aFracdescr),
          _fractMap(aFractMap),
          _fractDescrIndeces(aFractDescrIndeces),
          _fractal(true),
          _dataPos(dataPos),
          _fractalMapPos(aFractalMapPos),
          _fractDescrIndecesPos(aFractDescrIndecesPos)
    {

    }

    bool isWaveFractal()
    {
        return _fractal;
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

    qint64 getDataPos()
    {
        return _dataPos;
    }

    std::tuple<bool, __FRACDESCR> getFracdescr()
    {
        return std::make_tuple(_fractal, _fractDescr);
    }

    std::tuple<bool, __FRACMAP> getFracmap()
    {
        return std::make_tuple(_fractal, _fractMap);
    }

    std::tuple<bool, __FRACDESCRINDECES> getFracdescrindeces()
    {
        return std::make_tuple(_fractal, _fractDescrIndeces);
    }

    std::tuple<bool, qint64> getFractalMapPos()
    {
        return std::make_tuple(_fractal, _fractalMapPos);
    }

    std::tuple<bool, qint64> getFractalDescrIndecesPos()
    {
        return std::make_tuple(_fractal, _fractDescrIndecesPos);
    }

private:

    __WAVEDESCR _wavedescr;

    __WAVEFORMAT _waveformat;

    __WAVEDESCRDATA _wavedescrdata;

    __FRACDESCR _fractDescr;

    __FRACMAP _fractMap;

    __FRACDESCRINDECES _fractDescrIndeces;

    bool _fractal;

    qint64 _dataPos;

    qint64 _fractalMapPos;

    qint64 _fractDescrIndecesPos;

};


class WaveFractal_parser
{
public:

    static WaveFractal_parser &getInstance();

    std::tuple<bool, WaveFractalFormatData> parse(QDataStream &dataStream);

private:

    WaveFractal_parser();

    ~WaveFractal_parser();

    WaveFractal_parser(const WaveFractal_parser&);

    std::tuple<bool, __WAVEDESCR> parseWaveDescr(QDataStream &dataStream);

    std::tuple<bool, __WAVEFORMAT> parseWaveFormat(__WAVECHUNKHEAD aHead, QDataStream &dataStream);
};

#endif // WAVEFRACTAL_PARSER_H
