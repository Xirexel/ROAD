#ifndef __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsFactory_h__
#define __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsFactory_h__

#include <vector>
#include <memory>

#include "roadovercoder_global.h"
#include "memorydefine.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
        class IROADoverEncodingOptions;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;
        class ROADOVERCODERSHARED_EXPORT ROADoverEncodingOptionsFactory
		{
            public: static Unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> getIROADoverEncodingOptions(ROADUInt32 aType);
            public: static std::vector<ROADUInt32> getSupportedFormats();
		};
	}
}

#endif
