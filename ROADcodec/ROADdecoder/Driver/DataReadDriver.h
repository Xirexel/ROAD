#include <string>
#include <vector>
#include <exception>
#include <memory>

#ifndef __ROADdecoder__Driver__DataReadDriver_h__
#define __ROADdecoder__Driver__DataReadDriver_h__

#include "IEndianConvertor.h"
#include "IDataReadDriver.h"

namespace Endian
{
	class IEndianConvertor;
}
namespace ROADdecoder
{
	namespace Driver
	{
		class IDataReadDriver;
		class DataReadDriver;
	}
}

namespace ROADdecoder
{
	namespace Driver
	{
		class DataReadDriver: public ROADdecoder::Driver::IDataReadDriver
		{
            private: std::unique_ptr<unsigned char> _data;
			private: unsigned int _length;
			private: unsigned int _position;
            private: std::unique_ptr<Endian::IEndianConvertor> _convertor;

            public: DataReadDriver(std::unique_ptr<unsigned char> &aData, unsigned int aLength, std::unique_ptr<Endian::IEndianConvertor> &aConvertor);

            public: IDataReadDriver &operator >>(unsigned int &aValue);

            public: virtual ~DataReadDriver();
		};
	}
}

#endif
