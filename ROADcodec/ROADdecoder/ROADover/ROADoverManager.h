#include <string>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

#ifndef __ROADdecoder__ROADover__ROADoverManager_h__
#define __ROADdecoder__ROADover__ROADoverManager_h__


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
            protected: std::unique_ptr<unsigned char> _bufferROADdata;
            protected: unsigned int _frequencyScale;
            protected: unsigned int _superFrameSamplesLength;
            protected: unsigned int _superFrameLength;
            protected: unsigned int _frameRangLength;

            public: ROADoverManager(ROADdecoder::ROADover::ROADover* aRoadOver,
                                    unsigned int aAmountOfChannels,
                                    unsigned int aSampleLength,
                                    unsigned int aSuperFrameLength,
                                    unsigned int aFrameRangLength,
                                    unsigned int aSuperFrameSamplesLength);

            public: virtual ~ROADoverManager();
		};
	}
}

#endif