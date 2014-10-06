#include "FractalFormatRawDataContainer.h"
void ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::setRawData(char* aData, unsigned int aLength) {
    this->_data.reset(aData);

    this->_length = aLength;
}

ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::FractalFormatRawDataContainer() {
}

char* ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::getData() {
    return this->_data.get();
}

unsigned int ROADcoder::ROADoverCoder::FractalFormatRawDataContainer::getLength() {
	return this->_length;
}

