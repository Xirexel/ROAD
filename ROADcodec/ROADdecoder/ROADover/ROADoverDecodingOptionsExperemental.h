#include <string>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

#ifndef __ROADdecoder__ROADover__ROADoverDecodingOptionsExperemental_h__
#define __ROADdecoder__ROADover__ROADoverDecodingOptionsExperemental_h__

#include "ChannelsMixingMode.h"
#include "IROADoverDecodingOptions.h"
#include "IDataReadDriver.h"
#include "roadover_global.h"
namespace ROADdecoder
{
	namespace ROADover
	{
		// enum ROADFormatMode;
		// enum ChannelsMixingMode;
		class IROADoverDecodingOptions;
		class ROADoverDecodingOptionsExperemental;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
        class ROADOVERSHARED_EXPORT ROADoverDecodingOptionsExperemental: public ROADdecoder::ROADover::IROADoverDecodingOptions
		{
            private: ROADdecoder::ROADover::ROADFormatMode _formatMode;
            private: ROADdecoder::ROADover::ChannelsMixingMode _channelsMixingMode;
            private: unsigned int _amountOfChannels;
			private: unsigned int _superframeLength;
            private: unsigned int _frameRangLength;
			private: unsigned int _samplesPerRang;
			private: unsigned int _relativeDomainShift;
            private: unsigned int _scaleDomainShift;
            private: unsigned int _encriptionCode;
            private: unsigned int _originalBitsPerSample;

            public: unsigned int getROADFormatMode();

            public: ROADoverDecodingOptionsExperemental(Driver::IDataReadDriver *aPtrIDataReadDriver);

            public: virtual ~ROADoverDecodingOptionsExperemental();

			public: unsigned int getAmountOfChannels();

			public: unsigned int getSuperframeLength();

			public: ROADdecoder::ROADover::ChannelsMixingMode getChannelsMixingMode();

            public: unsigned int getFrameRangLength();

			public: unsigned int getSamplesPerRang();

			public: unsigned int getRelativeDomainShift();

			public: unsigned int getScaleDomainShift();

			public: unsigned int getOriginalSamplesPerRang();

            public: void setSamplesPerRang(unsigned int aValue);

            public: void setOriginalBitsPerSample( unsigned int aValue);

            public: unsigned int getOriginalBitsPerSample();

            public: unsigned int getEncriptionCode();
		};
	}
}

#endif
