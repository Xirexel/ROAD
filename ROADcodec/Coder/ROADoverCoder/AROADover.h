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
#include "FormatContainer.h"

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
    class FormatContainer;
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
        private: ROADoverEncoding::FormatContainer _formatContainer;

        protected: virtual ROADoverEncoding::Result readRawData(ROADoverEncoding::IRawDataBuffer* aBuffer) = 0;

        protected: virtual unsigned int convertDoubleArrayToByteArray(double* aDoubleData, unsigned int aLength, char* aByteData) = 0;

        protected: virtual void writePrelistening(double* aData, unsigned int aLength) = 0;

        protected: virtual void writeROADdata(char* aData, unsigned int aLength, unsigned int aPrelisteningCRC, unsigned int aROADdataCRC) = 0;

		public: ROADoverEncoding::Result doOneStepEncoding();

        public: ROADoverEncoding::ICharDataContainer* getFormatICharDataContainer();

		public: AROADover(ROADoverEncoding::ROADoverEncodingOptions aOptions);

        public: virtual ~AROADover();
	};
}

#endif
