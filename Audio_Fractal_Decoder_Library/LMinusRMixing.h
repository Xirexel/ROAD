#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __LMinusRMixing_h__
#define __LMinusRMixing_h__

 #include "IMixing.h"

namespace FractalDecoding
{
	class IMixing;
	class LMinusRMixing;
}

namespace FractalDecoding
{
	class LMinusRMixing: public FractalDecoding::IMixing
	{

        public: void compute(double* aFirstChannel, double* aSecondChannel, unsigned int aLength);
	};
}

#endif
