#ifndef __ROADcoder__ROADCoder__IROADFractalAnalyzerFactory_h__
#define __ROADcoder__ROADCoder__IROADFractalAnalyzerFactory_h__


#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
    using namespace PlatformDependencies;
		class IROADFractalAnalyzerFactory
		{
            public: virtual ~IROADFractalAnalyzerFactory(){}

            public: virtual ROADUInt32 getOrder() = 0;
		};
	}
}

#endif
