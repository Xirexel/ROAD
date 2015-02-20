#ifndef __ROADdecoder__ROADover__ROADoverManagerExperemental_h__
#define __ROADdecoder__ROADover__ROADoverManagerExperemental_h__


#include <vector>
#include <memory>
// #include "ROADdecoder/ROADover/ROADover.h"
// #include "ROADdecoder/ROADover/ROADoverDecodingOptionsExperemental.h"
#include "../ROAD/IROADFractalFirstOrderBuilder.h"
#include "Result.h"
#include "ROADoverManager.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class ROADover;
		class ROADoverDecodingOptionsExperemental;
        class FractalFirstOrderItemSuperFrameContainer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class ROADoverManagerExperemental: public ROADdecoder::ROADover::ROADoverManager
		{
            private: std::unique_ptr<ROADdecoder::ROAD::IROADFractalFirstOrderBuilder> _fractalBuilder;
            private: std::vector<ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer*> _fractalItemSuperFrameContainer;

            protected: ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental* _options;

            private: std::unique_ptr<ROADByte> _preListeningData;

            private: std::unique_ptr<ROADReal> _preListeningDoubleData;

			public: ROADoverManagerExperemental(ROADdecoder::ROADover::ROADover* aRoadOver, ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental* aOptions);

			public: ROADdecoder::ROADover::Result decode();

            public: virtual ~ROADoverManagerExperemental();
		};
	}
}

#endif
