#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__ROADFractalOrderFactory_h__
#define __ROADdecoder__ROAD__ROADFractalOrderFactory_h__

// #include "ROADdecoder/ROAD/IROADFractalBuilderFactory.h"

namespace ROADdecoder
{
	namespace ROAD
	{
		class IROADFractalBuilderFactory;
		class ROADFractalOrderFactory;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
		class ROADFractalOrderFactory
		{

            public: static ROADdecoder::ROAD::IROADFractalBuilderFactory* getIROADFractalBuilderFactory(unsigned int aOrder);
		};
	}
}

#endif
