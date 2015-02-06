#ifndef __ROADcoder__ROADoverCoder__ROADoverManagerFirstVersion_h__
#define __ROADcoder__ROADoverCoder__ROADoverManagerFirstVersion_h__


#include <vector>

#include "IROADFractalFirstOrderAnalyzer.h"
#include "FractalFormatRawDataContainer.h"
#include "FractalFirstOrderItemSuperFrameContainer.h"
#include "ROADoverEncodingOptionsFirstVersion.h"
#include "Result.h"
#include "ROADoverManager.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IROADFractalFirstOrderAnalyzer;
	}
	namespace ROADoverCoder
	{
		class ROADoverEncodingOptionsFirstVersion;
		class FractalFormatRawDataContainer;
		class FractalFirstOrderItemSuperFrameContainer;
		// enum Result;
		class ROADover;
		class ROADoverManager;
		class ROADoverManagerFirstVersion;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class ROADoverManagerFirstVersion: public ROADcoder::ROADoverCoder::ROADoverManager
		{
            private: std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion> _options;
            private: std::unique_ptr<ROADcoder::ROADoverCoder::FractalFormatRawDataContainer> _fractalFormatRawDataContainer;
            public: std::unique_ptr<ROADcoder::ROADCoder::IROADFractalFirstOrderAnalyzer> _analyzer;
			public: std::vector<ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer*> _fractalItemSuperFrameContainer;

			public: ROADcoder::ROADoverCoder::Result encode();

            public: std::tuple<unsigned char *, unsigned int> getFractalFormatRawData();

			public: ROADoverManagerFirstVersion(ROADcoder::ROADoverCoder::ROADover* aRoadOver, ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion* aOptions);

            public: virtual ~ROADoverManagerFirstVersion();
		};
	}
}

#endif
