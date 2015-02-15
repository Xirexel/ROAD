#include <cstring>

#include "DoubleDataContainer.h"
#include "IDoubleDataContainer.h"

PlatformDependencies::PtrROADReal ROADdecoder::ROADover::DoubleDataContainer::getData() {
    return this->_data;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::DoubleDataContainer::getCount() {
    return this->_count;
}

void ROADdecoder::ROADover::DoubleDataContainer::setCount(ROADUInt32 aValue) {
    this->_count = aValue;
}

ROADdecoder::ROADover::DoubleDataContainer::~DoubleDataContainer() {
    delete []this->_data;
}

ROADdecoder::ROADover::DoubleDataContainer::DoubleDataContainer(ROADUInt32 aLength)
    : _data(new ROADReal[aLength]), _count(aLength)
{
    memset(_data, 0, aLength * sizeof(ROADReal));
}

