#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IMixingChannels_h__
#define __IMixingChannels_h__

namespace FractalEncoding
{
	class IMixingChannels;
}

namespace FractalEncoding
{
	class IMixingChannels
	{

		public: virtual void compute(double* aFirstChannel, double* aSecondChannel, unsigned int aLength) = 0;

        public: virtual ~IMixingChannels(){}
	};
}

#endif
