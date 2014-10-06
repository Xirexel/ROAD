#ifndef __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsFactory_h__
#define __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsFactory_h__

#include <vector>
#include <memory>

#include "roadovercoder_global.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IROADoverEncodingOptions;
		class ROADoverEncodingOptionsFactory;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
        class ROADOVERCODERSHARED_EXPORT ROADoverEncodingOptionsFactory
		{
            public: static std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> getIROADoverEncodingOptions(unsigned int aType);
            public: static std::vector<unsigned int> getSupportedFormats();
		};
	}
}

#endif
