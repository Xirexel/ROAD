#ifndef __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsFirstVersion_h__
#define __ROADcoder__ROADoverCoder__ROADoverEncodingOptionsFirstVersion_h__

#include <list>


#include "ChannelsMixingMode.h"
#include "IROADoverEncodingOptions.h"
#include "FractalFormatRawDataContainer.h"
#include "ROADSeekPoint.h"
//#include "IDataWriteDriver.h"

#include "roadovercoder_global.h"

namespace ROADcoder
{
    namespace Driver
    {
        class IDataWriteDriver;
    }
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
        class ROADOVERCODERSHARED_EXPORT ROADoverEncodingOptionsFirstVersion: public ROADcoder::ROADoverCoder::IROADoverEncodingOptions
        {
            private: ROADUInt8 _maxSuperFrameLength;
            private: ROADUInt8 _rangSampleLengthPowerOfTwoScale;
            private: ROADUInt8 _amountRangLevels;
            private: ROADByte _domainShift;
            private: ROADReal _silenceThreshold;
            private: ROADReal _rangThreshold;
            private: ROADByte _mixingChannelsMode;
            private: ROADUInt16 _amountOfChannels;
            private: ROADUInt32 _encryptionFormat;
            private: ROADRawDataFormat _bitsPerSampleCode;
            private: ROADUInt16 _selectedPreListeningChannel;
            private: ROADUInt8 _endianType;
            private: ROADInt8 _constantScale;
            private: ROADUInt32 _originalFrequency;

            public: virtual ROADByte getROADFormatMode();

            public: std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> clone();

            public: ROADoverEncodingOptionsFirstVersion();

            public: virtual ~ROADoverEncodingOptionsFirstVersion();

            public: ROADUInt32 getFrameSampleLength();

            public: void setMaxSuperFrameLength(ROADUInt8 aSuperFrameLength);

            public: ROADUInt8 getMaxSuperFrameLength();

            public: void setRangSampleLengthPowerOfTwoScale(ROADUInt8 aRangSampleLength);

            public: ROADUInt8 getRangSampleLengthPowerOfTwoScale();

            public: ROADUInt32 getRangSampleLength();

            public: ROADUInt32 getInitRangSampleLength();

            public: void setAmountRangLevels(ROADUInt8 aAmountRangLevels);

            public: ROADUInt8 getAmountRangLevels();

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

            public: void setBitsPerSampleCode(ROADRawDataFormat aBitsPerSampleCode);

            public: ROADRawDataFormat getBitsPerSampleCode();

            public: void setSelectedPreListeningChannel(ROADUInt16 aSelectedPreListeningChannel);

            public: ROADUInt16 getSelectedPreListeningChannel();

            public: ROADUInt8 getEndianType();

            public: void setEndianType(ROADUInt8 aEndianType);

            public: ROADInt8 getConstantScale();

            public: void setConstantScale(ROADInt8 aConstantScale);

            public: ROADUInt32 getOriginalFrequency();

            public: void setOriginalFrequency(ROADUInt32 aOriginalFrequency);

            public: Unique_ptr<FractalFormatRawDataContainer> getFractalFormatRawDataContainer(std::list<ROADSeekPoint> &aSeekPoints);

            public: Unique_ptr<FractalFormatRawDataContainer> getFractalFormatRawDataContainer();

            protected: void writeROADINFO(ROADcoder::Driver::IDataWriteDriver *aIDataWriteDriver);

            protected: void writeSEEKTABLE(ROADcoder::Driver::IDataWriteDriver *aIDataWriteDriver, std::list<ROADSeekPoint> &aSeekPoints);

            protected: void writeDATAINFO(ROADcoder::Driver::IDataWriteDriver *aIDataWriteDriver);
		};
	}
}

#endif
