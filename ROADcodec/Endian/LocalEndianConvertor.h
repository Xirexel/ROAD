#ifndef __Endian__LocalEndianConvertor_h__
#define __Endian__LocalEndianConvertor_h__

#include "IEndianConvertor.h"

namespace Endian
{
	class IEndianConvertor;
	class LocalEndianConvertor;
}

namespace Endian
{
	class LocalEndianConvertor: public Endian::IEndianConvertor
    {

        public: ROADUInt64 convertToUINT64(PtrROADByte aData);

        public: ROADInt64 convertToINT64(PtrROADByte aData);

        public: ROADUInt32 convertToUINT32(PtrROADByte aData);

        public: ROADInt32 convertToINT32(PtrROADByte aData);

        public: ROADUInt16 convertToUINT16(PtrROADByte aData);

        public: ROADInt16 convertToINT16(PtrROADByte aData);

        public: ROADUInt8 convertToUINT8(PtrROADByte Data);

        public: ROADInt8 convertToINT8(PtrROADByte Data);

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
