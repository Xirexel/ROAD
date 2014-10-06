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
        class IFractalFirstOrderItemContainer;
        class IROADFractalFirstOrderBuilder;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
        class IROADFractalFirstOrderBuilder
		{

            public: virtual void build(double* aData, ROADdecoder::ROAD::IFractalFirstOrderItemContainer* aFractalItemContainer) = 0;

            public: virtual ~IROADFractalFirstOrderBuilder(){}
		};
	}
}

#endif
