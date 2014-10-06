#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IRawDataReader_h__
#define __IRawDataReader_h__

#include "ReadResult.h"
// #include "IFractalDataContainer.h"

namespace FractalDecoding
{
	// enum ReadResult;
	class IFractalDataContainer;
	class IRawDataReader;
}

namespace FractalDecoding
{
	class IRawDataReader
	{

		public: virtual FractalDecoding::ReadResult readData(FractalDecoding::IFractalDataContainer* aFirstChannel, FractalDecoding::IFractalDataContainer* aSecondChannel) = 0;

        public: virtual ~IRawDataReader(){}
	};
}

#endif
