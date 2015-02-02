#ifndef __Endian__IEndianConvertor_h__
#define __Endian__IEndianConvertor_h__

namespace Endian
{
	class IEndianConvertor
	{

		public: virtual unsigned int convertToUINT32(unsigned char* aData) = 0;

		public: virtual int convertToINT32(unsigned char* aData) = 0;

		public: virtual unsigned short convertToUINT16(unsigned char* aData) = 0;

		public: virtual short convertToINT16(unsigned char* aData) = 0;

        public: virtual int convertToBytes(unsigned int aValue, unsigned char* aData) = 0;

        public: virtual int convertToBytes(int aValue, unsigned char* aData) = 0;

        public: virtual int convertToBytes(unsigned short aValue, unsigned char* aData) = 0;

        public: virtual int convertToBytes(short aValue, unsigned char* aData) = 0;
	};
}

#endif
