#ifndef __ROADcoder__ROADCoder__IROADFractalAnalyzer_h__
#define __ROADcoder__ROADCoder__IROADFractalAnalyzer_h__

namespace ROADcoder
{
	namespace ROADCoder
	{
        class IFractalFirstOrderItemContainer;
        class IROADFractalFirstOrderAnalyzer;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
        class IROADFractalFirstOrderAnalyzer
		{
            public: virtual void analyze(double* aData, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalItemContainer) = 0;

            public: virtual ~IROADFractalFirstOrderAnalyzer(){}
		};
	}
}

#endif
