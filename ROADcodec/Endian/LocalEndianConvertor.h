#include <string>
#include <vector>
#include <exception>
using namespace std;

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

		public: unsigned int convertToUINT32(unsigned char* aData);

		public: int convertToINT32(unsigned char* aData);

		public: unsigned short convertToUINT16(unsigned char* aData);

		public: short convertToINT16(unsigned char* aData);
	};
}

#endif
