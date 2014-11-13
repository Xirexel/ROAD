#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__IRawDataBuffer_h__
#define __ROADdecoder__ROADover__IRawDataBuffer_h__

// #include "ROADdecoder/ROADover/IDoubleDataContainer.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class IDoubleDataContainer;
		class IRawDataBuffer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class IRawDataBuffer
		{

			public: virtual ROADdecoder::ROADover::IDoubleDataContainer* getIDoubleDataContainer(unsigned int aIndex) = 0;

			public: virtual unsigned int getCount() = 0;

            public: virtual ~IRawDataBuffer(){}
		};
	}
}

#endif
