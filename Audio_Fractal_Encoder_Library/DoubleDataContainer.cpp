#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DoubleDataContainer.h"
#include "IDoubleDataContainer.h"

double* FractalEncoding::DoubleDataContainer::getData() {
    return this->_data;
}

unsigned int FractalEncoding::DoubleDataContainer::getCount() {
    return this->_count;
}

FractalEncoding::DoubleDataContainer::DoubleDataContainer(unsigned int aLength)
    : _data(new double[aLength])
{
}

FractalEncoding::DoubleDataContainer::~DoubleDataContainer()
{
    delete []_data;
}

void FractalEncoding::DoubleDataContainer::setCount(unsigned int aCount) {
	this->_count = aCount;
}

