#ifndef BYTESTOROADINT32_H
#define BYTESTOROADINT32_H

#include <memory>


#include "IBytesToROADInt32.h"
#include "DataDriver.h"
#include "EndianType.h"

namespace ROADdecoder
{
    namespace ROADover
    {
        template<typename T>
        class BytesToROADInt32: public IBytesToROADInt32
        {
            private: T _element;

            private: std::unique_ptr<ROADdecoder::Driver::IDataReadDriver> _IDataReadDriver;

            private: Endian::EndianType _EndianType;

            public: BytesToROADInt32(Endian::EndianType aEndianType):
                _EndianType(aEndianType){}

            public: virtual ~BytesToROADInt32(){}

            public: virtual void convert(std::shared_ptr<ROADByte> aData,
                                                ROADUInt64 aLength,
                                                PtrROADInt32 aROADInt32Data,
                                                ROADUInt64 aFrameSampleLength)
            {
                auto lIDataReadDriver = ROADdecoder::Driver::DataDriver::getIDataReadDriver(aData,
                                                                  aLength,
                                                                  _EndianType);

                for(decltype(aFrameSampleLength) lindex = 0;
                    lindex < aFrameSampleLength;
                    ++lindex)
                {

                    lIDataReadDriver->operator >>(_element);

                    *aROADInt32Data = _element;

                    ++aROADInt32Data;
                }


            }
        };
    }
}

#endif // BYTESTOROADINT32_H
