#ifndef WAVEREADER_H
#define WAVEREADER_H

#include <thread>
#include <mutex>

#include "IReader.h"
#include "wavefractal_parser.h"

template<typename T>
class WaveReader : public IReader
{

public:
    explicit WaveReader(QDataStream *dataStream, WaveFractalFormatData waveFractalFormatData, QObject *parent = 0)
        :IReader(dataStream, parent),
        _waveFractalFormatData(waveFractalFormatData),
        _pos(0)
    {

        _waveFormat = _waveFractalFormatData.getWaveformat();

        _wavedescrdata = _waveFractalFormatData.getWavedescrdata();

        _sampleAmount = _wavedescrdata.chunkHead.size / _waveFormat.blockAlign;

        _offset = _waveFractalFormatData.getDataPos();
    }

    qint64 readData(char *data, qint64 maxlen)
    {
        qint64 result = 0;

        if( _pos >= _sampleAmount)
        {
            emit finish();

            return result;
        }

        result = _dataStream->readRawData(data, maxlen);

        _pos += (result / _waveFormat.blockAlign);

        emit pos(_pos);

        return result;
    }

    qint64 getSampleAmount()
    {
        return _sampleAmount;
    }

    void setPosition(qint64 position)
    {

        qint64 newPos = position * _waveFormat.blockAlign;

//        qDebug(QString("%1").arg(position).toStdString().c_str());

        newPos += _offset;

        _dataStream->device()->seek(newPos);

        this->_pos = position;

//        emit pos(_pos);
    }

private:

    typedef T typeSample;

    WaveFractalFormatData _waveFractalFormatData;

    __WAVEFORMAT _waveFormat;

    __WAVEDESCRDATA _wavedescrdata;

    qint64 _sampleAmount;

    qint64 _pos;

    qint64 _offset;

};

#endif // WAVEREADER_H
