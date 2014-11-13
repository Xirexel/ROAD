#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__SIDEChannelsMixing_h__
#define __ROADdecoder__ROADover__SIDEChannelsMixing_h__


#include "IChannelsMixing.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class IRawDataBuffer;
		class IChannelsMixing;
		class SIDEChannelsMixing;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class SIDEChannelsMixing: public ROADdecoder::ROADover::IChannelsMixing
		{

			public: void compute(ROADdecoder::ROADover::IRawDataBuffer* aBuffer);
		};
	}
}

#endif
