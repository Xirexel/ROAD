#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __LminusRMixing_h__
#define __LminusRMixing_h__

 #include "IMixingChannels.h"

namespace FractalEncoding
{
	class IMixingChannels;
	class LminusRMixing;
}

namespace FractalEncoding
{
	class LminusRMixing: public FractalEncoding::IMixingChannels
	{

		public: void compute(double* aFirstChannel, double* aSecondChannel, unsigned int aLength);

        public: virtual ~LminusRMixing();

	};
}

#endif
