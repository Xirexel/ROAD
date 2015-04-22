#ifndef __ROADdecoder__ROAD__IFractalItem_h__
#define __ROADdecoder__ROAD__IFractalItem_h__

#include "platformdependencies.h"

namespace ROADdecoder
{
	namespace ROAD
	{

    using namespace PlatformDependencies;

        class IFractalFirstOrderItem
        {
            public: virtual ROADUInt32 getLength() = 0;

            public: virtual ROADBool isInversDirection() = 0;

            public: virtual ROADUInt32 getDomainOffset() = 0;

            public: virtual ROADUInt32 getPosition() = 0;

            public: virtual ~IFractalFirstOrderItem(){}
		};
	}
}

#endif
