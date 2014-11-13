#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__ROADoverDecodingOptionsExperemental_h__
#define __ROADdecoder__ROADover__ROADoverDecodingOptionsExperemental_h__

#include "ROADFormatMode.h"
#include "ChannelsMixingMode.h"
#include "IROADoverDecodingOptions.h"

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
		class ROADoverDecodingOptionsExperemental: public ROADdecoder::ROADover::IROADoverDecodingOptions
		{
			public: ROADdecoder::ROADover::ROADFormatMode _formatMode;
			public: ROADdecoder::ROADover::ChannelsMixingMode _channelsMixingMode;
			private: unsigned int _channels;
			private: unsigned int _superframeLength;
			private: unsigned int _frameRangLength;
			private: unsigned int _bitsPerSample;
			private: unsigned int _samplesPerRang;
			private: unsigned int _relativeDomainShift;
			private: unsigned int _scaleDomainShift;

			public: ROADdecoder::ROADover::ROADFormatMode getROADFormatMode();

            public: ROADoverDecodingOptionsExperemental(unsigned char *byteArray, unsigned int aLength);

			public: unsigned int getAmountOfChannels();

			public: unsigned int getSuperframeLength();

			public: ROADdecoder::ROADover::ChannelsMixingMode getChannelsMixingMode();

			public: unsigned int getFrameRangLength();

			public: unsigned int getBitsPerSample();

			public: unsigned int getSamplesPerRang();

			public: unsigned int getRelativeDomainShift();

			public: unsigned int getScaleDomainShift();
		};
	}
}

#endif
