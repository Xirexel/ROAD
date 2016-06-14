#ifndef __ROADcoder__ROADoverCoder__ROADover_h__
#define __ROADcoder__ROADoverCoder__ROADover_h__

#include <memory>

#include "memorydefine.h"
#include "roadovercoder_global.h"
#include "Result.h"
#include "RawDataBuffer.h"
#include "IROADoverManager.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IROADoverManager;
		class IROADoverEncodingOptions;
		class ROADover;        
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;
        class ROADOVERCODERSHARED_EXPORT ROADover
		{
            private: Unique_ptr<ROADcoder::ROADoverCoder::IROADoverManager> _manager;

            public: ROADUInt32 getRangSampleLength();

            public: ROADUInt32 getBitsPerSample();

            public: std::tuple<PtrROADByte, ROADUInt32> getFractalFormatRawData();

            public: virtual ROADBool lockResource() = 0;

            public: virtual ROADBool unlockResource() = 0;

            public: virtual ROADcoder::ROADoverCoder::Result readRawData(ROADcoder::ROADoverCoder::RawDataBuffer &aRawDataBuffer) = 0;

            public: virtual ROADUInt32 convertDoubleArrayIntoByteArray(const PtrROADReal aDoubleData, ROADUInt32 aLengthDoubleArray, PtrROADByte aByteData) = 0;

            public: virtual ROADUInt32 writePreListening(PtrROADReal aDoubleData, ROADUInt32 aLength) = 0;

            public: virtual void writeROADdata(PtrROADByte aByteData, ROADUInt32 aLength) = 0;

            public: ROADcoder::ROADoverCoder::Result doOneStepEncoding();

            public: virtual ~ROADover();

            public: ROADover(Unique_ptr<IROADoverEncodingOptions> &aOptions);
		};
	}
}

#endif
