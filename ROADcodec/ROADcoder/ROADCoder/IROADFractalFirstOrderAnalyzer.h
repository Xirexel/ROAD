#ifndef __ROADcoder__ROADCoder__IROADFractalAnalyzer_h__
#define __ROADcoder__ROADCoder__IROADFractalAnalyzer_h__

#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
        class IFractalFirstOrderItemContainer;
	}
}

namespace ROADcoder
{
    namespace ROADCoder
    {
    using namespace PlatformDependencies;
        class IROADFractalFirstOrderAnalyzer
		{
            public: virtual void analyze(
                    PtrROADReal aData,
                    ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalItemContainer) = 0;

            public: virtual ~IROADFractalFirstOrderAnalyzer(){}
		};
	}
}

#endif
