#ifndef __ROADdecoder__ROADover__IRawDataBuffer_h__
#define __ROADdecoder__ROADover__IRawDataBuffer_h__

#include "platformdependencies.h"
#include "ROADRawDataFormat.h"


namespace ROADdecoder
{
	namespace ROADover
	{
    using namespace PlatformDependencies;
		class IRawDataBuffer
		{

            public: virtual ROADdecoder::ROADover::ROADRawDataFormat getDecodedSampleTypeCode() = 0;

            public: virtual ROADUInt32 getCount() = 0;

            public: virtual ROADUInt32 getLength() = 0;

            public: virtual ~IRawDataBuffer(){}
		};
	}
}

#endif
