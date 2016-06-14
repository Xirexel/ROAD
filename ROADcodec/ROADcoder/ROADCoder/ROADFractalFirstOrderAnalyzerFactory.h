#ifndef __ROADcoder__ROADCoder__ROADFractalAnalyzerFactory_h__
#define __ROADcoder__ROADCoder__ROADFractalAnalyzerFactory_h__

#include "IROADFractalAnalyzerFactory.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
        class IROADFractalAnalyzerFactory;
        class IROADFractalFirstOrderAnalyzer;
		class IFractalEncodingOptions;
        class ROADFractalFirstOrderAnalyzerFactory;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
        class ROADFractalFirstOrderAnalyzerFactory: public ROADcoder::ROADCoder::IROADFractalAnalyzerFactory
		{
            public: static ROADcoder::ROADCoder::IROADFractalFirstOrderAnalyzer* getIROADFractalFirstOrderAnalyzer(
                    ROADcoder::ROADCoder::IFractalEncodingOptions* aOptions,
                    ROADUInt32 aType);

            public: ROADUInt32 getOrder();

        };
	}
}

#endif
