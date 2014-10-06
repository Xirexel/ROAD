#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "CharDataContainer.h"
ROADoverEncoding::CharDataContainer::CharDataContainer(unsigned int aLength) {
}

void ROADoverEncoding::CharDataContainer::setData(double* aData) {
	this->_data = aData;
}

double* ROADoverEncoding::CharDataContainer::getData() {
	return this->_data;
}

