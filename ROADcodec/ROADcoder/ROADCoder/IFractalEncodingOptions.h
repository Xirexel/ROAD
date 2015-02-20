#ifndef __ROADcoder__ROADCoder__IFractalEncodingOptions_h__
#define __ROADcoder__ROADCoder__IFractalEncodingOptions_h__

#include "platformdependencies.h"

namespace ROADcoder
{
    namespace ROADCoder
    {
    using namespace PlatformDependencies;
		class IFractalEncodingOptions
        {
            public: virtual ROADUInt32 getFrameSampleLength() = 0;

            public: virtual ROADUInt32 getRangTopSampleLength() = 0;

            public: virtual ROADUInt32 getAmountRangLevels() = 0;

            public: virtual ROADUInt32 getDomainShift() = 0;

            public: virtual ROADReal getSilenceThreshold() = 0;

            public: virtual ROADReal getRangThreshold() = 0;

            public: virtual ~IFractalEncodingOptions(){}
		};
	}
}

#endif
