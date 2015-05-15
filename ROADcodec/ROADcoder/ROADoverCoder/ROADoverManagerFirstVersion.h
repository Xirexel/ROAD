#ifndef __ROADcoder__ROADoverCoder__ROADoverManagerFirstVersion_h__
#define __ROADcoder__ROADoverCoder__ROADoverManagerFirstVersion_h__


#include <vector>
#include <fstream>

#include "IROADFractalFirstOrderAnalyzer.h"
#include "FractalFormatRawDataContainer.h"
#include "FractalFirstOrderItemSuperFrameContainer.h"
#include "ROADoverEncodingOptionsFirstVersion.h"
#include "IDecodedSampleTypeToRawDataSampleType.h"
#include "Result.h"
#include "ROADoverManager.h"
#include "../ROAD/IROADFractalFirstOrderBuilder.h"
#include "../ROAD/ROADFrameDataContainer.h"


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
    using namespace PlatformDependencies;
		class ROADoverManagerFirstVersion: public ROADcoder::ROADoverCoder::ROADoverManager
		{
            template<typename BaseDecodingSampleType>
            class ROADFractalFirstOrderItemsSuperFrameDataContainer
            {
                public: typedef BaseDecodingSampleType DecodingSampleType;

            private: typedef ROADdecoder::ROAD::ROADFractalFirstOrderItemsFrameDataContainer<DecodingSampleType> FrameContainerType;

            private: std::unique_ptr<FrameContainerType> _FrameMassive;

            public: ROADFractalFirstOrderItemsSuperFrameDataContainer(ROADUInt32 aMaxSuperFrameLength,
                                                                      ROADUInt32 aMaxFrameRangLength,
                                                                      ROADUInt32 aMaxRangSampleLength):
                    _FrameMassive(new FrameContainerType[aMaxSuperFrameLength])
                {

                    for(decltype(aMaxSuperFrameLength) lindex = 0;
                        lindex < aMaxSuperFrameLength;
                        ++lindex)
                    {
                        getFrameDataContainer(lindex)->Init(aMaxFrameRangLength,aMaxRangSampleLength);
                    }
                }

            public: FrameContainerType* getFrameDataContainer(ROADUInt32 aIndex)
                {
                    return _FrameMassive.get() + aIndex;
                }

            };

            private: std::unique_ptr<ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion> _options;
            private: std::unique_ptr<ROADcoder::ROADoverCoder::FractalFormatRawDataContainer> _fractalFormatRawDataContainer;
//            private: std::vector<ROADFractalFirstOrderItemsSuperFrameDataContainer<DecodedSampleType>*> _fractalItemSuperFrameContainer;
            public: std::unique_ptr<ROADcoder::ROADCoder::IROADFractalFirstOrderAnalyzer> _analyzer;
            private: std::unique_ptr<ROADdecoder::ROAD::IROADFractalFirstOrderBuilder> _fractalBuilder;
			public: std::vector<ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer*> _fractalItemSuperFrameContainer;
            private: std::unique_ptr<IDecodedSampleTypeToRawDataSampleType> _convertor;

//            std::fstream file;

			public: ROADcoder::ROADoverCoder::Result encode();

            public: std::tuple<PtrROADByte, ROADUInt32> getFractalFormatRawData();

			public: ROADoverManagerFirstVersion(ROADcoder::ROADoverCoder::ROADover* aRoadOver, ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion* aOptions);

            public: virtual ~ROADoverManagerFirstVersion();
		};
	}
}

#endif
