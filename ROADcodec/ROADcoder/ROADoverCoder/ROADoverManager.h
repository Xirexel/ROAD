#ifndef __ROADcoder__ROADoverCoder__ROADoverManager_h__
#define __ROADcoder__ROADoverCoder__ROADoverManager_h__

#include <memory>


#include "IROADoverManager.h"
#include "RawDataBuffer.h"
#include "IChannelsMixing.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class IROADoverManager;
		class ROADover;
		class ROADoverManager;
        class RawDataBuffer;
        class IChannelsMixing;

    }
}
namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;
		class ROADoverManager: public ROADcoder::ROADoverCoder::IROADoverManager
		{
            protected: ROADcoder::ROADoverCoder::ROADover* _roadOver;
            protected: ROADcoder::ROADoverCoder::RawDataBuffer _channelsDataBuffer;
            protected: std::unique_ptr<ROADcoder::ROADoverCoder::IChannelsMixing> _channelsMixing;
            protected: ROADUInt32 _superFrameSamplesLength;
            protected: ROADUInt32 _superFrameLength;
            protected: ROADUInt32 _frameRangLength;
            protected: ROADUInt32 _rangSampleLength;
            protected: ROADUInt32 _bitsPerSample;
            protected: std::unique_ptr<ROADByte> _bufferROADdata;

            public: ROADoverManager(ROADcoder::ROADoverCoder::ROADover* aRoadOver, ROADUInt32 aAmountOfChannels, ROADUInt32 aSuperFrameLength, ROADUInt32 aFrameRangLength, ROADUInt32 aSuperFrameSamplesLength);

            public: ROADUInt32 getRangSampleLength();

            public: ROADUInt32 getBitsPerSample();

            public: virtual ~ROADoverManager(){}
		};
	}
}

#endif
