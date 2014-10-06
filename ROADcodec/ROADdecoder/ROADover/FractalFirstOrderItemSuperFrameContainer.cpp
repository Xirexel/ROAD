#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalFirstOrderItemSuperFrameContainer.h"
#include "FractalFirstOrderItemContainer.h"

ROADdecoder::ROADover::FractalFirstOrderItemContainer* ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer::getFractalFirstOrderItemContainer(unsigned int aIndex) {
    return this->_fractalItemContainerCollection.at(aIndex);
}

ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer::FractalFirstOrderItemSuperFrameContainer(unsigned int aSuperFrameLength, unsigned int aMaxFrameRangLength)
    : _count(aSuperFrameLength)
{
    for(decltype(aSuperFrameLength) lindex = 0;
        lindex < aSuperFrameLength;
        ++lindex)
    {
        _fractalItemContainerCollection.push_back(new FractalFirstOrderItemContainer(aMaxFrameRangLength));

    }
}

unsigned int ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer::getCount() {
    return this->_count;
}

ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer::~FractalFirstOrderItemSuperFrameContainer()
{
    for(FractalFirstOrderItemContainer* item: _fractalItemContainerCollection)
        delete item;

    _fractalItemContainerCollection.clear();
}
