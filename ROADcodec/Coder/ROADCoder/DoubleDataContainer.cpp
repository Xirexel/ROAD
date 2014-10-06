#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DoubleDataContainer.h"
#include "IDoubleDataContainer.h"

double* ROADEncoding::DoubleDataContainer::getData() {
    return this->_data;
}

unsigned int ROADEncoding::DoubleDataContainer::getCount() {
    return this->_count;
}

ROADEncoding::DoubleDataContainer::DoubleDataContainer(unsigned int aLength)
    : _data(new double[aLength])
{
}

ROADEncoding::DoubleDataContainer::~DoubleDataContainer()
{
    delete []_data;
}

void ROADEncoding::DoubleDataContainer::setCount(unsigned int aCount) {
	this->_count = aCount;
}

