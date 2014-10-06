#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "UIntDataContainer.h"
#include "IUIntDataContainer.h"

unsigned int* FractalDecoding::UIntDataContainer::getData() {
    return this->_data;
}

unsigned int FractalDecoding::UIntDataContainer::getCount() {
    return this->_count;
}

void FractalDecoding::UIntDataContainer::setCount(unsigned int aValue) {
    this->_count = aValue;
}

FractalDecoding::UIntDataContainer::UIntDataContainer(unsigned int aLength)
    : _data(new unsigned int[aLength])
{
}

FractalDecoding::UIntDataContainer::~UIntDataContainer()
{
    delete []_data;
}
