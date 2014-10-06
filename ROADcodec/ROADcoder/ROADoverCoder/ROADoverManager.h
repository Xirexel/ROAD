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
		class ROADoverManager: public ROADcoder::ROADoverCoder::IROADoverManager
		{
            protected: ROADcoder::ROADoverCoder::ROADover* _roadOver;
            protected: ROADcoder::ROADoverCoder::RawDataBuffer _channelsDataBuffer;
            protected: std::unique_ptr<ROADcoder::ROADoverCoder::IChannelsMixing> _channelsMixing;
			protected: unsigned int _superFrameSamplesLength;
			protected: unsigned int _superFrameLength;
			protected: unsigned int _frameRangLength;
            protected: unsigned int _rangSampleLength;
            protected: unsigned int _bitsPerSample;
            protected: std::unique_ptr<unsigned char> _bufferROADdata;

            public: ROADoverManager(ROADcoder::ROADoverCoder::ROADover* aRoadOver, unsigned int aAmountOfChannels, unsigned int aSuperFrameLength, unsigned int aFrameRangLength, unsigned int aSuperFrameSamplesLength);

            public: unsigned int getRangSampleLength();

            public: unsigned int getBitsPerSample();

            public: virtual ~ROADoverManager(){}
		};
	}
}

#endif
