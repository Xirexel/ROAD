#ifndef WAVEFRACTAL_PARSER_H
#define WAVEFRACTAL_PARSER_H

#include <fstream>
#include <memory>
//#include <boost/optional.hpp>

#include "IROADoverDecodingOptions.h"


namespace proxy {

template<typename T>
class optional
{
public:

    optional()
        : m_initialized(false)
    {

    }

    bool is_initialized() const { return m_initialized ; }

    bool operator!() const noexcept { return !this->is_initialized() ; }

    optional& operator= ( T val )
      {
        m_initialized = true;

        value_type = val;

        return *this ;
      }

    T operator *() &
    {
        return value_type ;
    }

private:

    bool m_initialized;

    T value_type;

};

}



struct __WAVECHUNKHEAD
{
        char id[4];   // идентификатор типа файла
        unsigned int size;   // размер оставшейся части файла
};

struct __WAVEDESCR
{
        __WAVECHUNKHEAD chunkHead;   // размер оставшейся части файла
        char wave[4];  // формат файла

        bool check()
        {
            return  (
                    chunkHead.id[0] == 'R'
                    && chunkHead.id[1] == 'I'
                    && chunkHead.id[2] == 'F'
                    && chunkHead.id[3] == 'F'
                    )
                    &&
                    (
                    wave[0] == 'W'
                    && wave[1] == 'A'
                    && wave[2] == 'V'
                    && wave[3] == 'E'
                    );
        }
};

struct __WAVEFORMAT
{
        __WAVECHUNKHEAD chunkHead;
        unsigned short format;     // аудио формат
        unsigned short channels;    // число каналов
        unsigned int sampleRate;    // частота дискретизации
        unsigned int byteRate;     // скорость потока
        unsigned short blockAlign;  // смещение блока выборки
        unsigned short bitsPerSample;   // разрядность выборки

};

struct __WAVEDESCRDATA
{
        __WAVECHUNKHEAD chunkHead;
};

struct __FRACDESCR
{
    enum Format
    {
        EXPEREMENTAL,
        MAIN,
        ERROR
    };

    __FRACDESCR()
    {
    }

    Format check()
    {
        Format lresult = ERROR;

        if(this->_chunkHead.id[0] == 'R'
                && this->_chunkHead.id[1] == 'O'
                && this->_chunkHead.id[2] == 'A'
                && this->_chunkHead.id[3] == 'D')
        {
            lresult = EXPEREMENTAL;
        }
        else if(
                this->_chunkHead.id[0] == 'R'
                && this->_chunkHead.id[1] == 'o'
                && this->_chunkHead.id[2] == 'A'
                && this->_chunkHead.id[3] == 'd')
        {
            lresult = MAIN;
        }


        return lresult;
    }

    __WAVECHUNKHEAD _chunkHead;

    ROADdecoder::ROADover::IROADoverDecodingOptions * _format;
};

struct __FRACMAP
{

    bool check()
    {
        return this->_chunkHead.id[0] == 'M'
                && this->_chunkHead.id[1] == 'A'
                && this->_chunkHead.id[2] == 'P'
                && this->_chunkHead.id[3] == ' ';
    }

    __WAVECHUNKHEAD _chunkHead;
};

struct __FRACDESCRINDECES
{

    bool check()
    {
        return this->_chunkHead.id[0] == 'F'
                && this->_chunkHead.id[1] == 'I'
                && this->_chunkHead.id[2] == 'N'
                && this->_chunkHead.id[3] == 'D';
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
                          int dataPos)
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
                          int dataPos,
                          __FRACDESCR aFracdescr,
                          __FRACMAP aFractMap,
                          __FRACDESCRINDECES aFractDescrIndeces,
                          int aFractalMapPos,
                          int aFractDescrIndecesPos)
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

    int getDataPos()
    {
        return _dataPos;
    }

    __FRACDESCR getFracdescr()
    {
        return _fractDescr;
    }

    __FRACMAP getFracmap()
    {
        return _fractMap;
    }

    __FRACDESCRINDECES getFracdescrindeces()
    {
        return _fractDescrIndeces;
    }

    int getFractalMapPos()
    {
        return _fractalMapPos;
    }

    int getFractalDescrIndecesPos()
    {
        return _fractDescrIndecesPos;
    }

private:

    __WAVEDESCR _wavedescr;

    __WAVEFORMAT _waveformat;

    __WAVEDESCRDATA _wavedescrdata;

    __FRACDESCR _fractDescr;

    __FRACMAP _fractMap;

    __FRACDESCRINDECES _fractDescrIndeces;

    bool _fractal;

    int _dataPos;

    int _fractalMapPos;

    int _fractDescrIndecesPos;

};


class WaveFractal_parser
{
public:

    static WaveFractal_parser &getInstance();

    proxy::optional<WaveFractalFormatData> parse(FILE *pFile);

private:

    WaveFractal_parser();

    ~WaveFractal_parser();

    WaveFractal_parser(const WaveFractal_parser&);

    proxy::optional<__WAVEDESCR> parseWaveDescr(FILE * pFile);

    proxy::optional<__WAVEFORMAT> parseWaveFormat(FILE * pFile, __WAVECHUNKHEAD aHead);

    void parsExperementalFormat(FILE * pFile, int &aPos, __FRACDESCR &aFractDescr);

    void parsMainFormat(FILE * pFile, int &aPos, __FRACDESCR &aFractDescr);

};

#endif // WAVEFRACTAL_PARSER_H
