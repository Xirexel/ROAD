#ifndef __ROADcoder__ROADoverCoder__MIDChannelsMixing_h__
#define __ROADcoder__ROADoverCoder__MIDChannelsMixing_h__

#include "IChannelsMixing.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IChannelsMixing;
		class MIDChannelsMixing;
        class IRawDataBuffer;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class MIDChannelsMixing: public ROADcoder::ROADoverCoder::IChannelsMixing
		{

			public: void compute(ROADcoder::ROADoverCoder::IRawDataBuffer* aBuffer);
		};
	}
}

#endif
