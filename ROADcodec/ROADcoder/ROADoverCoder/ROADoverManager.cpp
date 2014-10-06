#include "ROADoverManager.h"
#include "ROADover.h"
#include "RawDataBuffer.h"

ROADcoder::ROADoverCoder::ROADoverManager::ROADoverManager(ROADcoder::ROADoverCoder::ROADover* aRoadOver, unsigned int aAmountOfChannels, unsigned int aSuperFrameLength, unsigned int aFrameRangLength, unsigned int aSuperFrameSamplesLength)
    : _roadOver(aRoadOver),
      _channelsDataBuffer(RawDataBuffer(aAmountOfChannels, aSuperFrameSamplesLength)),
      _superFrameSamplesLength(aSuperFrameSamplesLength),
      _superFrameLength(aSuperFrameLength),
      _frameRangLength(aFrameRangLength)
{
}



unsigned int ROADcoder::ROADoverCoder::ROADoverManager::getRangSampleLength()
{
    return this->_rangSampleLength;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverManager::getBitsPerSample()
{
    return this->_bitsPerSample;
}
