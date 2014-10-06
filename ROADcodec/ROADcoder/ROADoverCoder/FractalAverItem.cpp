#include "FractalAverItem.h"

void ROADcoder::ROADoverCoder::FractalAverItem::setAver(double aValue) {
    this->_aver = aValue;
}

void ROADcoder::ROADoverCoder::FractalAverItem::setLength(unsigned int aValue) {
    this->_length = aValue;
}

void ROADcoder::ROADoverCoder::FractalAverItem::setIndex(unsigned int aValue) {
    this->_index = aValue;
}

double ROADcoder::ROADoverCoder::FractalAverItem::getAver() {
	return this->_aver;
}

unsigned int ROADcoder::ROADoverCoder::FractalAverItem::getLength() {
	return this->_length;
}

unsigned int ROADcoder::ROADoverCoder::FractalAverItem::getIndex() {
	return this->_index;
}

