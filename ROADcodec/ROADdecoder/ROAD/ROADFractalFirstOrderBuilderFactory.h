#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__ROADFractalFirstOrderBuilderFactory_h__
#define __ROADdecoder__ROAD__ROADFractalFirstOrderBuilderFactory_h__

// #include "IROADFractalFirstOrderBuilder.h"
#include "IROADFractalBuilderFactory.h"

namespace ROADdecoder
{
	namespace ROAD
	{
		class IROADFractalFirstOrderBuilder;
		class IROADFractalBuilderFactory;
		class ROADFractalFirstOrderBuilderFactory;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
		class ROADFractalFirstOrderBuilderFactory: public ROADdecoder::ROAD::IROADFractalBuilderFactory
		{

			public: ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* getIROADFractalFirstOrderBuilder(unsigned int aIndex, unsigned int aMaxRangeLength);

			public: unsigned int getOrder();
		};
	}
}

#endif
