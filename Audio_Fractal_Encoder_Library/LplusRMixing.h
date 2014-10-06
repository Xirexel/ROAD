#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __LplusRMixing_h__
#define __LplusRMixing_h__

 #include "IMixingChannels.h"

namespace FractalEncoding
{
	class IMixingChannels;
	class LplusRMixing;
}

namespace FractalEncoding
{
	class LplusRMixing: public FractalEncoding::IMixingChannels
	{

		public: void compute(double* aFirstChannel, double* aSecondChannel, unsigned int aLength);

        public: virtual ~LplusRMixing();
	};
}

#endif
