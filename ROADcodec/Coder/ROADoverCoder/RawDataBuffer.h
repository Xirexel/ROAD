#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __RawDataBuffer_h__
#define __RawDataBuffer_h__

#include "DoubleDataContainer.h"
// #include "IRawDataBuffer.h"

namespace ROADoverEncoding
{
	class DoubleDataContainer;
	class IRawDataBuffer;
	class RawDataBuffer;
}

namespace ROADoverEncoding
{
	class RawDataBuffer: public ROADoverEncoding::IRawDataBuffer
	{
		private: unsigned int _count;
		private: std::vector<ROADoverEncoding::DoubleDataContainer*> _channelsArray;

		public: double* getData(unsigned int aIndex);

		public: unsigned int getCount();

		public: RawDataBuffer(unsigned int aCount, unsigned int aLength);
	};
}

#endif
