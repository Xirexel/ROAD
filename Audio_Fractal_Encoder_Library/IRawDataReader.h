#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IRawDataReader_h__
#define __IRawDataReader_h__

#include "ReadResult.h"

namespace FractalEncoding
{
	// enum ReadResult;
	class IRawDataReader;
}

namespace FractalEncoding
{
	class IRawDataReader
	{

		public: virtual FractalEncoding::ReadResult readData(double* aLeftChannel, double* aRightChannel, unsigned int aLength) = 0;

        public: virtual ~IRawDataReader(){}
	};
}

#endif
