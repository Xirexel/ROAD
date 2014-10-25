#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADoverEncodingOptions_h__
#define __ROADoverEncodingOptions_h__

#include "MixingChannelsMode.h"
#include "ROADFormat.h"

namespace ROADoverEncoding
{
	// enum MixingChannelsMode;
	// enum ROADFormat;
	class ROADoverEncodingOptions;
}

namespace ROADoverEncoding
{
	class ROADoverEncodingOptions
	{
		private: ROADoverEncoding::MixingChannelsMode _mixingChannelsMode;
		private: unsigned int _channels;
		private: unsigned int _superframeLength;
		private: unsigned int _frameSampleLength;
		private: unsigned int _bitsPerSample;
		private: ROADoverEncoding::ROADFormat _format;
		private: unsigned int _shortestRangSampleLength;
		private: unsigned int _longestRangSampleLength;
		private: unsigned int _domainShift;
		private: unsigned int _encryptionFromat;

		public: void setMixingChannelsMode(ROADoverEncoding::MixingChannelsMode aMixingChannelsMode);

		public: ROADoverEncoding::MixingChannelsMode getMixingChannelsMode();

		public: void setChannels(unsigned int aChannels);

		public: unsigned int getChannels();

		public: void setSuperframeLength(unsigned int aSuperframeLength);

		public: unsigned int getSuperframeLength();

		public: void setFrameSampleLength(unsigned int aFrameSampleLength);

		public: unsigned int getFrameSampleLength();

		public: void setBitsPerSample(unsigned int aBitsPerSample);

		public: unsigned int getBitsPerSample();

		public: void setFormat(ROADoverEncoding::ROADFormat aFormat);

		public: ROADoverEncoding::ROADFormat getFormat();

		public: void setShortestRangSampleLength(unsigned int aShortestRangSampleLength);

		public: unsigned int getShortestRangSampleLength();

		public: void setLongestRangSampleLength(unsigned int aLongestRangSampleLength);

		public: unsigned int getLongestRangSampleLength();

		public: void setDomainShift(unsigned int aDomainShift);

		public: unsigned int getDomainShift();

		public: void setEncryptionFromat(unsigned int aEncryptionFromat);

		public: unsigned int getEncryptionFromat();
	};
}

#endif
