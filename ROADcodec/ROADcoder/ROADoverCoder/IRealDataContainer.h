#ifndef __ROADcoder__ROADoverCoder__IRealDataContainer_h__
#define __ROADcoder__ROADoverCoder__IRealDataContainer_h__

#include "platformdependencies.h"


namespace ROADcoder
{
	namespace ROADoverCoder
	{
        using namespace PlatformDependencies;

        class IRealDataContainer
		{

            public: virtual PtrROADReal getData() = 0;

            public: virtual ROADUInt32 getLength() = 0;

            public: virtual ~IRealDataContainer(){}

		};
	}
}

#endif
