#ifndef __ROADdecoder__ROAD__IROADFractalBuilderFactory_h__
#define __ROADdecoder__ROAD__IROADFractalBuilderFactory_h__

#include "platformdependencies.h"

namespace ROADdecoder
{
	namespace ROAD
	{

    using namespace PlatformDependencies;

		class IROADFractalBuilderFactory
		{

            public: virtual ROADUInt32 getOrder() = 0;

            public: virtual ~IROADFractalBuilderFactory(){}
		};
	}
}

#endif
