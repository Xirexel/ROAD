#ifndef __ROADcoder__ROADCoder__ROADFractalFirstOrderAnalyzerNoneFixedRangLength_h__
#define __ROADcoder__ROADCoder__ROADFractalFirstOrderAnalyzerNoneFixedRangLength_h__

#include <vector>


#include "IFractalFirstOrderItemContainer.h"
#include "IROADFractalFirstOrderAnalyzer.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
		class DomainPool;
        class IFractalFirstOrderItemContainer;
        class IROADFractalFirstOrderAnalyzer;
        class ROADFractalFirstOrderAnalyzerNoneFixedRangLength;
        class IFractalEncodingOptions;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
        class ROADFractalFirstOrderAnalyzerNoneFixedRangLength: public ROADcoder::ROADCoder::IROADFractalFirstOrderAnalyzer
        {
            private: ROADUInt32 _amountRangLevels;
            private: ROADUInt32 _domainShift;
            private: ROADUInt32 _frameSampleLength;
            private: ROADUInt32 _rangTopSampleLength;
            private: ROADReal _rangThreshold;
            private: ROADReal _silenceThreshold;
            private: ROADUInt32 _currentPosition;



			public: std::vector<ROADcoder::ROADCoder::DomainPool*> _domainPools;

            public: ROADFractalFirstOrderAnalyzerNoneFixedRangLength(ROADcoder::ROADCoder::IFractalEncodingOptions* aOptions);

            public: void analyze(PtrROADReal aData, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalFirstOrderItemContainer);

            private: void silenceMatch(PtrROADReal aData, ROADUInt32 aSilenceSampleLength, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalFirstOrderItemContainer);

            private: void domainIntoRangMatch(PtrROADReal aData, ROADUInt32 aRangSampleLength, ROADUInt32 aDeepthIndex, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalFirstOrderItemContainer);

            private: ROADReal computeSumValue(PtrROADReal aData, ROADUInt32 aLength);

            private: ROADReal computeDeviationValue(PtrROADReal aData, ROADUInt32 aLength, ROADReal aAverValue);

            private: void populateDomainPools(PtrROADReal aData);

            private: ROADReal computeAlpha(const PtrROADReal aDataRang, const PtrROADReal aDataDomain, ROADUInt32 aLength, ROADReal aSumRang, ROADReal aSumDomain);

            public: virtual ~ROADFractalFirstOrderAnalyzerNoneFixedRangLength();
		};
	}
}

#endif
