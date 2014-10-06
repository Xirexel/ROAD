#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__NoneChannelsMixing_h__
#define __ROADdecoder__ROADover__NoneChannelsMixing_h__

#include "IChannelsMixing.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class IRawDataBuffer;
		class IChannelsMixing;
		class NoneChannelsMixing;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class NoneChannelsMixing: public ROADdecoder::ROADover::IChannelsMixing
		{

			public: void compute(ROADdecoder::ROADover::IRawDataBuffer* aBuffer);
		};
	}
}

#endif
