#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DoubleDataContainer.h"
ROADoverEncoding::DoubleDataContainer::DoubleDataContainer(unsigned int aLength) {
}

void ROADoverEncoding::DoubleDataContainer::setData(double* aData) {
	this->_data = aData;
}

double* ROADoverEncoding::DoubleDataContainer::getData() {
	return this->_data;
}

