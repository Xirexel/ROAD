#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IRawDataReader_h__
#define __IRawDataReader_h__

#include "ReadResult.h"

namespace ROADEncoding
{
	// enum ReadResult;
	class IRawDataReader;
}

namespace ROADEncoding
{
	class IRawDataReader
	{

		public: virtual ROADEncoding::ReadResult readData(double* aData, unsigned int aLength) = 0;
	};
}

#endif
