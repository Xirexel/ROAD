#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FrameFractalItemCollection.h"
#include "FractalItem.h"
#include "IFractalItem.h"
#include "IFrameFractalItemCollection.h"

ROADEncoding::IFractalItem* ROADEncoding::FrameFractalItemCollection::getNextIFractalItem() {

    if(this->_count > 511)
        this->_count = 511;

    return this->_fractalItemCollection.at(this->_count++);
}

ROADEncoding::FrameFractalItemCollection::FrameFractalItemCollection(unsigned int aSize)
    : _count(0)
{
    for(decltype(aSize) index = 0;
        index < aSize;
        ++index)
        _fractalItemCollection.push_back(new ROADEncoding::FractalItem);
}

ROADEncoding::FrameFractalItemCollection::~FrameFractalItemCollection()
{
    for(ROADEncoding::FractalItem* item: _fractalItemCollection)
        delete item;

    _fractalItemCollection.clear();
}

ROADEncoding::FractalItem* ROADEncoding::FrameFractalItemCollection::getFractalItem(unsigned int aIndex) {
    return this->_fractalItemCollection.at(aIndex);
}

void ROADEncoding::FrameFractalItemCollection::resetCount() {
    this->_count = 0;
}

unsigned int ROADEncoding::FrameFractalItemCollection::getCount() {
	return this->_count;
}

