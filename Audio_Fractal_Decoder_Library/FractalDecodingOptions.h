#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FractalDecodingOptions_h__
#define __FractalDecodingOptions_h__

#include "MixingChannelMode.h"

#include "audio_fractal_decoder_library_global.h"

namespace FractalDecoding
{
	// enum MixingChannelMode;
	class FractalDecodingOptions;
}

namespace FractalDecoding
{
    class AUDIO_FRACTAL_DECODER_LIBRARYSHARED_EXPORT FractalDecodingOptions
	{
		private: FractalDecoding::MixingChannelMode _mixingChannelMode;
		private: unsigned int _frameLength;
		private: unsigned int _samplesPerRang;
		private: unsigned int _superFrameLength;
		private: unsigned int _amountOfChannels;
		private: unsigned int _relativeDomainShift;
		private: unsigned int _scaleDomainShift;

		public: void setMixingChannelMode(FractalDecoding::MixingChannelMode aMixingChannelMode);

		public: FractalDecoding::MixingChannelMode getMixingChannelMode();

		public: void setFrameLength(unsigned int aFrameLength);

		public: unsigned int getFrameLength();

		public: void setSamplesPerRang(unsigned int aSamplesPerRang);

		public: unsigned int getSamplesPerRang();

		public: void setSuperFrameLength(unsigned int aSuperFrameLength);

		public: unsigned int getSuperFrameLength();

		public: void setAmountOfChannels(unsigned int aAmountOfChannels);

		public: unsigned int getAmountOfChannels();

		public: void setRelativeDomainShift(unsigned int aRelativeDomainShift);

		public: unsigned int getRelativeDomainShift();

		public: void setScaleDomainShift(unsigned int aScaleDomainShift);

		public: unsigned int getScaleDomainShift();
	};
}

#endif
