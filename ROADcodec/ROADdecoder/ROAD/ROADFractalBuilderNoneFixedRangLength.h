#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROAD__ROADFractalBuilderNoneFixedRangLength_h__
#define __ROADdecoder__ROAD__ROADFractalBuilderNoneFixedRangLength_h__

#include "DomainProcessorNoneFixedLength.h"
#include "IROADFractalBuilder.h"


#include "road_global.h"

namespace ROADdecoder
{
	namespace ROAD
	{
		class DomainProcessorNoneFixedLength;
		class IFractalItemContainer;
		class IROADFractalBuilder;
		class ROADFractalBuilderNoneFixedRangLength;
	}
}

namespace ROADdecoder
{
	namespace ROAD
	{
        class ROADSHARED_EXPORT ROADFractalBuilderNoneFixedRangLength: public ROADdecoder::ROAD::IROADFractalBuilder
		{
			private: ROADdecoder::ROAD::DomainProcessorNoneFixedLength _domainProcessor;

			public: void build(double* aData, ROADdecoder::ROAD::IFractalItemContainer* aFractalItemContainer);
		};
	}
}

#endif
