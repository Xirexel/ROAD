#ifndef __ROADcoder__ROADoverCoder__SIDEChannelsMixing_h__
#define __ROADcoder__ROADoverCoder__SIDEChannelsMixing_h__

#include "IChannelsMixing.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IChannelsMixing;
		class SIDEChannelsMixing;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class SIDEChannelsMixing: public ROADcoder::ROADoverCoder::IChannelsMixing
		{
			public: void compute(ROADcoder::ROADoverCoder::IRawDataBuffer* aBuffer);
		};
	}
}

#endif
