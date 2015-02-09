#ifndef __Endian__BigEndianConvertor_h__
#define __Endian__BigEndianConvertor_h__

#include "IEndianConvertor.h"

namespace Endian
{
	class BigEndianConvertor: public Endian::IEndianConvertor
    {
        public: ROADUInt32 convertToUINT32(ROADPtrByte  aData);

        public: ROADInt32 convertToINT32(ROADPtrByte  aData);

        public: ROADUInt16 convertToUINT16(ROADPtrByte  aData);

        public: ROADInt16 convertToINT16(ROADPtrByte  aData);

        public: ROADInt32 convertToBytes(ROADUInt32 aValue, ROADPtrByte  aData);

        public: ROADInt32 convertToBytes(ROADInt32 aValue, ROADPtrByte  aData);

        public: ROADInt32 convertToBytes(ROADUInt16 aValue, ROADPtrByte  aData);

        public: ROADInt32 convertToBytes(ROADInt16 aValue, ROADPtrByte  aData);
	};
}

#endif
