#ifndef __ROADdecoder__ROAD__IROADFractalBuilder_h__
#define __ROADdecoder__ROAD__IROADFractalBuilder_h__

#include <memory>

#include "platformdependencies.h"
#include "IFractalFirstOrderItemContainer.h"
#include "ROADFrameDataContainer.h"

namespace ROADdecoder
{
	namespace ROAD
	{

    using namespace PlatformDependencies;
        class IROADFractalFirstOrderBuilder
		{
            public: virtual void build(PtrROADVoid aData, IROADFrameDataContainer* aPtrIROADFrameDataContainer) = 0;

            public: virtual ~IROADFractalFirstOrderBuilder(){}
		};
	}
}

#endif
