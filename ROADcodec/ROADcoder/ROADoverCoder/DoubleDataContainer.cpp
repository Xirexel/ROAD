#include "DoubleDataContainer.h"

ROADcoder::ROADoverCoder::DoubleDataContainer::DoubleDataContainer(unsigned int aLength)
    : _data(new double[aLength]),
      _length(aLength)
{

}

unsigned int ROADcoder::ROADoverCoder::DoubleDataContainer::getLength() {
    return this->_length;
}

double* ROADcoder::ROADoverCoder::DoubleDataContainer::getData() {
    return this->_data;
}

ROADcoder::ROADoverCoder::DoubleDataContainer::~DoubleDataContainer()
{
    delete[] this->_data;
}
