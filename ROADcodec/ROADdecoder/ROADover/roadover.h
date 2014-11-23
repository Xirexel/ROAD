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
		class IChannelsMixing;
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
			private: ROADdecoder::ROADover::IChannelsMixing* _channelsMixing;
			private: ROADdecoder::ROADover::IROADoverManager* _manager;

            protected: virtual unsigned int readROADdata(unsigned char* aData) = 0;

            protected: virtual unsigned int readPreListening(unsigned char* aData) = 0;

			protected: virtual void convertByteArrayIntoDoubleArray(const char* aByteData, unsigned int aLengthByteArray, double* aDoubleData) = 0;

			protected: virtual void writeRawData(ROADdecoder::ROADover::IRawDataBuffer* aRawDataBuffer) = 0;

			protected: virtual bool lockResource() = 0;

			protected: virtual bool unlockResource() = 0;

			public: ROADover(ROADdecoder::ROADover::IROADoverDecodingOptions* aOptions);

			public: ROADdecoder::ROADover::Result decode();
		};
	}
}

#endif
