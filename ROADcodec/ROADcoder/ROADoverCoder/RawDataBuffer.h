#ifndef __ROADcoder__ROADoverCoder__RawDataBuffer_h__
#define __ROADcoder__ROADoverCoder__RawDataBuffer_h__


#include <vector>


#include "IRawDataBuffer.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class DoubleDataContainer;
		class IDoubleDataContainer;
		class IRawDataBuffer;
		class RawDataBuffer;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class RawDataBuffer: public ROADcoder::ROADoverCoder::IRawDataBuffer
		{
			private: unsigned int _channelCount;
			public: std::vector<ROADcoder::ROADoverCoder::DoubleDataContainer*> _dataCollection;

			public: ROADcoder::ROADoverCoder::IDoubleDataContainer* getIDoubleDataContainer(unsigned int aIndex);

			public: unsigned int getCount();

			public: RawDataBuffer(unsigned int aChannelCount, unsigned int aLength);

            public: virtual ~RawDataBuffer();
		};
	}
}

#endif
