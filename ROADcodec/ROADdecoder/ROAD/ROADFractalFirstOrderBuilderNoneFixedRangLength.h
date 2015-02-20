#ifndef __ROADdecoder__ROAD__ROADFractalBuilderNoneFixedRangLength_h__
#define __ROADdecoder__ROAD__ROADFractalBuilderNoneFixedRangLength_h__

#include "DomainProcessorFirstOrderNoneFixedLength.h"
#include "IROADFractalFirstOrderBuilder.h"

namespace ROADdecoder
{
	namespace ROAD
	{
        class DomainProcessorFirstOrderNoneFixedLength;
        class IFractalFirstOrderItemContainer;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
        class ROADFractalFirstOrderBuilderNoneFixedRangLength: public ROADdecoder::ROAD::IROADFractalFirstOrderBuilder
		{
            private: ROADdecoder::ROAD::DomainProcessorFirstOrderNoneFixedLength _domainProcessor;

            public: void build(PtrROADReal aData, ROADdecoder::ROAD::IFractalFirstOrderItemContainer* aFractalItemContainer);

            public: ROADFractalFirstOrderBuilderNoneFixedRangLength(ROADUInt32 aMaxRangeLength);

            public: virtual ~ROADFractalFirstOrderBuilderNoneFixedRangLength();
		};
	}
}

#endif
