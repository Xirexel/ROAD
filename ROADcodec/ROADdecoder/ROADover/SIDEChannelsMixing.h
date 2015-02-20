#ifndef __ROADdecoder__ROADover__SIDEChannelsMixing_h__
#define __ROADdecoder__ROADover__SIDEChannelsMixing_h__


#include "IChannelsMixing.h"

namespace ROADdecoder
{
	namespace ROADover
	{
        class IRawDataBuffer;
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
