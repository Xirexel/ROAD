#ifndef DECODEDSAMPLETYPETORAWDATASAMPLETYPE_H
#define DECODEDSAMPLETYPETORAWDATASAMPLETYPE_H

#include <iostream>


#include "IDecodedSampleTypeToRawDataSampleType.h"

namespace ROADcoder
{
    namespace ROADoverCoder
    {
        template<typename RawDataSampleType>
        class DecodedSampleTypeToRawDataSampleType:public IDecodedSampleTypeToRawDataSampleType
        {
            private: typedef RawDataSampleType SampleType;

            private: SampleType _sampleType;

            private: ROADInt32 _tempSampleType;

            public: virtual void writeRawData(
                    ROADcoder::Driver::IDataWriteDriver& aIDataWriteDriver,
                    ROADReal *aData,
                    ROADUInt32 ldoubleBufferLength)
            {
//                std::cerr << "ldoubleBufferLength: " << ldoubleBufferLength << std::endl;

                std::cerr << "getLength(): " << aIDataWriteDriver.getLength() << std::endl;

//                std::cerr << "getPosition(): " << aIDataWriteDriver->getPosition() << std::endl;

                while (ldoubleBufferLength > 0)
                {
                    _tempSampleType = (ROADInt32)*aData++;

                    _sampleType = (SampleType)_tempSampleType;

                    aIDataWriteDriver << _sampleType;

                    --ldoubleBufferLength;
                }

//                std::cerr << "writeRawDataEnd" << std::endl;
            }

            public: virtual ~DecodedSampleTypeToRawDataSampleType(){}
        };
    }
}

#endif // DECODEDSAMPLETYPETORAWDATASAMPLETYPE_H
