#ifndef __ROADdecoder__ROADover__ROADoverManager_h__
#define __ROADdecoder__ROADover__ROADoverManager_h__

#include <memory>
#include <cstring>

#include "RawDataBuffer.h"
#include "NoneChannelsMixing.h"
#include "IROADoverManager.h"


namespace ROADdecoder
{
	namespace ROAD
	{
        class IROADFractalFirstOrderBuilder;
	}
	namespace ROADover
    {
        class ROADover;
        class IROADoverManager;
        class IROADoverDecodingOptions;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
        template<typename ROADDecodedSampleType>
		class ROADoverManager: public ROADdecoder::ROADover::IROADoverManager
		{
            private: typedef ROADDecodedSampleType DecodedSampleType;
            protected: std::unique_ptr<ROADdecoder::ROADover::IChannelsMixing<DecodedSampleType>> _channelsMixing;
            protected: ROADover* _roadOver;
            protected: RawDataBuffer<DecodedSampleType> _channelsDataBuffer;
            protected: std::shared_ptr<ROADByte> _bufferROADdata;
            protected: ROADUInt32 _frequencyScale;
            protected: ROADUInt32 _superFrameSamplesLength;
            protected: ROADUInt32 _superFrameLength;
            protected: ROADUInt32 _frameRangLength;
            private: ROADRawDataFormat _decodedSampleTypeCode;

            public: ROADoverManager(ROADdecoder::ROADover::ROADover* aRoadOver,
                                    ROADUInt32 aAmountOfChannels,
                                    ROADUInt32 aSampleLength,
                                    ROADUInt32 aSuperFrameLength,
                                    ROADUInt32 aFrameRangLength,
                                    ROADUInt32 aSuperFrameSamplesLength)
                : _channelsMixing(new NoneChannelsMixing<DecodedSampleType>()),
                  _roadOver(aRoadOver),
                  _channelsDataBuffer(RawDataBuffer<DecodedSampleType>(aAmountOfChannels, aSuperFrameSamplesLength)),
                  _bufferROADdata(new ROADByte[aAmountOfChannels * aSampleLength * aSuperFrameSamplesLength]),
                  _frequencyScale(1),
                  _superFrameSamplesLength(aSuperFrameSamplesLength),
                  _superFrameLength(aSuperFrameLength),
                  _frameRangLength(aFrameRangLength)

            {
                memset(_bufferROADdata.get(), 0, aAmountOfChannels * aSampleLength * aSuperFrameSamplesLength);
            }

            public: virtual ROADRawDataFormat getDecodedSampleTypeCode()
            {
                return DecodedSampleTypeToROADRawDataFormat<DecodedSampleType>::_code;
            }

            public: virtual ~ROADoverManager(){}
		};
	}
}

#endif
