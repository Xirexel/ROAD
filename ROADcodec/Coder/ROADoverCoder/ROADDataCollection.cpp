#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADDataCollection.h"
#include "IROADDataContainer.h"
#include "IROADDataCollection.h"

unsigned int ROADoverEncoding::ROADDataCollection::getCount() {
    return this->_count;
}

ROADEncoding::IROADDataContainer* ROADoverEncoding::ROADDataCollection::getIROADDataContainer(unsigned int aIndex)
{
    return _container.at(aIndex);
}

void ROADoverEncoding::ROADDataCollection::addIROADDataContainer(ROADEncoding::IROADDataContainer* aItem) {
    _container.push_back(aItem);
    this->_count++;
}

void ROADoverEncoding::ROADDataCollection::reset() {
    this->_container.clear();
    this->_count = 0;
}

