#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IRawDataBuffer_h__
#define __IRawDataBuffer_h__

namespace ROADoverEncoding
{
	class IRawDataBuffer;
}

namespace ROADoverEncoding
{
	class IRawDataBuffer
	{

		public: virtual double* getData(unsigned int aIndex) = 0;

		public: virtual unsigned int getCount() = 0;
	};
}

#endif
