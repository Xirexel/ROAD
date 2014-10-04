#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "UCharDataContainer.h"
#include "IUCharDataContainer.h"

unsigned char* FractalDecoding::UCharDataContainer::getData() {
    return this->_data;
}

unsigned int FractalDecoding::UCharDataContainer::getCount() {
    return this->_count;
}

FractalDecoding::UCharDataContainer::UCharDataContainer(unsigned int aLength)
    : _data(new unsigned char[aLength])
{
}

FractalDecoding::UCharDataContainer::~UCharDataContainer()
{
    delete []_data;
}

void FractalDecoding::UCharDataContainer::setCount(unsigned int aValue) {
    this->_count = aValue;
}

