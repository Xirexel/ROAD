#ifndef __ROADdecoder__ROADover__ROADoverDecodingOptionsFactory_h__
#define __ROADdecoder__ROADover__ROADoverDecodingOptionsFactory_h__

#include <memory>
#include <list>


#include "../Driver/IDataReadDriver.h"
#include "ROADRawMetaDataContainer.h"

#include "roadover_global.h"


namespace ROADdecoder
{
	namespace ROADover
	{
		class IROADoverDecodingOptions;
		class ROADoverDecodingOptionsFactory;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
        class ROADOVERSHARED_EXPORT ROADoverDecodingOptionsFactory
		{
        public: static IROADoverDecodingOptions* getIROADoverDecodingOptions(std::unique_ptr<Driver::IDataReadDriver> &aPtrIDataReadDriver);

        public: static IROADoverDecodingOptions* getIROADoverDecodingOptions(std::list<ROADRawMetaDataContainer> aPtrIDataReadDriver);
		};
	}
}

#endif
