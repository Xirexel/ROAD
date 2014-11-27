#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverManager.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"


ROADdecoder::ROADover::ROADoverManager::ROADoverManager(ROADdecoder::ROADover::ROADover* aRoadOver,
                                                        unsigned int aCount,
                                                        unsigned int aSampleLength,
                                                        unsigned int aSuperFrameLength)
    : _roadOver(aRoadOver),
      _channelsDataBuffer(RawDataBuffer(aCount, aSuperFrameLength)),
      _bufferROADdata(new unsigned char[aCount * aSampleLength * aSuperFrameLength])
{
}

ROADdecoder::ROADover::ROADoverManager::~ROADoverManager()
{
    delete this->_bufferROADdata;
}
