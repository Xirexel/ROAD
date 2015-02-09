#ifndef __Endian__IEndianConvertor_h__
#define __Endian__IEndianConvertor_h__

#include "platformdependencies.h"


namespace Endian
{
    using namespace PlatformDependencies;

	class IEndianConvertor
	{
        public: virtual ROADUInt32 convertToUINT32(ROADPtrByte  aData) = 0;

        public: virtual ROADInt32 convertToINT32(ROADPtrByte  aData) = 0;

        public: virtual ROADUInt16 convertToUINT16(ROADPtrByte  aData) = 0;

        public: virtual ROADInt16 convertToINT16(ROADPtrByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADUInt32 aValue, ROADPtrByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADInt32 aValue, ROADPtrByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADUInt16 aValue, ROADPtrByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADInt16 aValue, ROADPtrByte  aData) = 0;
	};
}

#endif
