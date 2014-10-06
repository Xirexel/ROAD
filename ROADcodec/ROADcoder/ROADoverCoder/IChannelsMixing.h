#ifndef __ROADcoder__ROADoverCoder__IChannelsMixing_h__
#define __ROADcoder__ROADoverCoder__IChannelsMixing_h__


namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IRawDataBuffer;
		class IChannelsMixing;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IChannelsMixing
		{

			public: virtual void compute(ROADcoder::ROADoverCoder::IRawDataBuffer* aBuffer) = 0;

            public: virtual ~IChannelsMixing(){}
		};
	}
}

#endif
