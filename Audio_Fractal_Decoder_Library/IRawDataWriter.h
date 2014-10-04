#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IRawDataWriter_h__
#define __IRawDataWriter_h__

namespace FractalDecoding
{
	class IRawDataWriter;
}

namespace FractalDecoding
{
	class IRawDataWriter
	{

		public: virtual void writeData(double* aFirstChannel, double* aSecongChannel, unsigned int aLength) = 0;

        public: virtual ~IRawDataWriter(){}
	};
}

#endif
