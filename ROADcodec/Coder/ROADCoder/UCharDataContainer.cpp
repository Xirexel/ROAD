#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "UCharDataContainer.h"
#include "IUCharDataContainer.h"

unsigned char* ROADEncoding::UCharDataContainer::getData() {
    return this->_data;
}

unsigned int ROADEncoding::UCharDataContainer::getCount() {
    return this->_count;
}

ROADEncoding::UCharDataContainer::UCharDataContainer(unsigned int aLength)
    : _data(new unsigned char[aLength])
{
}

ROADEncoding::UCharDataContainer::~UCharDataContainer()
{
    delete []this->_data;
}

void ROADEncoding::UCharDataContainer::setCount(unsigned int aCount) {
	this->_count = aCount;
}

