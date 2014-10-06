#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__ROADFractalBuilderNoneFixedRangLength_h__
#define __ROADdecoder__ROAD__ROADFractalBuilderNoneFixedRangLength_h__

#include "DomainProcessorFirstOrderNoneFixedLength.h"
#include "IROADFractalFirstOrderBuilder.h"


//#include "road_global.h"

namespace ROADdecoder
{
	namespace ROAD
	{
        class DomainProcessorFirstOrderNoneFixedLength;
        class IFractalFirstOrderItemContainer;
        class IROADFractalFirstOrderBuilder;
        class ROADFractalFirstOrderBuilderNoneFixedRangLength;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
        class ROADFractalFirstOrderBuilderNoneFixedRangLength: public ROADdecoder::ROAD::IROADFractalFirstOrderBuilder
		{
            private: ROADdecoder::ROAD::DomainProcessorFirstOrderNoneFixedLength _domainProcessor;

            public: void build(double* aData, ROADdecoder::ROAD::IFractalFirstOrderItemContainer* aFractalItemContainer);

            public: ROADFractalFirstOrderBuilderNoneFixedRangLength(unsigned int aMaxRangeLength);

            public: virtual ~ROADFractalFirstOrderBuilderNoneFixedRangLength();
		};
	}
}

#endif
