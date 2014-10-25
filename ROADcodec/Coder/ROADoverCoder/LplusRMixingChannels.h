#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __LplusRMixingChannels_h__
#define __LplusRMixingChannels_h__

// #include "IRawDataBuffer.h"
 #include "IMixingChannels.h"

namespace ROADoverEncoding
{
	class IRawDataBuffer;
	class IMixingChannels;
	class LplusRMixingChannels;
}

namespace ROADoverEncoding
{
	class LplusRMixingChannels: public ROADoverEncoding::IMixingChannels
	{

		public: void compute(ROADoverEncoding::IRawDataBuffer* aBuffer);
	};
}

#endif
