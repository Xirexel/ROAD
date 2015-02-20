#ifndef __ROADcoder__ROADoverCoder__IROADoverManager_h__
#define __ROADcoder__ROADoverCoder__IROADoverManager_h__


#include <tuple>


#include "Result.h"
#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;

		class IROADoverManager
        {
			public: virtual ROADcoder::ROADoverCoder::Result encode() = 0;

            public: virtual ROADUInt32 getRangSampleLength() = 0;

            public: virtual ROADUInt32 getBitsPerSample() = 0;

            public: virtual std::tuple<PtrROADByte, ROADUInt32> getFractalFormatRawData() = 0;

            public: virtual ~IROADoverManager(){}
		};
	}
}

#endif
