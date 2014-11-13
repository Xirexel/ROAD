#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __Endian__IConvertor_h__
#define __Endian__IConvertor_h__

namespace Endian
{
	class IConvertor;
}

namespace Endian
{
	class IConvertor
	{

		public: virtual unsigned int convertToUINT32(unsigned char* aData) = 0;

		public: virtual int convertToINT32(unsigned char* aData) = 0;

		public: virtual unsigned short convertToUINT16(unsigned char* aData) = 0;

		public: virtual short convertToINT16(unsigned char* aData) = 0;
	};
}

#endif
