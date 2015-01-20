#ifndef __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsExperemental_h__
#define __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsExperemental_h__


#include "ChannelsMixingMode.h"
#include "ROADFormatMode.h"
#include "IROADoverEncodingOptions.h"

#include "roadovercoder_global.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		// enum ChannelsMixingMode;
		// enum ROADFormatMode;
		class IROADoverEncodingOptions;
		class ROADoverEncodingOptionsExperemental;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
        class ROADOVERCODERSHARED_EXPORT ROADoverEncodingOptionsExperemental: public ROADcoder::ROADoverCoder::IROADoverEncodingOptions
		{
			private: unsigned int _frameSampleLength;
			private: unsigned int _superFrameLength;
			private: unsigned int _rangTopSampleLength;
			private: unsigned int _amountRangLevels;
			private: unsigned int _domainShift;
			private: double _silenceThreshold;
            private: double _rangThreshold;
			private: ROADcoder::ROADoverCoder::ChannelsMixingMode _mixingChannelsMode;
            private: unsigned int _amountOfChannels;
            private: unsigned int _encryptionFormat;
            private: unsigned int _bitsPerSample;

            public: unsigned int getROADFormatMode();

			public: void setFrameSampleLength(unsigned int aFrameSampleLength);

			public: unsigned int getFrameSampleLength();

			public: void setSuperFrameLength(unsigned int aSuperFrameLength);

			public: unsigned int getSuperFrameLength();

			public: void setRangTopSampleLength(unsigned int aRangTopSampleLength);

			public: unsigned int getRangTopSampleLength();

			public: void setAmountRangLevels(unsigned int aAmountRangLevels);

			public: unsigned int getAmountRangLevels();

			public: void setDomainShift(unsigned int aDomainShift);

			public: unsigned int getDomainShift();

			public: void setSilenceThreshold(double aSilenceThreshold);

			public: double getSilenceThreshold();

			public: void setRangThreshold(double aRangThreshold);

			public: double getRangThreshold();

            public: void setMixingChannelsMode(ROADcoder::ROADoverCoder::ChannelsMixingMode aMixingChannelsMode);

            public: ROADcoder::ROADoverCoder::ChannelsMixingMode getMixingChannelsMode();

            public: void setAmountOfChannels(unsigned int aAmountOfChannels);

            public: unsigned int getAmountOfChannels();

            public: void setEncryptionFormat(unsigned int aEncryptionFormat);

            public: unsigned int getEncryptionFormat();

            public: void setBitsPerSample(unsigned int aBitsPerSample);

            public: unsigned int getBitsPerSample();

            public: virtual std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> clone();
		};
	}
}

#endif