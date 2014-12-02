#include <string>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

#ifndef __ROADdecoder__ROADover__ROADoverManagerExperemental_h__
#define __ROADdecoder__ROADover__ROADoverManagerExperemental_h__

// #include "ROADdecoder/ROADover/ROADover.h"
// #include "ROADdecoder/ROADover/ROADoverDecodingOptionsExperemental.h"
#include "Result.h"
#include "ROADoverManager.h"

namespace ROADdecoder
{
	namespace ROADover
	{
		class ROADover;
		class ROADoverDecodingOptionsExperemental;
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
