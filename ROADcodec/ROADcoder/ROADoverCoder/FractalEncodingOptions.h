#ifndef __ROADcoder__ROADoverCoder__FractalEncodingOptions_h__
#define __ROADcoder__ROADoverCoder__FractalEncodingOptions_h__

#include "IFractalEncodingOptions.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IFractalEncodingOptions;
	}
	namespace ROADoverCoder
	{
		class FractalEncodingOptions;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class FractalEncodingOptions: public ROADcoder::ROADCoder::IFractalEncodingOptions
		{
			private: unsigned int _frameSampleLength;
			private: unsigned int _rangTopSampleLength;
			private: unsigned int _amountRangLevels;
			private: unsigned int _domainShift;
			private: double _silenceThreshold;
			private: double _rangThreshold;

			public: unsigned int getFrameSampleLength();

			public: unsigned int getRangTopSampleLength();

			public: unsigned int getAmountRangLevels();

			public: unsigned int getDomainShift();

			public: double getSilenceThreshold();

			public: double getRangThreshold();

			public: FractalEncodingOptions(unsigned int aFrameSampleLength, unsigned int aRangTopSampleLength, unsigned int aAmountRangLevels, unsigned int aDomainShift, double aSilenceThreshold, double aRangThreshold);
		};
	}
}

#endif
