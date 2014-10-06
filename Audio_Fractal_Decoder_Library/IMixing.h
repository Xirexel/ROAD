#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IMixing_h__
#define __IMixing_h__

namespace FractalDecoding
{
	class IMixing;
}

namespace FractalDecoding
{
	class IMixing
	{

		public: virtual void compute(double* aFirstChannel, double* aSecongChannel, unsigned int aLength) = 0;

        public: virtual ~IMixing(){}
	};
}

#endif
