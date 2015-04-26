#ifndef __ROADdecoder__ROADover__IROADoverManager_h__
#define __ROADdecoder__ROADover__IROADoverManager_h__

#include "Result.h"
#include "ROADRawDataFormat.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class IROADoverManager
		{
			public: virtual ROADdecoder::ROADover::Result decode() = 0;

            public: virtual ROADRawDataFormat getDecodedSampleTypeCode() = 0;

            public: virtual ~IROADoverManager(){}
		};
	}
}

#endif
