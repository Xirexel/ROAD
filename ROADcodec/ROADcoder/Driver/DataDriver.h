#ifndef __ROADcoder__Driver__DataDriver_h__
#define __ROADcoder__Driver__DataDriver_h__

#include <memory>

#include "../../Endian/EndianType.h"
#include "IDataWriteDriver.h"
#include "memorydefine.h"


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
            private: DataDriver() = delete;

            private: virtual ~DataDriver() = delete;

            // get interface for writing data.
            public: static PlatformDependencies::Unique_ptr<IDataWriteDriver> getIDataWriteDriver(
                    SharedMassive_ptr<ROADByte> &aData,
                    Endian::EndianType aEndianType);
		};
	}
}

#endif
