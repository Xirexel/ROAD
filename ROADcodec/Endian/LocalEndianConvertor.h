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

        public: ROADUInt32 convertToUINT32(PtrROADByte aData);

        public: ROADInt32 convertToINT32(PtrROADByte aData);

        public: ROADUInt16 convertToUINT16(PtrROADByte aData);

        public: ROADInt16 convertToINT16(PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADUInt32 aValue,unsigned char *aData);

        public: ROADInt32 convertToBytes(ROADInt32 aValue,PtrROADByte aData);

        public: ROADInt32 convertToBytes(ROADUInt16 aValue,unsigned char *aData);

        public: ROADInt32 convertToBytes(ROADInt16 aValue,PtrROADByte aData);
	};
}

#endif
