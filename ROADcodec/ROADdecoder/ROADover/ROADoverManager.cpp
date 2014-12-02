#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverManager.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "../ROAD/ROADFractalBuilderFactory.h"
#include "FractalItemSuperFrameContainer.h"
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
      _fractalBuilder(ROADdecoder::ROAD::ROADFractalBuilderFactory::getIROADFractalBuilder(aSuperFrameSamplesLength))

{
    for(decltype(aAmountOfChannels) index = 0;
        index < aAmountOfChannels;
        ++index)
    {
//        _fractalBuilder.push_back();

        _fractalItemSuperFrameContainer.push_back(new FractalItemSuperFrameContainer(aSuperFrameLength, aFrameRangLength));
    }
}

ROADdecoder::ROADover::ROADoverManager::~ROADoverManager()
{
//    delete this->_bufferROADdata;

//    for(ROADdecoder::ROAD::IROADFractalBuilder* item : _fractalBuilder)
//        delete item;

//    _fractalBuilder.clear();

    for(FractalItemSuperFrameContainer* item : _fractalItemSuperFrameContainer)
        delete item;

    _fractalItemSuperFrameContainer.clear();
}
