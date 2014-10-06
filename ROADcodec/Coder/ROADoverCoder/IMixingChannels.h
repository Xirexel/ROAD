#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IMixingChannels_h__
#define __IMixingChannels_h__

// #include "IRawDataBuffer.h"

namespace ROADoverEncoding
{
	class IRawDataBuffer;
	class IMixingChannels;
}

namespace ROADoverEncoding
{
	class IMixingChannels
	{

		public: virtual void compute(ROADoverEncoding::IRawDataBuffer* aBuffer) = 0;
	};
}

#endif
