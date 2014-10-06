#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DoubleDataContainer.h"
#include "IDoubleDataContainer.h"

double* FractalDecoding::DoubleDataContainer::getData() {
    return this->_data;
}

unsigned int FractalDecoding::DoubleDataContainer::getCount() {
    return this->_count;
}

FractalDecoding::DoubleDataContainer::DoubleDataContainer(unsigned int aLength)
    : _data(new double[aLength])
{
}

FractalDecoding::DoubleDataContainer::~DoubleDataContainer()
{
    delete []_data;
}


void FractalDecoding::DoubleDataContainer::setCount(unsigned int aValue) {
    this->_count = aValue;
}

