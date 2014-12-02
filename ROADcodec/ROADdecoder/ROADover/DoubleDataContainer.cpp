#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DoubleDataContainer.h"
#include "IDoubleDataContainer.h"

double* ROADdecoder::ROADover::DoubleDataContainer::getData() {
    return this->_data;
}

unsigned int ROADdecoder::ROADover::DoubleDataContainer::getCount() {
    return this->_count;
}

void ROADdecoder::ROADover::DoubleDataContainer::setCount(unsigned int aValue) {
    this->_count = aValue;
}

ROADdecoder::ROADover::DoubleDataContainer::~DoubleDataContainer() {
    delete []this->_data;
}

ROADdecoder::ROADover::DoubleDataContainer::DoubleDataContainer(unsigned int aLength)
    : _data(new double[aLength]), _count(aLength)
{
}

