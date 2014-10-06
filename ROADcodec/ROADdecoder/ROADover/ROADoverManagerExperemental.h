#include <string>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

#ifndef __ROADdecoder__ROADover__ROADoverManagerExperemental_h__
#define __ROADdecoder__ROADover__ROADoverManagerExperemental_h__

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
		// enum Result;
		class ROADoverManager;
		class ROADoverManagerExperemental;
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

            private: std::unique_ptr<unsigned char> _preListeningData;

            private: std::unique_ptr<double> _preListeningDoubleData;

			public: ROADoverManagerExperemental(ROADdecoder::ROADover::ROADover* aRoadOver, ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental* aOptions);

			public: ROADdecoder::ROADover::Result decode();

            public: virtual ~ROADoverManagerExperemental();
		};
	}
}

#endif
