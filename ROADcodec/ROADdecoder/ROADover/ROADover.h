#ifndef __ROADdecoder__ROADover__ROADover_h__
#define __ROADdecoder__ROADover__ROADover_h__

#include <memory>

#include "Result.h"
#include "roadover_global.h"
#include "platformdependencies.h"
#include "EndianType.h"

namespace ROADdecoder
{
	namespace ROADover
    {
		class IROADoverManager;
		class IRawDataBuffer;
		class IROADoverDecodingOptions;
		class ROADover;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
    using namespace PlatformDependencies;
        class ROADOVERSHARED_EXPORT ROADover
        {
            private: std::unique_ptr<ROADdecoder::ROADover::IROADoverManager> _manager;
            private: ROADUInt32 _amountOfChannels;
            private: ROADUInt32 _superframeLength;
            private: ROADUInt32 _frameRangLength;
            private: ROADUInt32 _samplesPerRang;



            public: virtual ROADInt32 readROADdata(PtrROADByte aData) = 0;

            public: virtual ROADInt32 readPreListening(PtrROADByte aData, ROADUInt32 aCRC32) = 0;

            public: virtual void convertByteArrayIntoDoubleArray(PtrROADByte aByteData, ROADUInt32 aLengthByteArray, PtrROADReal aDoubleData) = 0;

            public: virtual void writeRawData(ROADdecoder::ROADover::IRawDataBuffer* aRawDataBuffer) = 0;

            public: virtual ROADBool lockResource() = 0;

            public: virtual ROADBool unlockResource() = 0;

            public: ROADover(ROADdecoder::ROADover::IROADoverDecodingOptions* aOptions, Endian::EndianType aLowFormatEndianType);

			public: ROADdecoder::ROADover::Result decode();

            public: virtual ~ROADover();

            public: ROADUInt32 getAmountOfChannels();

            protected: ROADUInt32 getSuperframeLength();

            protected: ROADUInt32 getFrameRangLength();

            protected: ROADUInt32 getSamplesPerRang();

		};
	}
}

#endif
