#ifndef __ROADcoder__ROADoverCoder__IDoubleDataContainer_h__
#define __ROADcoder__ROADoverCoder__IDoubleDataContainer_h__

#include "platformdependencies.h"


namespace ROADcoder
{
	namespace ROADoverCoder
	{
        using namespace PlatformDependencies;

		class IDoubleDataContainer
		{

            public: virtual PtrROADReal getData() = 0;

            public: virtual ROADUInt32 getLength() = 0;

            public: virtual ~IDoubleDataContainer(){}

		};
	}
}

#endif
