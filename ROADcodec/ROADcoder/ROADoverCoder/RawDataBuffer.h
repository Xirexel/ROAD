#ifndef __ROADcoder__ROADoverCoder__RawDataBuffer_h__
#define __ROADcoder__ROADoverCoder__RawDataBuffer_h__


#include <vector>


#include "IRawDataBuffer.h"
#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class DoubleDataContainer;
        class IDoubleDataContainer;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;
		class RawDataBuffer: public ROADcoder::ROADoverCoder::IRawDataBuffer
		{
            private: ROADUInt32 _channelCount;
			public: std::vector<ROADcoder::ROADoverCoder::DoubleDataContainer*> _dataCollection;

            public: ROADcoder::ROADoverCoder::IDoubleDataContainer* getIDoubleDataContainer(ROADUInt32 aIndex);

            public: ROADUInt32 getCount();

            public: RawDataBuffer(ROADUInt32 aChannelCount, ROADUInt32 aLength);

            public: virtual ~RawDataBuffer();
		};
	}
}

#endif
