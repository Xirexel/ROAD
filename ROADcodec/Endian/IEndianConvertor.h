#ifndef __Endian__IEndianConvertor_h__
#define __Endian__IEndianConvertor_h__

#include "platformdependencies.h"


namespace Endian
{
    using namespace PlatformDependencies;

	class IEndianConvertor
	{
        public: virtual ROADUInt64 convertToUINT64(PtrROADByte  aData) = 0;

        public: virtual ROADInt64 convertToINT64(PtrROADByte aData) = 0;

        public: virtual ROADUInt32 convertToUINT32(PtrROADByte  aData) = 0;

        public: virtual ROADInt32 convertToINT32(PtrROADByte aData) = 0;

        public: virtual ROADUInt16 convertToUINT16(PtrROADByte aData) = 0;

        public: virtual ROADInt16 convertToINT16(PtrROADByte Data) = 0;

        public: virtual ROADUInt8 convertToUINT8(PtrROADByte Data) = 0;

        public: virtual ROADInt8 convertToINT8(PtrROADByte Data) = 0;

        public: virtual ROADInt32 convertToBytes(ROADUInt64 aValue, PtrROADByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADInt64 aValue, PtrROADByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADUInt32 aValue, PtrROADByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADInt32 aValue, PtrROADByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADUInt16 aValue, PtrROADByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADInt16 aValue, PtrROADByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADUInt8 aValue, PtrROADByte  aData) = 0;

        public: virtual ROADInt32 convertToBytes(ROADInt8 aValue, PtrROADByte  aData) = 0;
	};
}

#endif
