#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __Audio_Fractal_Encoder_h__
#define __Audio_Fractal_Encoder_h__

// #include "IRawDataReader.h"
// #include "IRawDataWriter.h"
// #include "IMixingChannels.h"
#include "DataBuffer.h"
#include "FractalEncoder.h"
#include "FractalEncodingOptions.h"
#include "ReadResult.h"

#include "audio_fractal_encoder_library_global.h"

namespace FractalEncoding
{
	class IRawDataReader;
	class IRawDataWriter;
	class IMixingChannels;
	class DataBuffer;
	class FractalEncoder;
	class FractalEncodingOptions;
	// enum ReadResult;
	class Audio_Fractal_Encoder;
}

namespace FractalEncoding
{

    class AUDIO_FRACTAL_ENCODER_LIBRARYSHARED_EXPORT Audio_Fractal_Encoder
	{
		public: FractalEncoding::IRawDataReader* _reader;
		public: FractalEncoding::IRawDataWriter* _writer;
		public: FractalEncoding::IMixingChannels* _mixingChannels;
		public: FractalEncoding::DataBuffer _buffer;
		public: FractalEncoding::FractalEncoder _firstFractalEncoder;
		public: FractalEncoding::FractalEncoder _secondFractalEncoder;

		public: Audio_Fractal_Encoder(FractalEncoding::IRawDataReader* aReader, FractalEncoding::IRawDataWriter* aWriter, FractalEncoding::FractalEncodingOptions aOptions);

        public: ~Audio_Fractal_Encoder();

		public: FractalEncoding::ReadResult doEncoding();
	};
}

#endif
