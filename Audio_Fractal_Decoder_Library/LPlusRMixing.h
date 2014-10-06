#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __LPlusRMixing_h__
#define __LPlusRMixing_h__

 #include "IMixing.h"

namespace FractalDecoding
{
	class IMixing;
	class LPlusRMixing;
}

namespace FractalDecoding
{
	class LPlusRMixing: public FractalDecoding::IMixing
	{

        public: void compute(double* aFirstChannel, double* aSecondChannel, unsigned int aLength);
	};
}

#endif
