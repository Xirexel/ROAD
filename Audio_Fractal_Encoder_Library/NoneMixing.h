#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __NoneMixing_h__
#define __NoneMixing_h__

 #include "IMixingChannels.h"

namespace FractalEncoding
{
	class IMixingChannels;
	class NoneMixing;
}

namespace FractalEncoding
{
	class NoneMixing: public FractalEncoding::IMixingChannels
	{

		public: void compute(double* aFirstChannel, double* aSecondChannel, unsigned int aLength);

        public: virtual ~NoneMixing();
	};
}

#endif
