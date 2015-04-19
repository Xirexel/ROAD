#ifndef __ROADdecoder__ROAD__IROADFractalBuilder_h__
#define __ROADdecoder__ROAD__IROADFractalBuilder_h__

#include <memory>

#include "platformdependencies.h"
#include "IFractalFirstOrderItemContainer.h"

namespace ROADdecoder
{
	namespace ROAD
	{

    using namespace PlatformDependencies;
        class IROADFractalFirstOrderBuilder
		{
            public: virtual void build(PtrROADVoid aData) = 0;

            public: virtual std::shared_ptr<ROADdecoder::ROAD::IFractalFirstOrderItemContainer> getContainer() = 0;

            public: virtual ~IROADFractalFirstOrderBuilder(){}
		};
	}
}

#endif
