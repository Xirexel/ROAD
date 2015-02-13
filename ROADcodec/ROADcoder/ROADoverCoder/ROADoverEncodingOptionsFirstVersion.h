#ifndef __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsFirstVersion_h__
#define __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsFirstVersion_h__

#include "ChannelsMixingMode.h"
#include "IROADoverEncodingOptions.h"
#include "FractalFormatRawDataContainer.h"



namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class ROADoverEncodingOptionsFirstVersion: public ROADcoder::ROADoverCoder::IROADoverEncodingOptions
        {
            private: ROADByte _superFrameLength;
            private: ROADByte _rangSampleLength;
            private: ROADByte _amountRangLevels;
            private: ROADByte _domainShift;
            private: ROADReal _silenceThreshold;
            private: ROADReal _rangThreshold;
            private: ROADByte _mixingChannelsMode;
            private: ROADUInt16 _amountOfChannels;
            private: ROADUInt32 _encryptionFormat;
            private: ROADByte _bitsPerSampleCode;
            private: ROADUInt16 _selectedPreListeningChannel;
            private: ROADByte _endianType;
            private: ROADInt8 _constantScale;
            private: ROADUInt32 _originalFrequency;

            public: virtual ROADByte getROADFormatMode();

            public: std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> clone();

            public: ROADoverEncodingOptionsFirstVersion();

            public: virtual ~ROADoverEncodingOptionsFirstVersion();

            public: ROADUInt32 getFrameSampleLength();

            public: void setSuperFrameLength(ROADByte aSuperFrameLength);

            public: ROADByte getSuperFrameLength();

            public: void setPowerRangSampleLength(ROADByte aRangSampleLength);

            public: ROADByte getRangSampleLength();

            public: void setAmountRangLevels(ROADByte aAmountRangLevels);

            public: ROADByte getAmountRangLevels();

            public: void setDomainShift(ROADByte aDomainShift);

            public: ROADByte getDomainShift();

            public: void setSilenceThreshold(ROADReal aSilenceThreshold);

            public: ROADReal getSilenceThreshold();

            public: void setRangThreshold(ROADReal aRangThreshold);

            public: ROADReal getRangThreshold();

            public: void setMixingChannelsMode(ROADByte aMixingChannelsMode);

            public: ROADByte getMixingChannelsMode();

            public: void setAmountOfChannels(ROADUInt16 aAmountOfChannels);

            public: ROADUInt16 getAmountOfChannels();

            public: void setEncryptionFormat(ROADUInt32 aEncryptionFormat);

            public: ROADUInt32 getEncryptionFormat();

            public: void setBitsPerSampleCode(ROADByte aBitsPerSampleCode);

            public: ROADByte getBitsPerSampleCode();

            public: void setSelectedPreListeningChannel(ROADUInt16 aSelectedPreListeningChannel);

            public: ROADUInt16 getSelectedPreListeningChannel();

            public: ROADUInt32 getEndianType();

            public: void setEndianType(ROADUInt32 aEndianType);

            public: ROADInt8 getConstantScale();

            public: void setConstantScale(ROADInt8 aConstantScale);

            public: ROADUInt32 getOriginalFrequency();

            public: void setOriginalFrequency(ROADUInt32 aOriginalFrequency);

            public: std::unique_ptr<FractalFormatRawDataContainer> getFractalFormatRawDataContainer();
		};
	}
}

#endif
