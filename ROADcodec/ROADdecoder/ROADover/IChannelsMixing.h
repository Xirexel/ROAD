#ifndef __ROADdecoder__ROADover__IChannelsMixing_h__
#define __ROADdecoder__ROADover__IChannelsMixing_h__

#include "RawDataBuffer.h"

namespace ROADdecoder
{
	namespace ROADover
	{
        template<typename ROADDecodedSampleType>
		class IChannelsMixing
		{
            public: virtual void compute(ROADdecoder::ROADover::RawDataBuffer<ROADDecodedSampleType>* aBuffer) = 0;

            public: virtual ~IChannelsMixing(){}
		};
	}
}

#endif
