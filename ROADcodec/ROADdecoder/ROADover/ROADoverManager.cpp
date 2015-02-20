#include <cstring>


#include "ROADoverManager.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "NoneChannelsMixing.h"


ROADdecoder::ROADover::ROADoverManager::ROADoverManager(ROADdecoder::ROADover::ROADover* aRoadOver,
                                                        ROADUInt32 aAmountOfChannels,
                                                        ROADUInt32 aSampleLength,
                                                        ROADUInt32 aSuperFrameLength,
                                                        ROADUInt32 aFrameRangLength,
                                                        ROADUInt32 aSuperFrameSamplesLength)
    : _channelsMixing(new NoneChannelsMixing),
      _roadOver(aRoadOver),
      _channelsDataBuffer(RawDataBuffer(aAmountOfChannels, aSuperFrameSamplesLength)),
      _bufferROADdata(new ROADByte[aAmountOfChannels * aSampleLength * aSuperFrameSamplesLength]),
      _frequencyScale(1),
      _superFrameSamplesLength(aSuperFrameSamplesLength),
      _superFrameLength(aSuperFrameLength),
      _frameRangLength(aFrameRangLength)

{


    memset(_bufferROADdata.get(), 0, aAmountOfChannels * aSampleLength * aSuperFrameSamplesLength);
}

ROADdecoder::ROADover::ROADoverManager::~ROADoverManager()
{
}
