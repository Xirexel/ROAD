#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __NoneMixingChannels_h__
#define __NoneMixingChannels_h__

// #include "IRawDataBuffer.h"
 #include "IMixingChannels.h"

namespace ROADoverEncoding
{
	class IRawDataBuffer;
	class IMixingChannels;
	class NoneMixingChannels;
}

namespace ROADoverEncoding
{
	class NoneMixingChannels: public ROADoverEncoding::IMixingChannels
	{

		public: void compute(ROADoverEncoding::IRawDataBuffer* aBuffer);
	};
}

#endif
