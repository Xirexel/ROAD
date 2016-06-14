#ifndef __ROADcoder__ROADoverCoder__ROADFormatMode_h__
#define __ROADcoder__ROADoverCoder__ROADFormatMode_h__

#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADoverCoder
    {
        enum class ROADFormatMode:PlatformDependencies::ROADByte
		{
            UNKNOWN = 0xFF, EXPEREMENTAL = 0x00, FIRSTVERSION = 0x01
		};
	}
}

#endif
