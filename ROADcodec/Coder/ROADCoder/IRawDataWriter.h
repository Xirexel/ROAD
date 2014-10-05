#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IRawDataWriter_h__
#define __IRawDataWriter_h__

// #include "IFractalDataContainer.h"

namespace ROADEncoding
{
	class IFractalDataContainer;
	class IRawDataWriter;
}

namespace ROADEncoding
{
	class IRawDataWriter
	{

		public: virtual void writeData(ROADEncoding::IFractalDataContainer* aRawROADdata) = 0;
	};
}

#endif
