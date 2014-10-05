#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROAD_Encoder_h__
#define __ROAD_Encoder_h__

// #include "IRawDataReader.h"
// #include "IRawDataWriter.h"
#include "DataBuffer.h"
#include "FractalEncoder.h"
#include "ROADEncodingOptions.h"
#include "ReadResult.h"

namespace ROADEncoding
{
	class IRawDataReader;
	class IRawDataWriter;
	class DataBuffer;
	class FractalEncoder;
	class ROADEncodingOptions;
	// enum ReadResult;
	class ROAD_Encoder;
}

namespace ROADEncoding
{
    class ROADCODERSHARED_EXPORT ROAD_Encoder
	{
		public: ROADEncoding::IRawDataReader* _reader;
		public: ROADEncoding::IRawDataWriter* _writer;
		public: ROADEncoding::DataBuffer _buffer;
        public: ROADEncoding::FractalEncoder _fractalEncoder;

		public: ROAD_Encoder(ROADEncoding::IRawDataReader* aReader, ROADEncoding::IRawDataWriter* aWriter, ROADEncoding::ROADEncodingOptions aOptions);

		public: ROADEncoding::ReadResult doEncoding();
	};
}

#endif
