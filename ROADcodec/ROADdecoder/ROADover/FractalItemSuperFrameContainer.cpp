#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalItemSuperFrameContainer.h"
#include "FractalItemContainer.h"

ROADdecoder::ROADover::FractalItemContainer* ROADdecoder::ROADover::FractalItemSuperFrameContainer::getFractalItemContainer(unsigned int aIndex) {
    return this->_fractalItemContainerCollection.at(aIndex);
}

ROADdecoder::ROADover::FractalItemSuperFrameContainer::FractalItemSuperFrameContainer(unsigned int aSuperFrameLength, unsigned int aMaxFrameRangLength)
    : _count(aSuperFrameLength)
{
    for(decltype(aSuperFrameLength) lindex = 0;
        lindex < aSuperFrameLength;
        ++lindex)
    {
        _fractalItemContainerCollection.push_back(new FractalItemContainer(aMaxFrameRangLength));

    }
}

unsigned int ROADdecoder::ROADover::FractalItemSuperFrameContainer::getCount() {
    return this->_count;
}

ROADdecoder::ROADover::FractalItemSuperFrameContainer::~FractalItemSuperFrameContainer()
{
    for(FractalItemContainer* item: _fractalItemContainerCollection)
        delete item;

    _fractalItemContainerCollection.clear();
}
