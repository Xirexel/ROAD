#ifndef __ROADdecoder__ROAD__ROADFractalOrderFactory_h__
#define __ROADdecoder__ROAD__ROADFractalOrderFactory_h__

#include "platformdependencies.h"

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

    using namespace PlatformDependencies;
		class ROADFractalOrderFactory
		{
            public: static ROADdecoder::ROAD::IROADFractalBuilderFactory* getIROADFractalBuilderFactory(ROADUInt32 aOrder);
		};
	}
}

#endif
