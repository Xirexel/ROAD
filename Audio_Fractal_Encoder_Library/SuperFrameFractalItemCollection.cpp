#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "SuperFrameFractalItemCollection.h"
#include "FrameFractalItemCollection.h"
#include "FractalDataContainer.h"
#include "IFrameFractalItemCollection.h"
#include "IFractalDataContainer.h"

FractalEncoding::SuperFrameFractalItemCollection::SuperFrameFractalItemCollection(unsigned int aFrameFractalItemCollectionSize,
                                                                                  unsigned int aSize)
    :  _fractalDataContainer(new FractalEncoding::FractalDataContainer(aFrameFractalItemCollectionSize * aSize))
{
    for(decltype(aFrameFractalItemCollectionSize)index = 0;
        index < aFrameFractalItemCollectionSize;
        ++index)
        _frameFractalItemCollections.push_back(new FractalEncoding::FrameFractalItemCollection(aSize));
}

FractalEncoding::SuperFrameFractalItemCollection::~SuperFrameFractalItemCollection()
{
    for(FractalEncoding::FrameFractalItemCollection* item: _frameFractalItemCollections)
        delete item;

    _frameFractalItemCollections.clear();

    delete _fractalDataContainer;
}

FractalEncoding::IFrameFractalItemCollection* FractalEncoding::SuperFrameFractalItemCollection::getIFrameFractalItemCollection(unsigned int aIndex) {
    return this->_frameFractalItemCollections.at(aIndex);
}

FractalEncoding::IFractalDataContainer* FractalEncoding::SuperFrameFractalItemCollection::getIFractalDataContainer() {

    _fractalDataContainer->reset();

    for(FractalEncoding::FrameFractalItemCollection* item: _frameFractalItemCollections)
    {
        _fractalDataContainer->populate(item);

        item->resetCount();
    }

    return this->_fractalDataContainer;
}

unsigned int FractalEncoding::SuperFrameFractalItemCollection::getSize() {
	return this->_size;
}

