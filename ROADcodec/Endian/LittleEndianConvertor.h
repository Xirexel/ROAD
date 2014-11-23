#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __Endian__LittleEndianConvertor_h__
#define __Endian__LittleEndianConvertor_h__

#include "IConvertor.h"

namespace Endian
{
	class IConvertor;
	class LittleEndianConvertor;
}

namespace Endian
{
	class LittleEndianConvertor: public Endian::IConvertor
	{

		public: unsigned int convertToUINT32(unsigned char* aData);

		public: int convertToINT32(unsigned char* aData);

		public: unsigned short convertToUINT16(unsigned char* aData);

		public: short convertToINT16(unsigned char* aData);

    private:
        template<typename T>
        struct LittleEndian
        {

            const std::size_t size;

            LittleEndian()
                :size(sizeof(T))
            {

            }

            T operator()(unsigned char* aData)
            {
                aData+=size - 1;

                T t = T();
                for (unsigned i = 0; i < size; i++)
                    t |= T(*aData--) << (i << 3);
                return t;
            }
        };

        LittleEndian<unsigned int> _ui32;

        LittleEndian<int> _i32;

        LittleEndian<unsigned short> _ui16;

        LittleEndian<short> _i16;
	};
}

#endif
