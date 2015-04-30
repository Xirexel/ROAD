#ifndef DECODEDSAMPLETYPETORAWDATASAMPLETYPE_H
#define DECODEDSAMPLETYPETORAWDATASAMPLETYPE_H

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

            public: virtual void writeRawData(ROADcoder::Driver::IDataWriteDriver* aIDataWriteDriver, ROADReal *aData, ROADUInt32 ldoubleBufferLength)
            {
                while (ldoubleBufferLength > 0)
                {
                    _tempSampleType = (ROADInt32)*aData++;

                    _sampleType = (SampleType)_tempSampleType;

                    aIDataWriteDriver->operator <<(_sampleType);

                    --ldoubleBufferLength;
                }

            }

            public: virtual ~DecodedSampleTypeToRawDataSampleType(){}
        };
    }
}

#endif // DECODEDSAMPLETYPETORAWDATASAMPLETYPE_H
