#ifndef __ROADcoder__Driver__DataDriver_h__
#define __ROADcoder__Driver__DataDriver_h__

#include <memory>

#include "../../Endian/EndianType.h"
#include "IDataWriteDriver.h"


namespace ROADcoder
{
	namespace Driver
	{
		class IDataWriteDriver;
		class DataDriver;
	}
}

namespace ROADcoder
{
	namespace Driver
	{
		class DataDriver
		{
            using namespace PlatformDependencies;

            private: DataDriver() = delete;

            private: virtual ~DataDriver() = delete;

            public: static std::unique_ptr<ROADcoder::Driver::IDataWriteDriver> getIDataWriteDriver(std::unique_ptr<ROADByte> &aData, ROADUInt32 aLength, Endian::EndianType aEndianType);
		};
	}
}

#endif
