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

        public: ROADUInt32 convertToUINT32(PtrROADByte aData);

        public: ROADInt32 convertToINT32(PtrROADByte aData);

        public: ROADUInt16 convertToUINT16(PtrROADByte aData);

        public: ROADInt16 convertToINT16(PtrROADByte aData);

        public: ROADUInt8 convertToUINT8(PtrROADByte Data);

        public: ROADInt8 convertToINT8(PtrROADByte Data);

        public: ROADInt32 convertToBytes(ROADUInt32 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADInt32 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADUInt16 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADInt16 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADUInt8 aValue, PtrROADByte  aData);

        public: ROADInt32 convertToBytes(ROADInt8 aValue, PtrROADByte  aData);
	};
}

#endif
