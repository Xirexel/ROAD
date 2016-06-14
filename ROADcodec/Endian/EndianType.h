#ifndef __Endian__EndianType_h__
#define __Endian__EndianType_h__

#include "platformdependencies.h"

namespace Endian
{
    enum class EndianType: PlatformDependencies::ROADInt32
	{
        BIG=0, LITTLE=0x80
	};
}

#endif
