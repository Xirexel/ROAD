#ifndef __ROADcoder__ROADoverCoder__IRawDataBuffer_h__
#define __ROADcoder__ROADoverCoder__IRawDataBuffer_h__

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IDoubleDataContainer;
		class IRawDataBuffer;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IRawDataBuffer
		{

			public: virtual ROADcoder::ROADoverCoder::IDoubleDataContainer* getIDoubleDataContainer(unsigned int aIndex) = 0;

            public: virtual unsigned int getCount() = 0;

            public: virtual ~IRawDataBuffer(){}
		};
	}
}

#endif
