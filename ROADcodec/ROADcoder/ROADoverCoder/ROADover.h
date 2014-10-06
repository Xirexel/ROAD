#ifndef __ROADcoder__ROADoverCoder__ROADover_h__
#define __ROADcoder__ROADoverCoder__ROADover_h__

#include <memory>

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
        class ROADOVERCODERSHARED_EXPORT ROADover
		{
            private: std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverManager> _manager;

            public: unsigned int getRangSampleLength();

            public: unsigned int getBitsPerSample();

            public: std::tuple<char *, unsigned int> getFractalFormatRawData();

			public: virtual bool lockResource() = 0;

			public: virtual bool unlockResource() = 0;

            public: virtual ROADcoder::ROADoverCoder::Result readRawData(ROADcoder::ROADoverCoder::RawDataBuffer &aRawDataBuffer) = 0;

            public: virtual unsigned int convertDoubleArrayIntoByteArray(const double* aDoubleData, unsigned int aLengthDoubleArray, unsigned char* aByteData) = 0;

            public: virtual void writePreListening(double *aDoubleData, unsigned int aLength) = 0;

            public: virtual void writeROADdata(unsigned char* aByteData, unsigned int aLength) = 0;

            public: ROADcoder::ROADoverCoder::Result doOneStepEncoding();

            public: virtual ~ROADover();

            public: ROADover(std::unique_ptr<IROADoverEncodingOptions> &aOptions);
		};
	}
}

#endif
