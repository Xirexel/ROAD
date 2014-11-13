#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__IROADFractalBuilder_h__
#define __ROADdecoder__ROAD__IROADFractalBuilder_h__

// #include "ROADdecoder/ROAD/IFractalItemContainer.h"

namespace ROADdecoder
{
	namespace ROAD
	{
		class IFractalItemContainer;
		class IROADFractalBuilder;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
		class IROADFractalBuilder
		{

			public: virtual void build(double* aData, ROADdecoder::ROAD::IFractalItemContainer* aFractalItemContainer) = 0;
		};
	}
}

#endif
