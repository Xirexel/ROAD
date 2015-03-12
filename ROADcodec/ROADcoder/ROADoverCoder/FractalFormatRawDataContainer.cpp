#include "FractalFormatRawDataContainer.h"

ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::FractalFormatRawDataContainer(std::shared_ptr<ROADByte> &aData, ROADUInt32 aLength)
    : _data(aData),
      _length(aLength)
{
}

PlatformDependencies::PtrROADByte ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::getData() const {
    return this->_data.get();
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::getLength() const {
	return this->_length;
}


