#ifndef __ROADdecoder__ROADover__IDoubleDataContainer_h__
#define __ROADdecoder__ROADover__IDoubleDataContainer_h__

#include "platformdependencies.h"

namespace ROADdecoder
{
	namespace ROADover
	{

    using namespace PlatformDependencies;
		class IDoubleDataContainer
		{

            public: virtual PtrROADReal getData() = 0;

            public: virtual ROADUInt32 getCount() = 0;

            public: virtual void setCount(ROADUInt32 aValue) = 0;

            public: virtual ~IDoubleDataContainer(){}
		};
	}
}

#endif
