#ifndef __ROADdecoder__ROADover__ROADoverManager_h__
#define __ROADdecoder__ROADover__ROADoverManager_h__

#include <memory>

#include "RawDataBuffer.h"
#include "IROADoverManager.h"


namespace ROADdecoder
{
	namespace ROAD
	{
        class IROADFractalFirstOrderBuilder;
	}
	namespace ROADover
	{
    class IChannelsMixing;
		class ROADover;
        class RawDataBuffer;
		class IROADoverManager;
		class ROADoverManager;
        class IROADoverDecodingOptions;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class ROADoverManager: public ROADdecoder::ROADover::IROADoverManager
		{
            protected: std::unique_ptr<ROADdecoder::ROADover::IChannelsMixing> _channelsMixing;
			protected: ROADdecoder::ROADover::ROADover* _roadOver;
            protected: ROADdecoder::ROADover::RawDataBuffer _channelsDataBuffer;
            protected: std::unique_ptr<ROADByte> _bufferROADdata;
            protected: ROADUInt32 _frequencyScale;
            protected: ROADUInt32 _superFrameSamplesLength;
            protected: ROADUInt32 _superFrameLength;
            protected: ROADUInt32 _frameRangLength;

            public: ROADoverManager(ROADdecoder::ROADover::ROADover* aRoadOver,
                                    ROADUInt32 aAmountOfChannels,
                                    ROADUInt32 aSampleLength,
                                    ROADUInt32 aSuperFrameLength,
                                    ROADUInt32 aFrameRangLength,
                                    ROADUInt32 aSuperFrameSamplesLength);

            public: virtual ~ROADoverManager();
		};
	}
}

#endif
