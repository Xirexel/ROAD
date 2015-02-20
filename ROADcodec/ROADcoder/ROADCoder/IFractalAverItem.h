#ifndef __ROADcoder__ROADCoder__IFractalAverItem_h__
#define __ROADcoder__ROADCoder__IFractalAverItem_h__

#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
    using namespace PlatformDependencies;

		class IFractalAverItem
		{

            public: virtual void setAver(ROADReal aValue) = 0;

            public: virtual void setLength(ROADUInt32 aValue) = 0;

            public: virtual void setIndex(ROADUInt32 aValue) = 0;

            public: virtual ~IFractalAverItem(){}
		};
	}
}

#endif
