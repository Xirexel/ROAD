#ifndef BYTESTOROADINT32_H
#define BYTESTOROADINT32_H

#include "IBytesToROADInt32.h"
#include "EndianConvertorFactory.h"

namespace ROADdecoder
{
    namespace ROADover
    {
        template<typename T>
        class BytesToROADInt32: public IBytesToROADInt32
        {
            private: T* PtrOriginalBytesType;

            private: std::unique_ptr<Endian::IEndianConvertor> _convertor;

            public: BytesToROADInt32(Endian::EndianType aEndianType):
                _convertor(Endian::EndianConvertorFactory.getInstance().getIEndianConvertor(aEndianType))
            {

            }

            public: virtual ~BytesToROADInt32(){}

            public: virtual void setAtBeginning(PtrROADByte aData)
            {

                PtrOriginalBytesType = (T*)aData;
            }

            public: virtual ROADInt32 getROADInt32()
            {
                _convertor->convertToINT8();

                return *PtrOriginalBytesType++;
            }
        };
    }
}

#endif // BYTESTOROADINT32_H
