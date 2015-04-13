#ifndef __Endian__IEndianConvertor_h__
#define __Endian__IEndianConvertor_h__

#include "platformdependencies.h"


namespace Endian
{
    using namespace PlatformDependencies;

	class IEndianConvertor
	{
        public: virtual ROADUInt64 convertToType(ROADUInt64, PtrROADByte aData) = 0;

        public: virtual ROADInt64 convertToType(ROADInt64, PtrROADByte aData) = 0;

        public: virtual ROADUInt32 convertToType(ROADUInt32, PtrROADByte aData) = 0;

        public: virtual ROADInt32 convertToType(ROADInt32, PtrROADByte aData) = 0;

        public: virtual ROADUInt16 convertToType(ROADUInt16, PtrROADByte aData) = 0;

        public: virtual ROADInt16 convertToType(ROADInt16, PtrROADByte Data) = 0;

        public: virtual ROADUInt8 convertToType(ROADUInt8, PtrROADByte Data) = 0;

        public: virtual ROADInt8 convertToType(ROADInt8, PtrROADByte Data) = 0;

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
