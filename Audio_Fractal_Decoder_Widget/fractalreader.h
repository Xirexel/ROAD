#ifndef FRACTALREADER_H
#define FRACTALREADER_H

#include <string>
#include <memory>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>

#include "IReader.h"
#include "wavefractal_parser.h"
#include "IRawDataReader.h"
#include "IRawDataWriter.h"
#include "Audio_Fractal_Decoder.h"
//#include "LogPrintOut.h"
#include "decodingthread.h"



template<typename T, typename O>
class FractalReader : public IReader, public FractalDecoding::IRawDataReader, public FractalDecoding::IRawDataWriter
{

    friend class DecodingThread;

public:
    explicit FractalReader(QDataStream *dataStream,
                           WaveFractalFormatData waveFractalFormatData,
                           FractalDecoding::FractalDecodingOptions aOptions,
                           QObject *parent = 0)
        :IReader(dataStream, parent),
          max(std::numeric_limits<typeOutSample>::max()),
          min(std::numeric_limits<typeOutSample>::min()),
          _sampleScale(1),
          _waveFractalFormatData(waveFractalFormatData),
          _pos(0),
          _nextPos(0),
          _readSize(0),
          _decoder(FractalDecoding::Audio_Fractal_Decoder(this, this, aOptions)),
          _options(aOptions),
          _decodingThread(new DecodingThread(this))
    {


        _sampleScale = 1 << ((sizeof(typeOutSample) * 8)-(sizeof(typeInSample)*8));

        _waveFormat = _waveFractalFormatData.getWaveformat();

        _wavedescrdata = _waveFractalFormatData.getWavedescrdata();

        _sampleAmount = (_wavedescrdata.chunkHead.size / _waveFormat.blockAlign) * _options.getSamplesPerRang();

        _offsetWaveData = _waveFractalFormatData.getDataPos();

        _offsetFractalMap = std::get<1>(_waveFractalFormatData.getFractalMapPos());

        _offsetFractalIndeces = std::get<1>(_waveFractalFormatData.getFractalDescrIndecesPos());

        this->_superFrameStep = _options.getSuperFrameLength() * _options.getFrameLength() * _options.getSamplesPerRang();

        _superFrameLength = _options.getSuperFrameLength() * _options.getFrameLength();

        _superFrameByteSize = _options.getSuperFrameLength() * _options.getFrameLength() * _options.getSamplesPerRang() * _options.getAmountOfChannels() * sizeof(typeInSample)* (sizeof(typeOutSample)/sizeof(typeInSample));

        _blockAlign = _options.getAmountOfChannels() * sizeof(typeInSample) * (sizeof(typeOutSample)/sizeof(typeInSample));


        _firstByteArray.resize(_superFrameByteSize);

        _secondByteArray.resize(_superFrameByteSize);

        _ptrWriteByteArray = &_firstByteArray;

        _ptrReadByteArray = &_secondByteArray;

        _decodingThread->start();

        _decoder.doDecoding();

        _readSize = _superFrameByteSize;

    }

    virtual ~FractalReader()
    {
        _decodingThread->requestInterruption();

        _executeDecodingThread.wakeAll();

        _finishMutex.lock();

        _finishDecodingThread.wait(&_finishMutex);

        _finishMutex.unlock();
    }

    virtual void decode()
    {


        _decodeMutex.lock();

        forever
        {


            _executeDecodingThread.wait(&_decodeMutex);

            _playMutex.lock();

            _playMutex.unlock();

            _startDecodingThread.wakeAll();

           if ( QThread::currentThread()->isInterruptionRequested() )
           {
               _decodeMutex.unlock();

               break;
           }

           _decoder.doDecoding();
        }

        _finishDecodingThread.wakeAll();
    }

    virtual FractalDecoding::ReadResult readData(FractalDecoding::IFractalDataContainer* aFirstChannel, FractalDecoding::IFractalDataContainer* aSecondChannel)
    {
        FractalDecoding::ReadResult result = FractalDecoding::ERROR;

        qint64 lNumSuperFrame = this->_nextPos / this->_superFrameStep;

        _dataStream->device()->seek(_offsetFractalMap + lNumSuperFrame * sizeof(qint64));

        if(_dataStream->atEnd())
            return FractalDecoding::FINISHFILE;

        qint64 lFractalIndecesShift = 0;

        *_dataStream >> lFractalIndecesShift;

        _dataStream->device()->seek(_offsetFractalIndeces + lFractalIndecesShift);



        unsigned int* lptrLengths = aFirstChannel->getLengths()->getData();

        unsigned char* lptrIndeces = aFirstChannel->getIndeces()->getData();


        auto lLength = _superFrameLength * _options.getSamplesPerRang();


        quint32 countIndeces = 0;

        quint8 luctemp = 0;

        while(lLength > 0)
        {
            if(_dataStream->atEnd())
                break;

            *_dataStream >> luctemp;

            lptrIndeces[countIndeces] = luctemp;

            unsigned int lrangeLength;

            if((luctemp & 128) == 128)
            {
                lrangeLength = (1 << (luctemp & 127)) * _options.getSamplesPerRang();
            }
            else
            {
                lrangeLength = (1 << (luctemp >> 5)) * _options.getSamplesPerRang();
            }

            lptrLengths[countIndeces] = lrangeLength;

            lLength -= lrangeLength;

            ++countIndeces;
        }

        aFirstChannel->getLengths()->setCount(countIndeces);

        aFirstChannel->getIndeces()->setCount(countIndeces);







        lptrLengths = aSecondChannel->getLengths()->getData();

        lptrIndeces = aSecondChannel->getIndeces()->getData();


        lLength = _superFrameLength * _options.getSamplesPerRang();


        countIndeces = 0;

        luctemp = 0;

        while(lLength > 0)
        {
            *_dataStream >> luctemp;

            lptrIndeces[countIndeces] = luctemp;

            decltype(lLength) lrangeLength;

            if((luctemp & 128) == 128)
            {
                lrangeLength = (1 << (luctemp & 127)) * _options.getSamplesPerRang();
            }
            else
            {
                lrangeLength = (1 << (luctemp >> 5)) * _options.getSamplesPerRang();
            }

            lptrLengths[countIndeces] = lrangeLength;

            lLength -= lrangeLength;

            ++countIndeces;
        }


        aSecondChannel->getLengths()->setCount(countIndeces);

        aSecondChannel->getIndeces()->setCount(countIndeces);




        typeInSample laver;

        double *lptrAver = aSecondChannel->getAver()->getData();

        countIndeces = aSecondChannel->getIndeces()->getCount();

        aSecondChannel->getAver()->setCount(countIndeces);

        while(countIndeces > 0)
        {
            *_dataStream >> laver;

            *lptrAver = laver * _sampleScale;

            ++lptrAver;

            --countIndeces;
        }





        unsigned char *lptrDomain = aFirstChannel->getDomain()->getData();

        countIndeces = aFirstChannel->getIndeces()->getCount();

        lptrIndeces = aFirstChannel->getIndeces()->getData();

        quint8 ldomainIndex;

        quint8 lindex;

        unsigned int countDomainIndeces = 0;

        while(countIndeces > 0)
        {
            lindex = *lptrIndeces;


            if((lindex & 128) == 0)
            {

                *_dataStream >> ldomainIndex;

                *lptrDomain = ldomainIndex;

                ++lptrDomain;

                ++countDomainIndeces;
            }

            --countIndeces;

            ++lptrIndeces;
        }


        aFirstChannel->getDomain()->setCount(countDomainIndeces);







        lptrDomain = aSecondChannel->getDomain()->getData();

        countIndeces = aSecondChannel->getIndeces()->getCount();

        lptrIndeces = aSecondChannel->getIndeces()->getData();

        countDomainIndeces = 0;

        while(countIndeces > 0)
        {
            lindex = *lptrIndeces;


            if((lindex & 128) == 0)
            {

                *_dataStream >> ldomainIndex;

                *lptrDomain = ldomainIndex;

                ++lptrDomain;

                ++countDomainIndeces;
            }

            --countIndeces;

            ++lptrIndeces;
        }


        aSecondChannel->getDomain()->setCount(countDomainIndeces);







        unsigned char *lptrScales = aFirstChannel->getScales()->getData();

        countIndeces = aFirstChannel->getIndeces()->getCount();

        lptrIndeces = aFirstChannel->getIndeces()->getData();

        quint8 lscale;

        unsigned int countScales = 0;

        while(countIndeces > 0)
        {
            lindex = *lptrIndeces;


            if((lindex & 128) == 0)
            {

                *_dataStream >> lscale;

                *lptrScales = lscale;

                ++lptrScales;

                ++countScales;
            }

            --countIndeces;

            ++lptrIndeces;
        }


        aFirstChannel->getScales()->setCount(countScales);





        lptrScales = aSecondChannel->getScales()->getData();

        countIndeces = aSecondChannel->getIndeces()->getCount();

        lptrIndeces = aSecondChannel->getIndeces()->getData();

        countScales = 0;

        while(countIndeces > 0)
        {
            lindex = *lptrIndeces;


            if((lindex & 128) == 0)
            {

                *_dataStream >> lscale;

                *lptrScales = lscale;

                ++lptrScales;

                ++countScales;
            }

            --countIndeces;

            ++lptrIndeces;
        }


        aSecondChannel->getScales()->setCount(countScales);














        _dataStream->device()->seek(_offsetWaveData + lNumSuperFrame * _superFrameLength * sizeof(typeInSample));

        lptrLengths = aFirstChannel->getLengths()->getData();

        lptrAver = aFirstChannel->getAver()->getData();

        countIndeces = aFirstChannel->getIndeces()->getCount();

        aFirstChannel->getAver()->setCount(countIndeces);

        decltype(aFirstChannel->getIndeces()->getCount()) count = 0;

        unsigned int lrabgeLength = 0;

        while(count < countIndeces)
        {
            *_dataStream >> laver;

            *lptrAver = laver * _sampleScale;

            ++lptrAver;

            lrabgeLength = *lptrLengths;

            lrabgeLength /= _options.getSamplesPerRang();

            --lrabgeLength;

            lrabgeLength *= sizeof(typeInSample);

            lptrLengths++;


            _dataStream->skipRawData(lrabgeLength);


            ++count;
        }





        this->_nextPos = lNumSuperFrame * this->_superFrameStep;

        result = FractalDecoding::DONE;

        if(_dataStream->atEnd())
            result = FractalDecoding::FINISHFILE;


        return result;
    }

    virtual void writeData(double* aFirstChannel, double* aSecongChannel, unsigned int aLength)
    {
        QDataStream lQDataStreamWrier(_ptrWriteByteArray, QIODevice::WriteOnly);

        lQDataStreamWrier.setByteOrder(QDataStream::LittleEndian);

        typeOutSample lsample;

        double lTemp = 0.0;

        while(aLength > 0)
        {
            lTemp = *aFirstChannel;

            if(lTemp > max)
            {
                lTemp = max;
            }
            else if(lTemp < min)
            {
                    lTemp = min;
            }


            lsample = lTemp;

            ++aFirstChannel;

            lQDataStreamWrier << lsample;


            lTemp = *aSecongChannel;

            if(lTemp > max)
            {
                lTemp = max;
            }
            else if(lTemp < min)
            {
                    lTemp = min;
            }


            lsample = lTemp;

            ++aSecongChannel;

            lQDataStreamWrier << lsample;

            --aLength;
        }

//        _readSize = 0;

    }

    qint64 readData(char *data, qint64 maxlen)
    {
        qint64 result = 0;

        if( _pos >= _sampleAmount)
        {
            emit finish();

            return result;
        }

        do
        {

            qint64 lrestLength = (_superFrameByteSize - _readSize);


            if(lrestLength > maxlen)
            {
                memcpy(data, _ptrReadByteArray->constData() + _readSize, maxlen);

                _readSize += maxlen;

                result = maxlen;

                _pos += (result / _blockAlign);
            }
            else
            {
                _decodeMutex.lock();

                memcpy(data, _ptrReadByteArray->constData() + _readSize, lrestLength);

                _readSize = 0;

                result = lrestLength;

                swapArrays();

                _decodeMutex.unlock();

                if( _pos < _sampleAmount)
                {

                    _playMutex.lock();

                    _executeDecodingThread.wakeAll();

                    _startDecodingThread.wait(&_playMutex);

                    _playMutex.unlock();
                }
            }

        }
        while(false);



        emit pos(_pos);

        return result;
    }

    qint64 getSampleAmount()
    {
        return _sampleAmount;
    }

    void setPosition(qint64 position)
    {
        _decodeMutex.lock();

        _readSize = 0;

        swapArrays();

        this->_nextPos = position;

        _decoder.doDecoding();

        swapArrays();

        _decoder.doDecoding();

        _decodeMutex.unlock();
    }

private:

    typedef T typeInSample;

    typedef O typeOutSample;

    double max;

    double min;

    qint32 _sampleScale;

    WaveFractalFormatData _waveFractalFormatData;

    __WAVEFORMAT _waveFormat;

    __WAVEDESCRDATA _wavedescrdata;

    qint64 _sampleAmount;

    qint64 _pos;

    qint64 _nextPos;

    qint64 _offsetWaveData;

    qint64 _offsetFractalMap;

    qint64 _offsetFractalIndeces;

    qint64 _superFrameStep;

    qint64 _superFrameLength;

    qint64 _superFrameByteSize;

    qint64 _readSize;

    qint64 _blockAlign;

    FractalDecoding::Audio_Fractal_Decoder _decoder;

    FractalDecoding::FractalDecodingOptions _options;

    QByteArray _firstByteArray;

    QByteArray _secondByteArray;

    QByteArray *_ptrWriteByteArray;

    QByteArray *_ptrReadByteArray;

    QMutex _finishMutex;

    QMutex _decodeMutex;

    QMutex _playMutex;

    QWaitCondition _finishDecodingThread;

    QWaitCondition _executeDecodingThread;

    QWaitCondition _startDecodingThread;


    DecodingThread *_decodingThread;


    void swapArrays()
    {
        QByteArray *lptrTemp = _ptrWriteByteArray;

        _ptrWriteByteArray = _ptrReadByteArray;

        _ptrReadByteArray = lptrTemp;

        this->_pos = this->_nextPos;

        this->_nextPos += this->_superFrameStep;
    }



};



#endif // FRACTALREADER_H
