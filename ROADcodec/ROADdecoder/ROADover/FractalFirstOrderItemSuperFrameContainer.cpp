#include "FractalFirstOrderItemSuperFrameContainer.h"
#include "FractalFirstOrderItemContainer.h"

ROADdecoder::ROADover::FractalFirstOrderItemContainer* ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer::getFractalFirstOrderItemContainer(ROADUInt32 aIndex) {
    return this->_fractalItemContainerCollection.at(aIndex);
}

ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer::FractalFirstOrderItemSuperFrameContainer(ROADUInt32 aSuperFrameLength, ROADUInt32 aMaxFrameRangLength)
    : _count(aSuperFrameLength)
{
    for(decltype(aSuperFrameLength) lindex = 0;
        lindex < aSuperFrameLength;
        ++lindex)
    {
        _fractalItemContainerCollection.push_back(new FractalFirstOrderItemContainer(aMaxFrameRangLength));

    }
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer::getCount() {
    return this->_count;
}

ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer::~FractalFirstOrderItemSuperFrameContainer()
{
    for(auto item: _fractalItemContainerCollection)
        delete item;

    _fractalItemContainerCollection.clear();
}
