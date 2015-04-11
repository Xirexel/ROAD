#ifndef WAVEFRACTALWRITER_H
#define WAVEFRACTALWRITER_H


#include <QDataStream>
#include <QByteArray>


#include <iostream>


#include "awavefractalwriter.h"
#include "DataDriver.h"
#include "crc.h"


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

    virtual PlatformDependencies::ROADUInt32 writePrelistening(double* aDoubleData, unsigned int aLength)
    {
        using namespace PlatformDependencies;

        typeSample ltypeValue;

        _averLength += aLength * sizeof(typeSample);

        std::shared_ptr<ROADByte> lData(new ROADByte[aLength * sizeof(typeSample)]);

        auto lIDataWriteDriver =
                ROADcoder::Driver::DataDriver::getIDataWriteDriver(lData,
                                                                   aLength * sizeof(typeSample),
                                                                   Endian::LITTLE);


//        std::cerr << "Length: " << aLength << std::endl;

        while(aLength > 0)
        {
            ltypeValue = *aDoubleData;

     //       if(lItemIndex >= lptrFractalItemContainer->getFractalAverItemCount() - 3)
//            {
//                std::cerr << ltypeValue << std::endl;

//            }

            ++aDoubleData;

            lIDataWriteDriver->operator <<(ltypeValue);

            _dataStream << ltypeValue;

            --aLength;
        }

//        _dataStream.writeBytes((char*)lData.get(), (int)lIDataWriteDriver->getLength());

        return CRCSupport::CRC::CRC32(lData.get(), (ROADUInt32)lIDataWriteDriver->getLength());

    }


private:

    typedef T typeSample;

    QByteArray _byteArray;

    quint32 _byteSize;
};

#endif // WAVEFRACTALWRITER_H
