#include <string>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

#ifndef __Driver__DataReadDriver_h__
#define __Driver__DataReadDriver_h__

#include "../Endian/IEndianConvertor.h"
#include "IDataReadDriver.h"


namespace Driver
{
    class IDataReadDriver;
	class DataReadDriver;
}
namespace Endian
{
	class IEndianConvertor;
}

namespace Driver
{
    class DataReadDriver: public Driver::IDataReadDriver
	{
        private: unique_ptr<unsigned char> _data;
		private: unsigned int _length;
        private: unsigned int _position;
        private: unique_ptr<Endian::IEndianConvertor> _convertor;

        public: DataReadDriver(unique_ptr<unsigned char> &aData, unsigned int aLength, unique_ptr<Endian::IEndianConvertor> &aConvertor);

        public: virtual ~DataReadDriver();

        public: IDataReadDriver &operator >>(unsigned int &aValue);
	};
}

#endif
