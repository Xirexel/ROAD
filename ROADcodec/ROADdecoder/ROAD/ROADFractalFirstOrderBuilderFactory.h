#ifndef __ROADdecoder__ROAD__ROADFractalFirstOrderBuilderFactory_h__
#define __ROADdecoder__ROAD__ROADFractalFirstOrderBuilderFactory_h__

// #include "IROADFractalFirstOrderBuilder.h"
#include "IROADFractalBuilderFactory.h"

namespace ROADdecoder
{
	namespace ROAD
	{
        class IROADFractalFirstOrderBuilder;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
		class ROADFractalFirstOrderBuilderFactory: public ROADdecoder::ROAD::IROADFractalBuilderFactory
		{
            public: ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* getIROADFractalFirstOrderBuilder(ROADUInt32 aIndex, ROADUInt32 aMaxRangeLength);

            public: ROADUInt32 getOrder();
		};
	}
}

#endif
