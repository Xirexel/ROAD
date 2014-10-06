#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __AROADover_h__
#define __AROADover_h__

// #include "IMixingChannels.h"
#include "CRCProcessor.h"
#include "EntropyCompression.h"
// #include "ROADManager.h"
#include "RawDataBuffer.h"
#include "CharDataContainer.h"
#include "Result.h"
#include "IRawDataBuffer.h"
#include "ROADoverEncodingOptions.h"

namespace ROADoverEncoding
{
	class IMixingChannels;
	class CRCProcessor;
	class EntropyCompression;
	class ROADManager;
	class RawDataBuffer;
	class CharDataContainer;
	// enum Result;
	class IRawDataBuffer;
	class ROADoverEncodingOptions;
	class AROADover;
}

namespace ROADoverEncoding
{
	class AROADover
	{
		private: ROADoverEncoding::IMixingChannels* _mixingChannels;
		private: ROADoverEncoding::CRCProcessor _crcProcessor;
		private: ROADoverEncoding::EntropyCompression _entropyCompressor;
		private: ROADoverEncoding::ROADManager* _manager;
		private: ROADoverEncoding::RawDataBuffer _buffer;
		private: ROADoverEncoding::CharDataContainer _rawCharDataContainer;

		public: virtual ROADoverEncoding::Result readRawData(ROADoverEncoding::IRawDataBuffer aBuffer) = 0;

		public: virtual unsigned int convertToByteArray(double* aDoubleData, unsigned int aLength, char* aByteData) = 0;

		public: virtual void writePrelistening(double* aData, unsigned int aLength) = 0;

		public: virtual void writeROADdata(char* aData, unsigned int aLength, unsigned int aPrelisteningCRC, unsigned int aROADdataCRC) = 0;

		public: ROADoverEncoding::Result doOneStepEncoding();

		public: AROADover(ROADoverEncoding::ROADoverEncodingOptions aOptions);
	};
}

#endif
