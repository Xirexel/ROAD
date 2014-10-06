#ifndef WAVEFRACTALWRITER_H
#define WAVEFRACTALWRITER_H


#include <QDataStream>
#include <QByteArray>


#include <iostream>


#include "awavefractalwriter.h"

template<typename T>
class WaveFractalWriter: public AWaveFractalWriter
{
public:
    explicit WaveFractalWriter(QString filePath,
                               __WAVEDESCR aWaveDesc,
                               __WAVEFORMAT awaveformat,
                               __WAVEDESCRDATA aWaveData)
        : AWaveFractalWriter(filePath + ".road.wav",
                             aWaveDesc,
                             awaveformat,
                             aWaveData),
          _byteSize(sizeof(typeSample))

    {

    }

    virtual ~WaveFractalWriter()
    {

    }

    virtual unsigned int convertDoubleArrayToByteArray(const double* aDoubleData, unsigned int aLength, unsigned char* aByteData)
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

    virtual void writePrelistening(double* aDoubleData, unsigned int aLength)
    {
        typeSample ltypeValue;

        _averLength += aLength * sizeof(typeSample);

//        std::cerr << "Length: " << aLength << std::endl;

        while(aLength > 0)
        {
            ltypeValue = *aDoubleData;

     //       if(lItemIndex >= lptrFractalItemContainer->getFractalAverItemCount() - 3)
//            {
//                std::cerr << ltypeValue << std::endl;

//            }

            ++aDoubleData;

            _dataStream << ltypeValue;

            --aLength;
        }

    }


private:

    typedef T typeSample;

    QByteArray _byteArray;

    quint32 _byteSize;
};

#endif // WAVEFRACTALWRITER_H
