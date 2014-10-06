#include <string>
#include <vector>
#include <exception>
#include <cstring>
using namespace std;

#include "ROADoverManager.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "NoneChannelsMixing.h"


ROADdecoder::ROADover::ROADoverManager::ROADoverManager(ROADdecoder::ROADover::ROADover* aRoadOver,
                                                        unsigned int aAmountOfChannels,
                                                        unsigned int aSampleLength,
                                                        unsigned int aSuperFrameLength,
                                                        unsigned int aFrameRangLength,
                                                        unsigned int aSuperFrameSamplesLength)
    : _channelsMixing(new NoneChannelsMixing),
      _roadOver(aRoadOver),
      _channelsDataBuffer(RawDataBuffer(aAmountOfChannels, aSuperFrameSamplesLength)),
      _bufferROADdata(new unsigned char[aAmountOfChannels * aSampleLength * aSuperFrameSamplesLength]),
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
