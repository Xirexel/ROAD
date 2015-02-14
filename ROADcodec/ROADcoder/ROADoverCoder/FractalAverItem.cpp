#include "FractalAverItem.h"

void ROADcoder::ROADoverCoder::FractalAverItem::setAver(ROADReal aValue) {
    this->_aver = aValue;
}

void ROADcoder::ROADoverCoder::FractalAverItem::setLength(ROADUInt32 aValue) {
    this->_length = aValue;
}

void ROADcoder::ROADoverCoder::FractalAverItem::setIndex(ROADUInt32 aValue) {
    this->_index = aValue;
}

PlatformDependencies::ROADReal ROADcoder::ROADoverCoder::FractalAverItem::getAver() {
	return this->_aver;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalAverItem::getLength() {
	return this->_length;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalAverItem::getIndex() {
	return this->_index;
}

