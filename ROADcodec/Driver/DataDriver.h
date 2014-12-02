#include <string>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

#ifndef __Driver__DataDriver_h__
#define __Driver__DataDriver_h__

#include "IDataReadDriver.h"
#include "../Endian/EndianType.h"

//#include "driver_global.h"

namespace Driver
{
	class IDataReadDriver;
	class DataDriver;
}
namespace Endian
{
	// enum EndianType;
}

namespace Driver
{
    class DataDriver
    {

        private: DataDriver() = delete;

        private: virtual ~DataDriver() = delete;

        public: static unique_ptr<Driver::IDataReadDriver> getIDataReadDriver(unique_ptr<unsigned char> &aData, unsigned int aLength, Endian::EndianType aEndianType);
	};
}

#endif
