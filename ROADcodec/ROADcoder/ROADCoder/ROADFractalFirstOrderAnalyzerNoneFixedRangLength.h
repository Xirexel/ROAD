#include <string>
#include <vector>
#include <exception>

#ifndef __ROADcoder__ROADCoder__ROADFractalFirstOrderAnalyzerNoneFixedRangLength_h__
#define __ROADcoder__ROADCoder__ROADFractalFirstOrderAnalyzerNoneFixedRangLength_h__

// #include "ROADcoder/ROADCoder/DomainPool.h"
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
            private: unsigned int _amountRangLevels;
            private: unsigned int _domainShift;
            private: unsigned int _frameSampleLength;
            private: unsigned int _rangTopSampleLength;
            private: double _rangThreshold;
            private: double _silenceThreshold;
            private: unsigned int _currentPosition;



			public: std::vector<ROADcoder::ROADCoder::DomainPool*> _domainPools;

            public: ROADFractalFirstOrderAnalyzerNoneFixedRangLength(ROADcoder::ROADCoder::IFractalEncodingOptions* aOptions);

            public: void analyze(double* aData, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalFirstOrderItemContainer);

            private: void silenceMatch(double* aData, unsigned int aSilenceSampleLength, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalFirstOrderItemContainer);

            private: void domainIntoRangMatch(double* aData, unsigned int aRangSampleLength, unsigned int aDeepthIndex, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalFirstOrderItemContainer);

			private: double computeSumValue(double* aData, unsigned int aLength);

			private: double computeDeviationValue(double* aData, unsigned int aLength, double aAverValue);

			private: void populateDomainPools(double* aData);

            private: double computeAlpha(const double *aDataRang, const double *aDataDomain, unsigned int aLength, double aSumRang, double aSumDomain);

            public: virtual ~ROADFractalFirstOrderAnalyzerNoneFixedRangLength();
		};
	}
}

#endif
