#include "RealDataContainer.h"

ROADcoder::ROADoverCoder::RealDataContainer::RealDataContainer(ROADUInt32 aLength)
    : _data(new ROADReal[aLength], aLength),
      _length(aLength)
{

}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::RealDataContainer::getLength() {
    return this->_length;
}

PlatformDependencies::PtrROADReal ROADcoder::ROADoverCoder::RealDataContainer::getData() {
    return this->_data;
}

ROADcoder::ROADoverCoder::RealDataContainer::~RealDataContainer()
{
}
