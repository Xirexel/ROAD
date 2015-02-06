#ifndef __ROADcoder__ROADoverCoder__IROADoverManager_h__
#define __ROADcoder__ROADoverCoder__IROADoverManager_h__


#include <tuple>


#include "Result.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
        class ROADover;
		class IROADoverManager;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IROADoverManager
        {
			public: virtual ROADcoder::ROADoverCoder::Result encode() = 0;

            public: virtual unsigned int getRangSampleLength() = 0;

            public: virtual unsigned int getBitsPerSample() = 0;

            public: virtual std::tuple<unsigned char *, unsigned int> getFractalFormatRawData() = 0;

            public: virtual ~IROADoverManager(){}
		};
	}
}

#endif
