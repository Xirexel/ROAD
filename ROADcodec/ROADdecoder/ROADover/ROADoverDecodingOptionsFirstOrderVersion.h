#ifndef ROADOVERDECODINGOPTIONSFIRSTVERSION_H
#define ROADOVERDECODINGOPTIONSFIRSTVERSION_H


#include <list>


#include "ChannelsMixingMode.h"
#include "IROADoverDecodingOptionsMainVersion.h"
#include "ROADRawDataFormat.h"
#include "ROADRawMetaDataContainer.h"



#include "roadover_global.h"

namespace ROADdecoder
{
    namespace Driver
    {
        class IDataReadDriver;
    }
}


namespace ROADdecoder
{
    namespace ROADover
    {
        class ROADOVERSHARED_EXPORT ROADoverDecodingOptionsFirstOrderVersion: public ROADdecoder::ROADover::IROADoverDecodingOptionsMainVersion
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
            private: ROADByte _bitsPerSampleCodeValue;
            private: ROADUInt16 _selectedPreListeningChannel;
            private: ROADUInt8 _endianType;
            private: ROADInt8 _constantScale;
            private: ROADUInt32 _originalFrequency;
            private: ROADUInt64 _amountOfSamples;

            public: ROADoverDecodingOptionsFirstOrderVersion(std::list<ROADRawMetaDataContainer> &aListROADRawMetaDataContainer);

            public: virtual ~ROADoverDecodingOptionsFirstOrderVersion();

            public: virtual ROADUInt32 getROADFormatMode();

            public: virtual ROADUInt32 getOrder();

            public: virtual ROADUInt32 getFrameSampleLength();

            public: virtual ROADUInt32 getMaxSuperFrameLength();

            public: virtual ROADUInt32 getMaxFrameRangLength();

            public: ROADUInt8 getRangSampleLengthPowerOfTwoScale();

            public: ROADUInt32 getOriginalMinSamplesPerRang();

            public: virtual ROADUInt32 getMinSamplesPerRang();

            public: ROADUInt32 getInitRangSampleLength();

            public: ROADUInt8 getAmountRangLevels();

            public: ROADByte getDomainShift();

            public: ROADByte getMixingChannelsMode();

            public: ROADUInt16 getAmountOfChannels();

            public: ROADUInt32 getEncryptionFormat();

            public: ROADRawDataFormat getBitsPerSampleCode();

            public: ROADUInt16 getSelectedPreListeningChannel();

            public: ROADUInt8 getEndianType();

            public: ROADInt8 getConstantScale();

            public: ROADUInt32 getOriginalFrequency();

            public: void setFrequencyScale(ROADUInt32 aValue);

            protected: void readROADINFO(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver);

            protected: void readDATAINFO(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver);

            protected: void checkBitsPerSampleCode();

        };
    }
}

#endif // ROADOVERDECODINGOPTIONSFIRSTVERSION_H
