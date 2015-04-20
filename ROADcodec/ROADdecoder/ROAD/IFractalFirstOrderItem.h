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
            public: virtual void setAverage(ROADUInt32 aPosition,
                                             ROADUInt32 aLength,
                                             PtrROADVoid aPtrDataSample) = 0;

            public: virtual void setRangTransform(ROADBool aIsInversDirection,
                                                  ROADUInt32 aDomainOffset,
                                                  ROADInt8 aScale) = 0;

            public: virtual ~IFractalFirstOrderItem(){}
		};
	}
}

#endif
