#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __Endian__BigEndianConvertor_h__
#define __Endian__BigEndianConvertor_h__

#include "IEndianConvertor.h"

namespace Endian
{
	class IEndianConvertor;
	class BigEndianConvertor;
}

namespace Endian
{
	class BigEndianConvertor: public Endian::IEndianConvertor
	{

		public: unsigned int convertToUINT32(unsigned char* aData);

		public: int convertToINT32(unsigned char* aData);

		public: unsigned short convertToUINT16(unsigned char* aData);

		public: short convertToINT16(unsigned char* aData);
	};
}

#endif
