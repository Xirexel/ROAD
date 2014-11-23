#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __Endian__BigEndianConvertor_h__
#define __Endian__BigEndianConvertor_h__

#include "IConvertor.h"

namespace Endian
{
	class IConvertor;
	class BigEndianConvertor;
}

namespace Endian
{
	class BigEndianConvertor: public Endian::IConvertor
	{        
		public: unsigned int convertToUINT32(unsigned char* aData);

		public: int convertToINT32(unsigned char* aData);

		public: unsigned short convertToUINT16(unsigned char* aData);

		public: short convertToINT16(unsigned char* aData);

    private:
        template<typename T>
        struct BigEndian
        { 
            std::size_t size;

            BigEndian()
                :size(sizeof(T))
            {

            }

        };

        typedef BigEndian<unsigned int> ui32;

        typedef BigEndian<int> i32;

        typedef BigEndian<unsigned short> ui16;

        typedef BigEndian<short> i16;
    };
}

#endif
