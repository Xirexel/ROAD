#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FractalEncodingOptions_h__
#define __FractalEncodingOptions_h__

#include "MixingChannelsMode.h"

#include "audio_fractal_encoder_library_global.h"

namespace FractalEncoding
{
	// enum MixingChannelsMode;
	class FractalEncodingOptions;
}

namespace FractalEncoding
{
    class AUDIO_FRACTAL_ENCODER_LIBRARYSHARED_EXPORT FractalEncodingOptions
	{
		private: unsigned int _frameSampleLength;
		private: unsigned int _superFrameLength;
		private: unsigned int _rangeTopSampleLength;
		private: unsigned int _amountRangeLevels;
		private: unsigned int _domainShift;
		private: FractalEncoding::MixingChannelsMode _mixingChannelsMode;
		private: double _silenceThreshold;
		private: double _rangeThreshold;

		public: void setFrameSampleLength(unsigned int aFrameSampleLength);

		public: unsigned int getFrameSampleLength();

		public: void setSuperFrameLength(unsigned int aSuperFrameLength);

		public: unsigned int getSuperFrameLength();

		public: void setRangeTopSampleLength(unsigned int aRangeTopSampleLength);

		public: unsigned int getRangeTopSampleLength();

		public: void setAmountRangeLevels(unsigned int aAmountRangeLevels);

		public: unsigned int getAmountRangeLevels();

		public: void setDomainShift(unsigned int aDomainShift);

		public: unsigned int getDomainShift();

		public: void setMixingChannelsMode(FractalEncoding::MixingChannelsMode aMixingChannelsMode);

		public: FractalEncoding::MixingChannelsMode getMixingChannelsMode();

		public: void setSilenceThreshold(double aSilenceThreshold);

		public: double getSilenceThreshold();

		public: void setRangeThreshold(double aRangeThreshold);

		public: double getRangeThreshold();
	};
}

#endif
