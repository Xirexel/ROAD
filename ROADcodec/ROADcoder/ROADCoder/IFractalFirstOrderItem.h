#ifndef __ROADcoder__ROADCoder__IFractalItem_h__
#define __ROADcoder__ROADCoder__IFractalItem_h__

#include "platformdependencies.h"

namespace ROADcoder
{
    namespace ROADCoder
    {
    using namespace PlatformDependencies;
        class IFractalFirstOrderItem
		{

            public: virtual void setAver(ROADReal aValue) = 0;

            public: virtual void setLength(ROADUInt32 aValue) = 0;

            public: virtual void setIsInversDirection(ROADBool aValue) = 0;

            public: virtual void setDomainOffset(ROADUInt32 aValue) = 0;

            public: virtual void setScale(ROADReal aValue) = 0;

            public: virtual void setPosition(ROADUInt32 aValue) = 0;

            public: virtual ~IFractalFirstOrderItem(){}
		};
	}
}

#endif
