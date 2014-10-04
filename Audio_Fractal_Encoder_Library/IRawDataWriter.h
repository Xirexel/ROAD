#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IRawDataWriter_h__
#define __IRawDataWriter_h__

// #include "IFractalDataContainer.h"

namespace FractalEncoding
{
	class IFractalDataContainer;
	class IRawDataWriter;
}

namespace FractalEncoding
{
	class IRawDataWriter
	{

		public: virtual void writeData(FractalEncoding::IFractalDataContainer* aFirstChannel, FractalEncoding::IFractalDataContainer* aSecondChannel) = 0;

        public: virtual ~IRawDataWriter(){}
	};
}

#endif
