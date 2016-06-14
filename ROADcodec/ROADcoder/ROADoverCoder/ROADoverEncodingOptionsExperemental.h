#ifndef __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsExperemental_h__
#define __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsExperemental_h__


#include "ChannelsMixingMode.h"
#include "ROADFormatMode.h"
#include "IROADoverEncodingOptions.h"
#include "FractalFormatRawDataContainer.h"

#include "roadovercoder_global.h"

namespace ROADcoder
{
	namespace ROADoverCoder
    {
		class IROADoverEncodingOptions;
		class ROADoverEncodingOptionsExperemental;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;
        class ROADOVERCODERSHARED_EXPORT ROADoverEncodingOptionsExperemental: public ROADcoder::ROADoverCoder::IROADoverEncodingOptions
		{
            private: ROADUInt32 _frameSampleLength;
            private: ROADUInt32 _superFrameLength;
            private: ROADUInt32 _rangTopSampleLength;
            private: ROADUInt32 _amountRangLevels;
            private: ROADUInt32 _domainShift;
            private: ROADReal _silenceThreshold;
            private: ROADReal _rangThreshold;
			private: ROADcoder::ROADoverCoder::ChannelsMixingMode _mixingChannelsMode;
            private: ROADUInt16 _amountOfChannels;
            private: ROADUInt32 _encryptionFormat;
            private: ROADUInt8 _bitsPerSample;


            public: ROADUInt8 getROADFormatMode();

            public: void setFrameSampleLength(ROADUInt32 aFrameSampleLength);

            public: ROADUInt32 getFrameSampleLength();

            public: void setSuperFrameLength(ROADUInt32 aSuperFrameLength);

            public: ROADUInt32 getSuperFrameLength();

            public: void setRangTopSampleLength(ROADUInt32 aRangTopSampleLength);

            public: ROADUInt32 getRangTopSampleLength();

            public: void setAmountRangLevels(ROADUInt32 aAmountRangLevels);

            public: ROADUInt32 getAmountRangLevels();

            public: void setDomainShift(ROADUInt32 aDomainShift);

            public: ROADUInt32 getDomainShift();

            public: void setSilenceThreshold(ROADReal aSilenceThreshold);

            public: ROADReal getSilenceThreshold();

            public: void setRangThreshold(ROADReal aRangThreshold);

            public: ROADReal getRangThreshold();

            public: void setMixingChannelsMode(ROADcoder::ROADoverCoder::ChannelsMixingMode aMixingChannelsMode);

            public: ROADcoder::ROADoverCoder::ChannelsMixingMode getMixingChannelsMode();

            public: void setAmountOfChannels(ROADUInt16 aAmountOfChannels);

            public: ROADUInt16 getAmountOfChannels();

            public: void setEncryptionFormat(ROADUInt32 aEncryptionFormat);

            public: ROADUInt32 getEncryptionFormat();

            public: void setBitsPerSampleCode(ROADRawDataFormat aBitsPerSample);

            public: ROADUInt8 getBitsPerSample();

            public: virtual Unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> clone();

            public: Unique_ptr<FractalFormatRawDataContainer> getFractalFormatRawDataContainer();
		};
	}
}

#endif
