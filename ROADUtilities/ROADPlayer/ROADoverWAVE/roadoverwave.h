#ifndef ROADOVERWAVE_H
#define ROADOVERWAVE_H

#include <fstream>
#include <limits>


#include <QFile>


#include "ROADover.h"
#include "../AudioPlayer/IReader.h"
#include "wavefractal_parser.h"
#include "IRawDataBuffer.h"
#include "IDoubleDataContainer.h"

typedef long long int64;

#define UNUSED(x) (void)x;

template<typename T, typename O>
class ROADoverWAVE: public ROADdecoder::ROADover::ROADover, public IReader
{

public:

    ROADoverWAVE(ROADdecoder::ROADover::IROADoverDecodingOptions* aOptions,
                 WaveFractalFormatData aWaveFractalFormatData,
                 std::string aFilePath)
        :ROADover(aOptions),
          max(std::numeric_limits<typeOutSample>::max()),
          min(std::numeric_limits<typeOutSample>::min()),
          _sampleScale(1),
          _waveFractalFormatData(aWaveFractalFormatData),
          _pos(0),
          _nextPos(0),
          _readSize(0),
          _File(new QFile(QString(aFilePath.c_str()))),
          _pData(new char[getAmountOfChannels() * sizeof(typeOutSample) *
          getSuperframeLength() * getFrameRangLength() * getSamplesPerRang()]),
          _lastLength(0)
    {

        if(!_File->open(QIODevice::ReadOnly))
            throw "file is not accessable!!!";

        _sampleScale = 1 << ((sizeof(typeOutSample) * 8)-(sizeof(typeInSample)*8));

        _waveFormat = _waveFractalFormatData.getWaveformat();

        _wavedescrdata = _waveFractalFormatData.getWavedescrdata();

        _sampleAmount = (_wavedescrdata.chunkHead.size / _waveFormat.blockAlign) * getSamplesPerRang();

        _offsetWaveData = _waveFractalFormatData.getDataPos();

        _offsetFractalMap = _waveFractalFormatData.getFractalMapPos();

        _amountSuperFrames = (_waveFractalFormatData.getFracmap()._chunkHead.size/sizeof(int64));

        _ptrFractalMap.reset(new int64[ _amountSuperFrames + 1]);

        int64 lFractalMapPos = _waveFractalFormatData.getFractalMapPos() - 1;

        _File->seek(lFractalMapPos);

        _File->read((char *)_ptrFractalMap.get(), _waveFractalFormatData.getFracmap()._chunkHead.size);

        _ptrFractalMap.get()[_amountSuperFrames] = _waveFractalFormatData.getFracdescrindeces()._chunkHead.size;

        _offsetFractalIndeces = _waveFractalFormatData.getFractalDescrIndecesPos();

        this->_superFrameStep = getSuperframeLength() * getFrameRangLength() * getSamplesPerRang();

        _superFrameLength = getSuperframeLength() * getFrameRangLength();

        _superFramePreListeningBytesLength = getSuperframeLength() * getFrameRangLength() * (_waveFormat.bitsPerSample >> 3);

        _superFrameByteSize = getSuperframeLength() * getFrameRangLength() * getSamplesPerRang() * getAmountOfChannels() * sizeof(typeInSample)* (sizeof(typeOutSample)/sizeof(typeInSample));

        _blockAlign = getAmountOfChannels() * sizeof(typeOutSample);

        _readSize = _superFrameByteSize;

    }

    virtual ~ROADoverWAVE()
    {
        _File->close();

        delete []_pData;
    }

    virtual int readData(char *data, int maxlen)
    {
        if(_lastLength == 0)
        {
            ROADdecoder::ROADover::Result result = ROADover::decode();

            if(result != ROADdecoder::ROADover::DONE)
                return 0;
            else
                _lastLength = _superFrameByteSize;
        }

        int lReadLength = maxlen;

        if(_lastLength > maxlen)
        {
            memcpy(data, _pData + (_superFrameByteSize - _lastLength), maxlen);

            _lastLength -= maxlen;
        }
        else
        {
            memcpy(data, _pData + (_superFrameByteSize - _lastLength), _lastLength);

            lReadLength = _lastLength;

            _lastLength = 0;
        }

        return lReadLength;
    }

    virtual int getSampleAmount()
    {
        return this->_sampleAmount;
    }

    virtual void setPosition(int position)
    {
        UNUSED(position);
    }

    virtual void decode()
    {

    }

protected:

    virtual int readROADdata(unsigned char* aData)
    {
        int result = 0;

        int64 lNumSuperFrame = this->_nextPos / this->_superFrameStep;

        if(lNumSuperFrame >= _amountSuperFrames)
            return -1;

        int64 lFractalIndecesShift = _ptrFractalMap.get()[lNumSuperFrame];

        int64 lFractalIndecesShiftNext = _ptrFractalMap.get()[++lNumSuperFrame];

        result = lFractalIndecesShiftNext - lFractalIndecesShift;

        int64 lFractalIndexPos = _offsetFractalIndeces + lFractalIndecesShift;

        _File->seek(lFractalIndexPos);

        if(_File->atEnd())
            return -1;

        _File->read((char *)aData, result);

        return result;
    }

    virtual int readPreListening(unsigned char* aData)
    {
        long lNumSuperFrame = this->_nextPos / this->_superFrameStep;

        long lPreListeningPosition = _offsetWaveData + lNumSuperFrame * _superFrameLength * sizeof(typeInSample);

        _File->seek(lPreListeningPosition);

        _File->read((char *)aData, _superFramePreListeningBytesLength);

        this->_nextPos = lNumSuperFrame * this->_superFrameStep;

        return _superFramePreListeningBytesLength;
    }

    virtual void convertByteArrayIntoDoubleArray(const unsigned char* aByteData, unsigned int aLengthByteArray, double* aDoubleData)
    {
        typeInSample laver;

        int llaverLength = sizeof(typeInSample);

        unsigned int lcount = aLengthByteArray/llaverLength;

        for(unsigned int lIndex = 0;
            lIndex < lcount;
            ++lIndex)
        {
            memcpy(&laver, aByteData, llaverLength);

            aByteData+=llaverLength;

            aDoubleData[lIndex] = laver * _sampleScale;
        }

    }

    virtual void writeRawData(ROADdecoder::ROADover::IRawDataBuffer* aRawDataBuffer)
    {
        unsigned int lchannels = aRawDataBuffer->getCount();

        unsigned int lLength = aRawDataBuffer->getLength();

        typeOutSample lvalue;

        double lDoubleValue;

        const int valueLength = sizeof(typeOutSample);

        char *lData = _pData;

        for(unsigned int lPosition = 0;
            lPosition < lLength;
            ++lPosition)
        {

            for(unsigned int lIndex = 0;
                lIndex < lchannels;
                ++lIndex)
            {

                auto lptrIDoubleDataBuffer = aRawDataBuffer->getIDoubleDataContainer(lIndex);

                double * lptrData = lptrIDoubleDataBuffer->getData();

                lDoubleValue = lptrData[lPosition];

                if(lDoubleValue > max)
                {
                    lDoubleValue = max;
                }
                else if(lDoubleValue < min)
                {
                    lDoubleValue = min;
                }

                lvalue = lDoubleValue;

                memcpy(lData, &lvalue, valueLength);

                lData+=valueLength;

            }
        }

        long lNumSuperFrame = this->_nextPos / this->_superFrameStep;

        this->_nextPos = ++lNumSuperFrame * this->_superFrameStep;
    }

    virtual bool lockResource()
    {
        bool result = true;

        return result;
    }

    virtual bool unlockResource()
    {
        bool result = true;

        return result;
    }

private:

    typedef T typeInSample;

    typedef O typeOutSample;

    double max;

    double min;

    int _sampleScale;

    WaveFractalFormatData _waveFractalFormatData;

    __WAVEFORMAT _waveFormat;

    __WAVEDESCRDATA _wavedescrdata;

    int _sampleAmount;

    int _pos;

    int _nextPos;

    int _offsetWaveData;

    int _offsetFractalMap;

    int _amountSuperFrames;

    int _offsetFractalIndeces;

    int _superFrameStep;

    int _superFrameLength;

    int _superFramePreListeningBytesLength;

    int _superFrameByteSize;

    int _readSize;

    int _blockAlign;

    std::unique_ptr<QFile> _File;

    std::unique_ptr<int64> _ptrFractalMap;

    char *_pData;

    int _lastLength;
};

#endif // ROADOVERWAVE_H
