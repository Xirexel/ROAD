#ifndef __Endian__BigEndianConvertor_h__
#define __Endian__BigEndianConvertor_h__

#include "IEndianConvertor.h"

namespace Endian
{
	class BigEndianConvertor: public Endian::IEndianConvertor
    {
        public: ROADUInt32 convertToUINT32(PtrROADByte  aData);

        public: ROADInt32 convertToINT32(PtrROADByte  aData);

        public: ROADUInt16 convertToUINT16(PtrROADByte  aData);

        public: ROADInt16 convertToINT16(PtrROADByte  aData);

        public: ROADInt32 convertToBytes(ROADUInt32 aValue, PtrROADByte  aData);

        public: ROADInt32 convertToBytes(ROADInt32 aValue, PtrROADByte  aData);

        public: ROADInt32 convertToBytes(ROADUInt16 aValue, PtrROADByte  aData);

        public: ROADInt32 convertToBytes(ROADInt16 aValue, PtrROADByte  aData);
	};
}

#endif
