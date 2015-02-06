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
            private: unsigned char _superFrameLength;
            private: unsigned char _powerRangSampleLength;
            private: unsigned char _amountRangLevels;
            private: unsigned char _domainShift;
			private: double _silenceThreshold;
			private: double _rangThreshold;
            private: unsigned char _mixingChannelsMode;
            private: unsigned short _amountOfChannels;
			private: unsigned int _encryptionFormat;
            private: unsigned char _bitsPerSample;
            private: unsigned short _selectedPreListeningChannel;
            private: unsigned char _endianType;

            public: virtual unsigned char getROADFormatMode();

            public: std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> clone();

            public: ROADoverEncodingOptionsFirstVersion();

            public: virtual ~ROADoverEncodingOptionsFirstVersion();

			public: unsigned int getFrameSampleLength();

            public: void setSuperFrameLength(unsigned char aSuperFrameLength);

            public: unsigned char getSuperFrameLength();

            public: void setPowerRangSampleLength(unsigned char aPowerRangSampleLength);

            public: unsigned char getPowerRangSampleLength();

            public: void setAmountRangLevels(unsigned char aAmountRangLevels);

            public: unsigned char getAmountRangLevels();

            public: void setDomainShift(unsigned char aDomainShift);

            public: unsigned char getDomainShift();

			public: void setSilenceThreshold(double aSilenceThreshold);

			public: double getSilenceThreshold();

			public: void setRangThreshold(double aRangThreshold);

			public: double getRangThreshold();

            public: void setMixingChannelsMode(unsigned char aMixingChannelsMode);

            public: unsigned char getMixingChannelsMode();

            public: void setAmountOfChannels(unsigned short aAmountOfChannels);

            public: unsigned short getAmountOfChannels();

			public: void setEncryptionFormat(unsigned int aEncryptionFormat);

			public: unsigned int getEncryptionFormat();

            public: void setBitsPerSample( unsigned char aBitsPerSample);

            public: unsigned char getBitsPerSample();

            public: void setSelectedPreListeningChannel(unsigned short aSelectedPreListeningChannel);

            public: unsigned short getSelectedPreListeningChannel();

            public: unsigned int getEndianType();

            public: void setEndianType(unsigned int aEndianType);

            public: std::unique_ptr<FractalFormatRawDataContainer> getFractalFormatRawDataContainer();
		};
	}
}

#endif
