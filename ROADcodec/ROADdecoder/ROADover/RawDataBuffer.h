#ifndef __ROADdecoder__ROADover__RawDataBuffer_h__
#define __ROADdecoder__ROADover__RawDataBuffer_h__

#include <vector>

#include "IRawDataBuffer.h"


namespace ROADdecoder
{
	namespace ROADover
	{
		class DoubleDataContainer;
		class IDoubleDataContainer;
		class IRawDataBuffer;
		class RawDataBuffer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class RawDataBuffer: public ROADdecoder::ROADover::IRawDataBuffer
		{
            private: ROADUInt32 _count;
            private: ROADUInt32 _length;
			private: std::vector<ROADdecoder::ROADover::DoubleDataContainer*> _dataCollection;

            public: ROADdecoder::ROADover::IDoubleDataContainer* getIDoubleDataContainer(ROADUInt32 aIndex);

            public: ROADUInt32 getCount();

            public: ROADUInt32 getLength();

            public: ~RawDataBuffer();

            public: RawDataBuffer(ROADUInt32 aCount, ROADUInt32 aSuperFrameLength);
		};
	}
}

#endif
