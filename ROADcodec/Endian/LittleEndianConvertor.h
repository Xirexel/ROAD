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

		public: unsigned int convertToUINT32(unsigned char* aData);

		public: int convertToINT32(unsigned char* aData);

		public: unsigned short convertToUINT16(unsigned char* aData);

		public: short convertToINT16(unsigned char* aData);

        public: int convertToBytes(unsigned int aValue, unsigned char* aData);

        public: int convertToBytes(int aValue, unsigned char* aData);

        public: int convertToBytes(unsigned short aValue, unsigned char* aData);

        public: int convertToBytes(short aValue, unsigned char* aData);
	};
}

#endif
