#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADManager.h"
#include "ROAD_Encoder.h"
#include "ROADDataCollection.h"
#include "ROADoverEncodingOptions.h"
#include "IROADDataCollection.h"
#include "IRawDataBuffer.h"

ROADoverEncoding::ROADManager::ROADManager(ROADoverEncoding::ROADoverEncodingOptions aOptions)
{

    ROADEncoding::ROADEncodingOptions lOptions;

    for(decltype(aOptions.getChannels()) index = 0;
        index < aOptions.getChannels();
        ++index)
    {
        _channelEncoders.push_back(new ROADEncoding::ROAD_Encoder(lOptions));
    }

}

ROADoverEncoding::ROADManager::~ROADManager()
{
    auto begin =_channelEncoders.begin();

    auto end =_channelEncoders.end();

    while(begin != end)
    {
        delete *begin;

        ++begin;
    }

}

ROADoverEncoding::IROADDataCollection* ROADoverEncoding::ROADManager::doEncoding(ROADoverEncoding::IRawDataBuffer* aBuffer) {

    _roadDataCollection.reset();

    unsigned int lCountChannels = aBuffer->getCount();

    for(decltype(lCountChannels) index = 0;
        index < lCountChannels;
        ++index)
    {
        _roadDataCollection.addIROADDataContainer(_channelEncoders.at(index)->doEncoding(aBuffer->getData(index)));
    }

    return &_roadDataCollection;
}

