#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__MIDChannelsMixing_h__
#define __ROADdecoder__ROADover__MIDChannelsMixing_h__

#include "IChannelsMixing.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class IRawDataBuffer;
		class IChannelsMixing;
		class MIDChannelsMixing;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class MIDChannelsMixing: public ROADdecoder::ROADover::IChannelsMixing
		{

			public: void compute(ROADdecoder::ROADover::IRawDataBuffer* aBuffer);
		};
	}
}

#endif
