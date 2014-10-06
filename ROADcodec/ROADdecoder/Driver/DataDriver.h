#include <string>
#include <vector>
#include <exception>
#include <memory>

#ifndef __ROADdecoder__Driver__DataDriver_h__
#define __ROADdecoder__Driver__DataDriver_h__

#include "EndianType.h"
#include "IDataReadDriver.h"

namespace Endian
{
	// enum EndianType;
}
namespace ROADdecoder
{
	namespace Driver
	{
		class IDataReadDriver;
		class DataDriver;
	}
}

namespace ROADdecoder
{
	namespace Driver
	{
		class DataDriver
        {

        private: DataDriver() = delete;

        private: virtual ~DataDriver() = delete;

        public: static std::unique_ptr<Driver::IDataReadDriver> getIDataReadDriver(std::unique_ptr<unsigned char> &aData, unsigned int aLength, Endian::EndianType aEndianType);
		};
	}
}

#endif
