#ifndef __Endian__LittleEndianConvertor_h__
#define __Endian__LittleEndianConvertor_h__

#include "IEndianConvertor.h"

namespace Endian
{
	class IEndianConvertor;
	class LittleEndianConvertor;
}

namespace Endian
{
	class LittleEndianConvertor: public Endian::IEndianConvertor
    {

        public: ROADUInt64 convertToType(ROADUInt64, PtrROADByte aData);

        public: ROADInt64 convertToType(ROADInt64, PtrROADByte aData);

        public: ROADUInt32 convertToType(ROADUInt32, PtrROADByte aData);

        public: ROADInt32 convertToType(ROADInt32, PtrROADByte aData);

        public: ROADUInt16 convertToType(ROADUInt16, PtrROADByte aData);

        public: ROADInt16 convertToType(ROADInt16, PtrROADByte aData);

        public: ROADUInt8 convertToType(ROADUInt8, PtrROADByte Data);

        public: ROADInt8 convertToType(ROADInt8, PtrROADByte Data);

        public: ROADInt32 convertToBytes(ROADUInt64 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADInt64 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADUInt32 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADInt32 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADUInt16 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADInt16 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADUInt8 aValue, PtrROADByte  aData);

        public: ROADInt32 convertToBytes(ROADInt8 aValue, PtrROADByte  aData);
	};
}

#endif
