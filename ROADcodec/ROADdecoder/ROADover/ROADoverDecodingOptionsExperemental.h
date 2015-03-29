#ifndef __ROADdecoder__ROADover__ROADoverDecodingOptionsExperemental_h__
#define __ROADdecoder__ROADover__ROADoverDecodingOptionsExperemental_h__

#include "ChannelsMixingMode.h"
#include "IROADoverDecodingOptions.h"
#include "../Driver/IDataReadDriver.h"
#include "roadover_global.h"


namespace ROADdecoder
{
	namespace ROADover
	{
        class ROADOVERSHARED_EXPORT ROADoverDecodingOptionsExperemental: public ROADdecoder::ROADover::IROADoverDecodingOptions
		{
            private: ROADdecoder::ROADover::ROADFormatMode _formatMode;
            private: ROADdecoder::ROADover::ChannelsMixingMode _channelsMixingMode;
            private: ROADUInt32 _amountOfChannels;
            private: ROADUInt32 _superframeLength;
            private: ROADUInt32 _frameRangLength;
            private: ROADUInt32 _samplesPerRang;
            private: ROADUInt32 _relativeDomainShift;
            private: ROADUInt32 _scaleDomainShift;
            private: ROADUInt32 _encriptionCode;
            private: ROADUInt32 _originalBitsPerSample;

            public: ROADUInt32 getROADFormatMode();

            public: ROADoverDecodingOptionsExperemental(Driver::IDataReadDriver *aPtrIDataReadDriver);

            public: virtual ~ROADoverDecodingOptionsExperemental();

            public: virtual ROADUInt16 getAmountOfChannels();

            public: ROADUInt32 getSuperframeLength();

			public: ROADdecoder::ROADover::ChannelsMixingMode getChannelsMixingMode();

            public: ROADUInt32 getFrameRangLength();

            public: ROADUInt32 getSamplesPerRang();

            public: ROADUInt32 getRelativeDomainShift();

            public: ROADUInt32 getScaleDomainShift();

            public: ROADUInt32 getOriginalSamplesPerRang();

            public: void setFrequencyScale(ROADUInt32 aValue);

            public: void setOriginalBitsPerSample(ROADUInt32 aValue);

            public: ROADUInt32 getOriginalBitsPerSample();

            public: ROADUInt32 getEncryptionFormat();
		};
	}
}

#endif
