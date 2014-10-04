#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __NoneMixing_h__
#define __NoneMixing_h__

 #include "IMixing.h"

namespace FractalDecoding
{
	class IMixing;
	class NoneMixing;
}

namespace FractalDecoding
{
	class NoneMixing: public FractalDecoding::IMixing
	{

		public: void compute(double* aFirstChannel, double* aSecongChannel, unsigned int aLength);
	};
}

#endif
