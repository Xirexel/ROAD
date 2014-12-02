#include <string>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

#ifndef __ROADdecoder__ROAD__ROADFractalBuilderFactory_h__
#define __ROADdecoder__ROAD__ROADFractalBuilderFactory_h__

// #include "ROADdecoder/ROAD/IROADFractalBuilder.h"
//#include "road_global.h"

namespace ROADdecoder
{
	namespace ROAD
	{
		class IROADFractalBuilder;
		class ROADFractalBuilderFactory;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
        class ROADFractalBuilderFactory
		{

            public: static IROADFractalBuilder *getIROADFractalBuilder(unsigned int aMaxRangeLength);
		};
	}
}

#endif
