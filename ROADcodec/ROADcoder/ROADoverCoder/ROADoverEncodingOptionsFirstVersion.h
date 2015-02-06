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
			private: unsigned int _frameSampleLength;
			private: unsigned int _superFrameLength;
            private: unsigned int _rangSampleLength;
			private: unsigned int _amountRangLevels;
			private: unsigned int _domainShift;
			private: double _silenceThreshold;
			private: double _rangThreshold;
			private: ROADcoder::ROADoverCoder::ChannelsMixingMode _mixingChannelsMode;
			private: unsigned int _amountOfChannels;
			private: unsigned int _encryptionFormat;
			private: int _bitsPerSample;
			private: int _selectedPreListeningChannel;
            private: unsigned char _endianType;

            public: virtual unsigned char getROADFormatMode();

            public: std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> clone();

            public: ROADoverEncodingOptionsFirstVersion();

            public: virtual ~ROADoverEncodingOptionsFirstVersion();

			public: void setFrameSampleLength(unsigned int aFrameSampleLength);

			public: unsigned int getFrameSampleLength();

			public: void setSuperFrameLength(unsigned int aSuperFrameLength);

			public: unsigned int getSuperFrameLength();

            public: void setRangSampleLength(unsigned int aRangSampleLength);

            public: unsigned int getRangSampleLength();

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

            public: void setBitsPerSample( int aBitsPerSample);

			public: int getBitsPerSample();

			public: void setSelectedPreListeningChannel(int aSelectedPreListeningChannel);

			public: int getSelectedPreListeningChannel();

            public: unsigned int getEndianType();

            public: void setEndianType(unsigned int aEndianType);

            public: std::unique_ptr<FractalFormatRawDataContainer> getFractalFormatRawDataContainer();
		};
	}
}

#endif
