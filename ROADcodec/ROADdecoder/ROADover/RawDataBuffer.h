#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__RawDataBuffer_h__
#define __ROADdecoder__ROADover__RawDataBuffer_h__

//#include "ROADdecoder/ROADover/DoubleDataContainer.h"
// #include "ROADdecoder/ROADover/IDoubleDataContainer.h"
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
			private: unsigned int _count;
			private: std::vector<ROADdecoder::ROADover::DoubleDataContainer*> _dataCollection;

			public: ROADdecoder::ROADover::IDoubleDataContainer* getIDoubleDataContainer(unsigned int aIndex);

			public: unsigned int getCount();

            public: ~RawDataBuffer();

            public: RawDataBuffer(unsigned int aCount, unsigned int aSuperFrameLength);
		};
	}
}

#endif
