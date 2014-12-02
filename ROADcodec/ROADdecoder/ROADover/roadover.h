#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__ROADover_h__
#define __ROADdecoder__ROADover__ROADover_h__

// #include "ROADdecoder/ROADover/IChannelsMixing.h"
// #include "ROADdecoder/ROADover/IROADoverManager.h"
// #include "ROADdecoder/ROADover/IRawDataBuffer.h"
// #include "ROADdecoder/ROADover/IROADoverDecodingOptions.h"
#include "Result.h"
#include "roadover_global.h"

namespace ROADdecoder
{
	namespace ROADover
    {
		class IROADoverManager;
		class IRawDataBuffer;
		class IROADoverDecodingOptions;
		// enum Result;
		class ROADover;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
        class ROADOVERSHARED_EXPORT ROADover
        {
			private: ROADdecoder::ROADover::IROADoverManager* _manager;
            private: unsigned int _amountOfChannels;
            private: unsigned int _superframeLength;
            private: unsigned int _frameRangLength;
            private: unsigned int _samplesPerRang;



            public: virtual int readROADdata(unsigned char* aData) = 0;

            public: virtual int readPreListening(unsigned char* aData) = 0;

            public: virtual void convertByteArrayIntoDoubleArray(const unsigned char* aByteData, unsigned int aLengthByteArray, double* aDoubleData) = 0;

            public: virtual void writeRawData(ROADdecoder::ROADover::IRawDataBuffer* aRawDataBuffer) = 0;

            public: virtual bool lockResource() = 0;

            public: virtual bool unlockResource() = 0;

			public: ROADover(ROADdecoder::ROADover::IROADoverDecodingOptions* aOptions);

			public: ROADdecoder::ROADover::Result decode();

            public: virtual ~ROADover();

            public: unsigned int getAmountOfChannels();

            protected: unsigned int getSuperframeLength();

            protected: unsigned int getFrameRangLength();

            protected: unsigned int getSamplesPerRang();



		};
	}
}

#endif
