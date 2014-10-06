#ifndef __ROADcoder__ROADCoder__IFractalEncodingOptions_h__
#define __ROADcoder__ROADCoder__IFractalEncodingOptions_h__

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IFractalEncodingOptions;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IFractalEncodingOptions
        {
            public: virtual unsigned int getFrameSampleLength() = 0;

            public: virtual unsigned int getRangTopSampleLength() = 0;

            public: virtual unsigned int getAmountRangLevels() = 0;

			public: virtual unsigned int getDomainShift() = 0;

			public: virtual double getSilenceThreshold() = 0;

            public: virtual double getRangThreshold() = 0;

            public: virtual ~IFractalEncodingOptions(){}
		};
	}
}

#endif
