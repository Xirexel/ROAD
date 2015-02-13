#include "DoubleDataContainer.h"

ROADcoder::ROADoverCoder::DoubleDataContainer::DoubleDataContainer(ROADUInt32 aLength)
    : _data(new double[aLength]),
      _length(aLength)
{

}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::DoubleDataContainer::getLength() {
    return this->_length;
}

PlatformDependencies::PtrROADReal ROADcoder::ROADoverCoder::DoubleDataContainer::getData() {
    return this->_data;
}

ROADcoder::ROADoverCoder::DoubleDataContainer::~DoubleDataContainer()
{
    delete[] this->_data;
}
