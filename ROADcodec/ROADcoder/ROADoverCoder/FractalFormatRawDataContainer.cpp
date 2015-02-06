#include "FractalFormatRawDataContainer.h"

ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::FractalFormatRawDataContainer(std::unique_ptr<unsigned char> &aData, unsigned int aLength)
    : _data(aData.release()),
      _length(aLength)
{
}

unsigned char* ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::getData() const {
    return this->_data.get();
}

unsigned int ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::getLength() const {
	return this->_length;
}


