#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__IChannelsMixing_h__
#define __ROADdecoder__ROADover__IChannelsMixing_h__

// #include "ROADdecoder/ROADover/IRawDataBuffer.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class IRawDataBuffer;
		class IChannelsMixing;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class IChannelsMixing
		{

			public: virtual void compute(ROADdecoder::ROADover::IRawDataBuffer* aBuffer) = 0;

            public: virtual ~IChannelsMixing(){}
		};
	}
}

#endif
