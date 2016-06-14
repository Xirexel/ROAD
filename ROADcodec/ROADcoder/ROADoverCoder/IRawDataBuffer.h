#ifndef __ROADcoder__ROADoverCoder__IRawDataBuffer_h__
#define __ROADcoder__ROADoverCoder__IRawDataBuffer_h__


#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
        class IRealDataContainer;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;

		class IRawDataBuffer
		{

            public: virtual ROADcoder::ROADoverCoder::IRealDataContainer* getIRealDataContainer(ROADUInt32 aIndex) = 0;

            public: virtual ROADUInt32 getCount() = 0;

            public: virtual ~IRawDataBuffer(){}
		};
	}
}

#endif
