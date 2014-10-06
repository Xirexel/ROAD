#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FrameFractalItemCollection.h"
#include "FractalItem.h"
#include "IFractalItem.h"
#include "IFrameFractalItemCollection.h"

FractalEncoding::IFractalItem* FractalEncoding::FrameFractalItemCollection::getNextIFractalItem() {

    if(this->_count > 511)
        this->_count = 511;

    return this->_fractalItemCollection.at(this->_count++);
}

FractalEncoding::FrameFractalItemCollection::FrameFractalItemCollection(unsigned int aSize)
    : _count(0)
{
    for(decltype(aSize) index = 0;
        index < aSize;
        ++index)
        _fractalItemCollection.push_back(new FractalEncoding::FractalItem);
}

FractalEncoding::FrameFractalItemCollection::~FrameFractalItemCollection()
{
    for(FractalEncoding::FractalItem* item: _fractalItemCollection)
        delete item;

    _fractalItemCollection.clear();
}

FractalEncoding::FractalItem* FractalEncoding::FrameFractalItemCollection::getFractalItem(unsigned int aIndex) {
    return this->_fractalItemCollection.at(aIndex);
}

void FractalEncoding::FrameFractalItemCollection::resetCount() {
    this->_count = 0;
}

unsigned int FractalEncoding::FrameFractalItemCollection::getCount() {
	return this->_count;
}

