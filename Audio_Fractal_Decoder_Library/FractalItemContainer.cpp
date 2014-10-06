#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalItemContainer.h"
#include "FractalItem.h"
#include "IFractalItem.h"
#include "IFractalItemContainer.h"

FractalDecoding::IFractalItem* FractalDecoding::FractalItemContainer::getIFractalItem(unsigned int aIndex) {
    return _fractalItemCollecrion.at(aIndex);
}

unsigned int FractalDecoding::FractalItemContainer::getCount() {
    return this->_count;
}

void FractalDecoding::FractalItemContainer::reset() {
    this->_count = 0;
}

FractalDecoding::FractalItem* FractalDecoding::FractalItemContainer::getNextFractalItem() {

    unsigned int t = this->_count;

    this->_count++;

    return _fractalItemCollecrion.at(t);
}

FractalDecoding::FractalItemContainer::FractalItemContainer(unsigned int aLength) {

    for(decltype(aLength) index = 0;
        index < aLength;
        ++index)
    {
        _fractalItemCollecrion.push_back(new FractalItem);
    }
}

FractalDecoding::FractalItemContainer::~FractalItemContainer()
{
    for(FractalDecoding::FractalItem* item: _fractalItemCollecrion)
        delete item;

    _fractalItemCollecrion.clear();
}
