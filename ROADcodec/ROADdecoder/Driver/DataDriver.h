#ifndef __ROADdecoder__Driver__DataDriver_h__
#define __ROADdecoder__Driver__DataDriver_h__

#include <memory>

#include "EndianType.h"
#include "IDataReadDriver.h"
#include "DataContainer.h"


namespace ROADdecoder
{
	namespace Driver
	{
    using namespace PlatformDependencies;
		class DataDriver
        {

        private: DataDriver() = delete;

        private: virtual ~DataDriver() = delete;

        public: static std::unique_ptr<Driver::IDataReadDriver> getIDataReadDriver(ROADdecoder::Driver::DataContainer *aData, ROADUInt32 aLength, Endian::EndianType aEndianType);

        public: static std::unique_ptr<Driver::IDataReadDriver> getIDataReadDriver(std::shared_ptr<ROADByte> &aData, ROADUInt32 aLength, Endian::EndianType aEndianType);
		};
	}
}

#endif
