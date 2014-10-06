#include "FractalFirstOrderItemSuperFrameContainer.h"
#include "FractalFirstOrderItemContainer.h"

ROADcoder::ROADoverCoder::FractalFirstOrderItemContainer* ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer::getFractalItemContainer(unsigned int aIndex) {
    return this->_fractalItemContainerCollection.at(aIndex);
}

ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer::FractalFirstOrderItemSuperFrameContainer(unsigned int aSuperFrameLength, unsigned int aMaxFrameRangLength)
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

unsigned int ROADcoder::ROADoverCoder::FractalFirstOrderItemSuperFrameContainer::getCount() {
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
