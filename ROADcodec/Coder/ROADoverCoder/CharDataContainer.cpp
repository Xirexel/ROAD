#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "CharDataContainer.h"
#include "ICharDataContainer.h"

ROADoverEncoding::CharDataContainer::CharDataContainer(unsigned int aLength)
    : _data(new char[aLength]),
      _length(aLength)
{
}

ROADoverEncoding::CharDataContainer::~CharDataContainer()
{
    delete this->_data;
}

char* ROADoverEncoding::CharDataContainer::getData() {
    return this->_data;
}

unsigned int ROADoverEncoding::CharDataContainer::getLength() {
    return this->_length;
}

