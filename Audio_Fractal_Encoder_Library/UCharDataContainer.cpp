#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "UCharDataContainer.h"
#include "IUCharDataContainer.h"

unsigned char* FractalEncoding::UCharDataContainer::getData() {
    return this->_data;
}

unsigned int FractalEncoding::UCharDataContainer::getCount() {
    return this->_count;
}

FractalEncoding::UCharDataContainer::UCharDataContainer(unsigned int aLength)
    : _data(new unsigned char[aLength])
{
}

FractalEncoding::UCharDataContainer::~UCharDataContainer()
{
    delete []this->_data;
}

void FractalEncoding::UCharDataContainer::setCount(unsigned int aCount) {
	this->_count = aCount;
}

