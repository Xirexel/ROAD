#include "ROADoverManager.h"
#include "ROADover.h"
#include "RawDataBuffer.h"

ROADcoder::ROADoverCoder::ROADoverManager::ROADoverManager(ROADcoder::ROADoverCoder::ROADover* aRoadOver, ROADUInt32 aAmountOfChannels, ROADUInt32 aSuperFrameLength, ROADUInt32 aFrameRangLength, ROADUInt32 aSuperFrameSamplesLength)
    : _roadOver(aRoadOver),
      _channelsDataBuffer(RawDataBuffer(aAmountOfChannels, aSuperFrameSamplesLength)),
      _superFrameSamplesLength(aSuperFrameSamplesLength),
      _superFrameLength(aSuperFrameLength),
      _frameRangLength(aFrameRangLength)
{
}



PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverManager::getRangSampleLength()
{
    return this->_rangSampleLength;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverManager::getBitsPerSample()
{
    return this->_bitsPerSample;
}
