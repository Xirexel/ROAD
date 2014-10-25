#ifndef WAVEFRACTALWRITER_H
#define WAVEFRACTALWRITER_H


#include <QDataStream>
#include <QByteArray>


#include "awavefractalwriter.h"

template<typename T>
class WaveFractalWriter: public AWaveFractalWriter
{
public:
    explicit WaveFractalWriter(QString filePath,
                               __WAVEDESCR aWaveDesc,
                               __WAVEFORMAT awaveformat,
                               __WAVEDESCRDATA aWaveData,
                               __FRACDESCR aFractalFormat)
        : AWaveFractalWriter(filePath + ".road.wav",
                             aWaveDesc,
                             awaveformat,
                             aWaveData,
                             aFractalFormat),
          _byteSize(sizeof(typeSample))

    {
        _byteArray.reserve(aFractalFormat._format._frameRangeLength * _byteSize);
    }

    virtual ~WaveFractalWriter()
    {

    }

    virtual unsigned int convertDoubleArrayToByteArray(double* aDoubleData, unsigned int aLength, char* aByteData)
    {
        QDataStream lQDataStream(&_byteArray, QIODevice::WriteOnly);

        lQDataStream.setByteOrder(QDataStream::LittleEndian);

        typeSample ltypeValue;

        for(decltype(aLength)lindex = 0;
            lindex < aLength;
            ++lindex)
        {
            ltypeValue = aDoubleData[lindex];

            lQDataStream << ltypeValue;
        }

        memcpy(aByteData, _byteArray.data(), aLength * _byteSize);

        return aLength * _byteSize;
    }

    virtual void writePrelistening(double* aData, unsigned int aLength)
    {
        typeSample ltypeValue;

        _averLength += aLength * sizeof(typeSample);

        while(aLength > 0)
        {
            ltypeValue = *aData;

            ++aData;

            _dataStream << ltypeValue;

            --aLength;
        }

    }

//    virtual void writeData(FractalEncoding::IFractalDataContainer* aFirstChannel, FractalEncoding::IFractalDataContainer* aSecondChannel)
//    {

//        // Writing average vertion into the WAVE container

//        FractalEncoding::IDoubleDataContainer* lptrExtendedAver = aFirstChannel->getExtendAver();

//        auto count = lptrExtendedAver->getCount();

//        double *lPtrData = lptrExtendedAver->getData();



//        typeSample temp;

//        while(count > 0)
//        {
//            temp = *lPtrData;

//            ++lPtrData;

//            _dataStream << temp;

//            --count;
//        }



//        // Writing the start position of the super frame

//        qint64 lpos = _tempFractalDataFile.pos();

//        _fractalMapStream << lpos;


//        // Writing Indeces of first channel

//        FractalEncoding::IUCharDataContainer* lptrFirstChannelIndeces = aFirstChannel->getIndex();

//        _tempFractalDataFile.write((char *)(lptrFirstChannelIndeces->getData()), lptrFirstChannelIndeces->getCount());


//        // Writing Indeces of second channel

//        FractalEncoding::IUCharDataContainer* lptrSecondChannelIndeces = aSecondChannel->getIndex();

//        _tempFractalDataFile.write((char *)(lptrSecondChannelIndeces->getData()), lptrSecondChannelIndeces->getCount());



//        // Writing aver value of second channel

//        FractalEncoding::IDoubleDataContainer* lptrSecondChannelAver =  aSecondChannel->getAver();

//        count = lptrSecondChannelAver->getCount();

//        lPtrData = lptrSecondChannelAver->getData();

//        while(count > 0)
//        {
//            temp = *lPtrData;

//            ++lPtrData;

//            _fractalDataStream << temp;

//            --count;
//        }









//        // Writing domain Indeces


//        FractalEncoding::IUCharDataContainer* lptrFirstChannelDomainIndeces = aFirstChannel->getDomain();

//        _tempFractalDataFile.write((char *)(lptrFirstChannelDomainIndeces->getData()), lptrFirstChannelDomainIndeces->getCount());



//        FractalEncoding::IUCharDataContainer* lptrSecondChannelDomainIndeces = aSecondChannel->getDomain();

//        _tempFractalDataFile.write((char *)(lptrSecondChannelDomainIndeces->getData()), lptrSecondChannelDomainIndeces->getCount());





//        // Writing scales

//        FractalEncoding::IUCharDataContainer* lptrFirstChannelScales = aFirstChannel->getScale();

//        _tempFractalDataFile.write((char *)(lptrFirstChannelScales->getData()), lptrFirstChannelScales->getCount());



//        FractalEncoding::IUCharDataContainer* lptrSecondChannelScales = aSecondChannel->getScale();

//        _tempFractalDataFile.write((char *)(lptrSecondChannelScales->getData()), lptrSecondChannelScales->getCount());


//    }

private:

    typedef T typeSample;

    QByteArray _byteArray;

    quint32 _byteSize;
};

#endif // WAVEFRACTALWRITER_H
