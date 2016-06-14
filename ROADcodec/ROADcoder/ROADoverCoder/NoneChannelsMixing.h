#ifndef __ROADcoder__ROADoverCoder__NoneChannelsMixing_h__
#define __ROADcoder__ROADoverCoder__NoneChannelsMixing_h__


#include "IChannelsMixing.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
        class IRawDataBuffer;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class NoneChannelsMixing: public ROADcoder::ROADoverCoder::IChannelsMixing
		{
            public: void compute(ROADcoder::ROADoverCoder::IRawDataBuffer*){}
		};
	}
}

#endif
