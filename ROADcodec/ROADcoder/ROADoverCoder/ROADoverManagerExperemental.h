#ifndef __ROADcoder__ROADoverCoder__ROADoverManagerExperemental_h__
#define __ROADcoder__ROADoverCoder__ROADoverManagerExperemental_h__

#include <vector>
#include <memory>


#include "Result.h"
#include "ROADoverManager.h"
#include "FractalFormatRawDataContainer.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IROADFractalFirstOrderAnalyzer;
	}
	namespace ROADoverCoder
	{
		class IROADoverEncodingOptions;
        class FractalFirstOrderItemSuperFrameContainer;
		class ROADover;
        class ROADoverEncodingOptionsExperemental;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;
		class ROADoverManagerExperemental: public ROADcoder::ROADoverCoder::ROADoverManager
		{
            private: std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental> _options;
            private: std::unique_ptr<ROADcoder::ROADCoder::IROADFractalFirstOrderAnalyzer> _analyzer;
            private: std::vector<ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer*> _fractalItemSuperFrameContainer;
            private: std::unique_ptr<ROADcoder::ROADoverCoder::FractalFormatRawDataContainer> _fractalFormatRawDataContainer;

			public: ROADcoder::ROADoverCoder::Result encode();

            public: std::tuple<PtrROADByte, ROADUInt32> getFractalFormatRawData();

			public: ROADoverManagerExperemental(ROADcoder::ROADoverCoder::ROADover* aRoadOver, ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental* aOptions);

            public: virtual ~ROADoverManagerExperemental();
		};
	}
}

#endif
