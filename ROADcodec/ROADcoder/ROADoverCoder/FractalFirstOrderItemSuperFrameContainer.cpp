#include "FractalFirstOrderItemSuperFrameContainer.h"
#include "FractalFirstOrderItemContainer.h"

ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer* ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer::getFractalItemContainer(ROADUInt32 aIndex) {
    return this->_fractalItemContainerCollection.at(aIndex);
}

ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer::FractalFirstOrderItemSuperFrameContainer(ROADUInt32 aSuperFrameLength, ROADUInt32 aMaxFrameRangLength)
    : _count(aSuperFrameLength)
{

    for(decltype(aSuperFrameLength) lindex = 0;
        lindex < aSuperFrameLength;
        ++lindex)
    {
        FractalFirstOrderItemContainer* lptrItemContainer = new FractalFirstOrderItemContainer(aMaxFrameRangLength);

        lptrItemContainer->resetCounts();

        this->_fractalItemContainerCollection.push_back(lptrItemContainer);
    }
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer::getCount() {
    return this->_count;
}

ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer::~FractalFirstOrderItemSuperFrameContainer()
{
    for(auto item: this->_fractalItemContainerCollection)
    {
        delete item;
    }

    this->_fractalItemContainerCollection.clear();
}
