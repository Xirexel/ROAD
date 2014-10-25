#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __LminusRMixingChannels_h__
#define __LminusRMixingChannels_h__

// #include "IRawDataBuffer.h"
 #include "IMixingChannels.h"

namespace ROADoverEncoding
{
	class IRawDataBuffer;
	class IMixingChannels;
	class LminusRMixingChannels;
}

namespace ROADoverEncoding
{
	class LminusRMixingChannels: public ROADoverEncoding::IMixingChannels
	{

		public: void compute(ROADoverEncoding::IRawDataBuffer* aBuffer);
	};
}

#endif
