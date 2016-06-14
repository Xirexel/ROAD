#ifndef __ROADcoder__ROADoverCoder__Result_h__
#define __ROADcoder__ROADoverCoder__Result_h__

#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;

        enum Result: ROADInt32
		{
            DONE = 0, FINISHFILE = 1, ERROR = -1
		};
	}
}

#endif
