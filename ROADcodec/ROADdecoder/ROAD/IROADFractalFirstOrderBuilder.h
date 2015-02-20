#ifndef __ROADdecoder__ROAD__IROADFractalBuilder_h__
#define __ROADdecoder__ROAD__IROADFractalBuilder_h__

#include "platformdependencies.h"

namespace ROADdecoder
{
	namespace ROAD
	{
        class IFractalFirstOrderItemContainer;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{

    using namespace PlatformDependencies;
        class IROADFractalFirstOrderBuilder
		{

            public: virtual void build(PtrROADReal aData, ROADdecoder::ROAD::IFractalFirstOrderItemContainer* aFractalItemContainer) = 0;

            public: virtual ~IROADFractalFirstOrderBuilder(){}
		};
	}
}

#endif
