#ifndef ROADOVERWAVE_H
#define ROADOVERWAVE_H

#include <fstream>
#include <limits>


#include "ROADover.h"
#include "../ROADPlayerGUI/IReader.h"
#include "wavefractal_parser.h"
#include "IRawDataBuffer.h"

typedef long long int64;


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
          _pData(new char[getAmountOfChannels() * sizeof(typeOutSample) *
          getSuperframeLength() * getFrameRangLength() * getSamplesPerRang()]),
          _lastLength(0)
    {

        _pFile = fopen (aFilePath.c_str() , "r");

        _sampleScale = 1 << ((sizeof(typeOutSample) * 8)-(sizeof(typeInSample)*8));

    }

    ~ROADoverWAVE()
    {
        fclose(_pFile);

        delete []_pData;
    }

    virtual int readData(char *data, int maxlen)
    {
        ROADdecoder::ROADover::Result result = ROADover::decode();



    }

    virtual int getSampleAmount()
    {

    }

    virtual void setPosition(int position)
    {

    }

    virtual void decode()
    {

    }

protected:

    virtual unsigned int readROADdata(unsigned char* aData)
    {
        unsigned int result = 0;

        return result;
    }

    virtual unsigned int readPreListening(unsigned char* aData)
    {
        unsigned int result = 0;

        return result;
    }

    virtual void convertByteArrayIntoDoubleArray(const char* aByteData, unsigned int aLengthByteArray, double* aDoubleData)
    {

    }

    virtual void writeRawData(ROADdecoder::ROADover::IRawDataBuffer* aRawDataBuffer)
    {

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

    int _offsetFractalIndeces;

    int _superFrameStep;

    int _superFrameLength;

    int _superFrameByteSize;

    int _readSize;

    int _blockAlign;

    FILE *_pFile;

    char *_pData;

    int _lastLength;



//    ROADoverWAVE(ROADdecoder::ROADover::IROADoverDecodingOptions *aOptions,
//                 WaveFractalFormatData waveFractalFormatData,
//                 std::string filePath)
//        : ROADover::ROADover(aOptions),
//          max(std::numeric_limits<typeOutSample>::max()),
//          min(std::numeric_limits<typeOutSample>::min()),
//          _sampleScale(1),
//          _waveFractalFormatData(waveFractalFormatData),
//          _pos(0),
//          _nextPos(0),
//          _readSize(0),
//          _pData(new char[aOptions.getAmountOfChannels() * sizeof(typeOutSample) *
//        aOptions.getSuperframeLength() * aOptions.getFrameRangLength() * aOptions.getSamplesPerRang()]),
//          _lastLength(0)
//    {
//        _pFile = fopen (filePath.c_str() , "r");


//        _sampleScale = 1 << ((sizeof(typeOutSample) * 8)-(sizeof(typeInSample)*8));

//        _waveFormat = _waveFractalFormatData.getWaveformat();

//        _wavedescrdata = _waveFractalFormatData.getWavedescrdata();

//        _sampleAmount = (_wavedescrdata.chunkHead.size / _waveFormat.blockAlign) * _options.getSamplesPerRang();

//        _offsetWaveData = _waveFractalFormatData.getDataPos();

//        _offsetFractalMap = _waveFractalFormatData.getFractalMapPos();

//        _offsetFractalIndeces = _waveFractalFormatData.getFractalDescrIndecesPos();

//        this->_superFrameStep = _options.getSuperframeLength() * _options.getFrameRangLength() * _options.getSamplesPerRang();

//        _superFrameLength = _options.getSuperframeLength() * _options.getFrameRangLength();

//        _superFrameByteSize = _options.getSuperframeLength() * _options.getFrameRangLength() * _options.getSamplesPerRang() * _options.getAmountOfChannels() * sizeof(typeInSample)* (sizeof(typeOutSample)/sizeof(typeInSample));

//        _blockAlign = _options.getAmountOfChannels() * sizeof(typeOutSample);

//        _readSize = _superFrameByteSize;

//        _lastLength = 0;

//    }

//    virtual ~ROADoverWAVE()
//    {
//        fclose(_pFile);

//        delete []_pData;
//    }

//    virtual int readData(char *data, int maxlen)
//    {
//        if(_lastLength == 0)
//            decode();

//        int lReadLength = maxlen;

//        if(_lastLength > maxlen)
//        {
//            memcpy(data, _pData + (_superFrameByteSize - _lastLength), maxlen);

//            _lastLength -= maxlen;
//        }
//        else
//        {
//            memcpy(data, _pData + (_superFrameByteSize - _lastLength), _lastLength);

//            lReadLength = _lastLength;

//            _lastLength = 0;
//        }


//        return lReadLength;
//    }

//    virtual int getSampleAmount()
//    {
//        return _sampleAmount;
//    }

//    virtual void setPosition(int position)
//    {

//    }

//    virtual void decode()
//    {
//        doOneDecoding();

//        _lastLength = _superFrameByteSize;
//    }



//public: virtual unsigned int readROADdata(char* aData)
//    {
//        int64 lNumSuperFrame = this->_nextPos / this->_superFrameStep;

//        fseek(_pFile, _offsetFractalMap - 1 + lNumSuperFrame * sizeof(int64), SEEK_SET);

////        char g[4];

////        fread(g, 1, 4,_pFile);

////        unsigned int h;

////        fread(&h, sizeof(h), 1,_pFile);

//        if(feof(_pFile))
//            return -1;

//        int64 lFractalIndecesShift = 0;

//        int64 lFractalIndecesShiftNext = 0;

//        int64 lFractalIndecesLength = 0;

//        fread(&lFractalIndecesShift, sizeof(lFractalIndecesShift), 1,_pFile);

//        fread(&lFractalIndecesShiftNext, sizeof(lFractalIndecesShiftNext), 1,_pFile);


//        lFractalIndecesLength = lFractalIndecesShiftNext - lFractalIndecesShift;

//        fseek(_pFile, _offsetFractalIndeces + lFractalIndecesShift, SEEK_SET);



////        fread(g, 1, 4,_pFile);

////        fread(&h, sizeof(h), 1,_pFile);


//        fread(aData, 1, lFractalIndecesLength,_pFile);

////        qDebug(QString("lNumSuperFrame: %1").arg(lNumSuperFrame).toStdString().c_str());

//        return lFractalIndecesLength;
//    }

//public: virtual unsigned int readAver(double* aData)
//    {
//        int result = 0;

//        long lNumSuperFrame = this->_nextPos / this->_superFrameStep;

//        fseek(_pFile, _offsetWaveData + lNumSuperFrame * _superFrameLength * sizeof(typeInSample), SEEK_SET);

//        typeInSample laver;

//        int lLength = _superFrameLength;

//        while(lLength > 0)
//        {
//            fread(&laver, 1, sizeof(laver),_pFile);

//            *aData = laver * _sampleScale;

//            ++aData;

//            --lLength;
//        }

//        this->_nextPos = lNumSuperFrame * this->_superFrameStep;

//        result = _superFrameLength;

//        if(feof(_pFile))
//            result = -1;


//        return result;
//    }

//public: virtual unsigned int convertByteArrayIntoDoubleArray(const char* aByteData, unsigned int aLengthByteArray, double* aDoubleData)
//    {
//        typeInSample laver;

//        int llaverLength = sizeof(typeInSample);

//        unsigned int lcount = aLengthByteArray/llaverLength;

//        for(unsigned int lIndex = 0;
//            lIndex < lcount;
//            ++lIndex)
//        {
//            memcpy(&laver, aByteData, llaverLength);

//            aByteData+=llaverLength;

//            aDoubleData[lIndex] = laver * _sampleScale;
//        }

//        return lcount;
//    }

//public: virtual void writeRawData(ROADdecoder::ROADover::IRawDataBuffer* aRawDataBuffer)
//    {
//        unsigned int lchannels = aRawDataBuffer->getCount();

//        unsigned int lLength = aRawDataBuffer->getLength();

//        typeOutSample lvalue;

//        double lDoubleValue;

//        int valueLength = sizeof(lvalue);

//        char *lData = _pData;

//        for(unsigned int lPosition = 0;
//            lPosition < lLength;
//            ++lPosition)
//        {

//            for(unsigned int lIndex = 0;
//                lIndex < lchannels;
//                ++lIndex)
//            {

//                ROADdecoding::IDoubleDataBuffer* lptrIDoubleDataBuffer = aRawDataBuffer->getIDoubleDataBuffer(lIndex);

//                double * lptrData = lptrIDoubleDataBuffer->getData();

//                lDoubleValue = lptrData[lPosition];

//                if(lDoubleValue > max)
//                {
//                    lDoubleValue = max;
//                }
//                else if(lDoubleValue < min)
//                {
//                    lDoubleValue = min;
//                }

//                lvalue = lDoubleValue;

//                memcpy(lData, &lvalue, valueLength);

//                lData+=valueLength;

//            }
//        }

//        long lNumSuperFrame = this->_nextPos / this->_superFrameStep;

//        this->_nextPos = ++lNumSuperFrame * this->_superFrameStep;
//    }




};

#endif // ROADOVERWAVE_H
