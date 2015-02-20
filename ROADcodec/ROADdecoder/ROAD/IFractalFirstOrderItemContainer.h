#ifndef __ROADdecoder__ROAD__IFractalItemContainer_h__
#define __ROADdecoder__ROAD__IFractalItemContainer_h__

#include "platformdependencies.h"

namespace ROADdecoder
{
	namespace ROAD
	{
        class IFractalFirstOrderItem;
        class IFractalAverItem;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{

    using namespace PlatformDependencies;
        class IFractalFirstOrderItemContainer
		{

            public: virtual ROADdecoder::ROAD::IFractalFirstOrderItem* getIFractalFirstOrderItem(ROADUInt32 aIndex) = 0;

            public: virtual ROADdecoder::ROAD::IFractalAverItem* getIFractalAverItem(ROADUInt32 aIndex) = 0;

            public: virtual ROADUInt32 getIFractalFirstOrderItemCount() = 0;

            public: virtual ROADUInt32 getIFractalAverItemCount() = 0;

            public: virtual ~IFractalFirstOrderItemContainer(){}
		};
	}
}

#endif
