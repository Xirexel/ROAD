#ifndef __ROADdecoder__ROAD__IFractalItemContainer_h__
#define __ROADdecoder__ROAD__IFractalItemContainer_h__

#include "platformdependencies.h"

namespace ROADdecoder
{
	namespace ROAD
	{
        class IFractalFirstOrderItem;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{

        using namespace PlatformDependencies;

        class IFractalFirstOrderItemContainer
		{
            public: virtual void resetIFractalFirstOrderItemCount() = 0;

            public: virtual ROADdecoder::ROAD::IFractalFirstOrderItem* getIFractalFirstOrderItem(ROADUInt32 aIndex) = 0;

            public: virtual ROADUInt32 getIFractalFirstOrderItemCount() = 0;

            public: virtual ~IFractalFirstOrderItemContainer(){}
		};
	}
}

#endif
