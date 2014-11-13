#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverManager.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"


ROADdecoder::ROADover::ROADoverManager::ROADoverManager(ROADdecoder::ROADover::ROADover* aRoadOver, ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental* aOptions)
    : _roadOver(aRoadOver),
      _channelsDataBuffer(RawDataBuffer(aOptions->getAmountOfChannels(),
                                              aOptions->getSamplesPerRang() *
                                              aOptions->getFrameRangLength() *
                                              aOptions->getSuperframeLength()))
{
}

ROADdecoder::ROADover::ROADoverManager::~ROADoverManager()
{

}
