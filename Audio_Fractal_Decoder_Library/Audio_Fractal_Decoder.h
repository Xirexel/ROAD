#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __Audio_Fractal_Decoder_h__
#define __Audio_Fractal_Decoder_h__

// #include "IMixing.h"
// #include "IRawDataReader.h"
// #include "IRawDataWriter.h"
#include "DataBuffer.h"
#include "FractalDecoder.h"
#include "FractalDataContainer.h"
#include "ReadResult.h"
#include "FractalDecodingOptions.h"

#include "audio_fractal_decoder_library_global.h"

namespace FractalDecoding
{
	class IMixing;
	class IRawDataReader;
	class IRawDataWriter;
	class DataBuffer;
	class FractalDecoder;
	class FractalDataContainer;
	// enum ReadResult;
	class FractalDecodingOptions;
	class Audio_Fractal_Decoder;
}

namespace FractalDecoding
{

    class AUDIO_FRACTAL_DECODER_LIBRARYSHARED_EXPORT Audio_Fractal_Decoder
	{
		public: FractalDecoding::IMixing* _mixingChannels;
		public: FractalDecoding::IRawDataReader* _reader;
		public: FractalDecoding::IRawDataWriter* _writer;
		private: FractalDecoding::DataBuffer _dataBuffer;
		private: FractalDecoding::FractalDecoder _firstChannelFractalDecoder;
		private: FractalDecoding::FractalDecoder _secondChannelFractalDecoder;
		private: FractalDecoding::FractalDataContainer _firstChannelFractalDataCollection;
		private: FractalDecoding::FractalDataContainer _secondChannelFractalDataCollection;

		public: FractalDecoding::ReadResult doDecoding();

		public: Audio_Fractal_Decoder(FractalDecoding::IRawDataReader* aReader, FractalDecoding::IRawDataWriter* aWriter, FractalDecoding::FractalDecodingOptions aOptions);

        public: virtual ~Audio_Fractal_Decoder();
	};
}

#endif
