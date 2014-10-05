#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "SuperFrameFractalItemCollection.h"
#include "FrameFractalItemCollection.h"
#include "FractalDataContainer.h"
#include "IFrameFractalItemCollection.h"
#include "IFractalDataContainer.h"

ROADEncoding::SuperFrameFractalItemCollection::SuperFrameFractalItemCollection(unsigned int aFrameFractalItemCollectionSize,
                                                                                  unsigned int aSize)
    :  _fractalDataContainer(new ROADEncoding::FractalDataContainer(aFrameFractalItemCollectionSize * aSize))
{
    for(decltype(aFrameFractalItemCollectionSize)index = 0;
        index < aFrameFractalItemCollectionSize;
        ++index)
        _frameFractalItemCollections.push_back(new ROADEncoding::FrameFractalItemCollection(aSize));
}

ROADEncoding::SuperFrameFractalItemCollection::~SuperFrameFractalItemCollection()
{
    for(ROADEncoding::FrameFractalItemCollection* item: _frameFractalItemCollections)
        delete item;

    _frameFractalItemCollections.clear();

    delete _fractalDataContainer;
}

ROADEncoding::IFrameFractalItemCollection* ROADEncoding::SuperFrameFractalItemCollection::getIFrameFractalItemCollection(unsigned int aIndex) {
    return this->_frameFractalItemCollections.at(aIndex);
}

ROADEncoding::IFractalDataContainer* ROADEncoding::SuperFrameFractalItemCollection::getIFractalDataContainer() {

    _fractalDataContainer->reset();

    for(ROADEncoding::FrameFractalItemCollection* item: _frameFractalItemCollections)
    {
        _fractalDataContainer->populate(item);

        item->resetCount();
    }

    return this->_fractalDataContainer;
}

unsigned int ROADEncoding::SuperFrameFractalItemCollection::getSize() {
	return this->_size;
}

