#ifndef __ROADcoder__Driver__DataWriteDriver_h__
#define __ROADcoder__Driver__DataWriteDriver_h__

#include <memory>


#include "IEndianConvertor.h"
#include "IDataWriteDriver.h"

namespace Endian
{
	class IEndianConvertor;
}
namespace ROADcoder
{
	namespace Driver
	{
		class IDataWriteDriver;
		class DataWriteDriver;
	}
}

namespace ROADcoder
{
	namespace Driver
	{
		class DataWriteDriver: public ROADcoder::Driver::IDataWriteDriver
		{
            private: std::unique_ptr<unsigned char> _data;
			private: unsigned int _length;
			private: unsigned int _position;
            private: std::unique_ptr<Endian::IEndianConvertor> _convertor;

            public: virtual ~DataWriteDriver();

            public: DataWriteDriver(std::unique_ptr<unsigned char> &aData, unsigned int aLength, std::unique_ptr<Endian::IEndianConvertor> &aConvertor);

            public: virtual IDataWriteDriver &operator << (unsigned int &aValue);

            public: virtual IDataWriteDriver &operator <<(int &aValue);

            public: virtual IDataWriteDriver &operator <<(unsigned short &aValue);

            public: virtual IDataWriteDriver &operator <<(short &aValue);
		};
	}
}

#endif
