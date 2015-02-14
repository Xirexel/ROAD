#ifndef __ROADcoder__ROADoverCoder__FractalEncodingOptions_h__
#define __ROADcoder__ROADoverCoder__FractalEncodingOptions_h__

#include "IFractalEncodingOptions.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
        using namespace PlatformDependencies;

		class FractalEncodingOptions: public ROADcoder::ROADCoder::IFractalEncodingOptions
		{
            private: ROADUInt32 _frameSampleLength;
            private: ROADUInt32 _rangTopSampleLength;
            private: ROADUInt32 _amountRangLevels;
            private: ROADUInt32 _domainShift;
            private: ROADReal _silenceThreshold;
            private: ROADReal _rangThreshold;

            public: ROADUInt32 getFrameSampleLength();

            public: ROADUInt32 getRangTopSampleLength();

            public: ROADUInt32 getAmountRangLevels();

            public: ROADUInt32 getDomainShift();

            public: ROADReal getSilenceThreshold();

            public: ROADReal getRangThreshold();

            public: FractalEncodingOptions(ROADUInt32 aFrameSampleLength, ROADUInt32 aRangTopSampleLength, ROADUInt32 aAmountRangLevels, ROADUInt32 aDomainShift, ROADReal aSilenceThreshold, ROADReal aRangThreshold);
		};
	}
}

#endif
