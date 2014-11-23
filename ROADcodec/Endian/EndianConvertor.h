#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __Endian__EndianConvertor_h__
#define __Endian__EndianConvertor_h__

// #include "Endian/IConvertor.h"
#include "endian_global.h"

namespace Endian
{
	class IConvertor;
	class EndianConvertor;        
}

namespace Endian
{
    class ENDIANSHARED_EXPORT EndianConvertor
	{
		private: Endian::IConvertor* _convertor;

		private: EndianConvertor();

        public: static Endian::EndianConvertor& getInstance();

		public: unsigned int convertToUINT32(unsigned char* aData);

		public: int convertToINT32(unsigned char* aData);

		public: unsigned short convertToUINT16(unsigned char* aData);

		public: short convertToINT16(unsigned char* aData);

        public: ~EndianConvertor();
	};
}

#endif
