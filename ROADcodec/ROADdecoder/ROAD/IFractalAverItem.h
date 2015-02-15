#ifndef __ROADdecoder__ROAD__IFractalAverItem_h__
#define __ROADdecoder__ROAD__IFractalAverItem_h__


#include "platformdependencies.h"



namespace ROADdecoder
{
	namespace ROAD
	{

    using namespace PlatformDependencies;

		class IFractalAverItem
		{
            public: virtual ROADReal getAver() = 0;

            public: virtual ROADUInt32 getLength() = 0;

            public: virtual ROADUInt32 getPosition() = 0;

            public: virtual ~IFractalAverItem(){}
		};
	}
}

#endif
