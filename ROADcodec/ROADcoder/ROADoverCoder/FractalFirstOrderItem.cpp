#include "FractalFirstOrderItem.h"

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setAver(double aValue) {
    this->_aver = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setIsInversDirection(bool aValue) {
    this->_isInversDirection = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setLength(unsigned int aValue) {
    this->_length = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setDomainOffset(unsigned int aValue) {
    this->_domainOffset = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setScale(double aValue) {
    this->_scale = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setPosition(unsigned int aValue) {
    this->_position = aValue;
}

double ROADcoder::ROADoverCoder::FractalFirstOrderItem::getAver() {
	return this->_aver;
}

bool ROADcoder::ROADoverCoder::FractalFirstOrderItem::isIsInversDirection() {
	return this->_isInversDirection;
}

unsigned int ROADcoder::ROADoverCoder::FractalFirstOrderItem::getLength() {
	return this->_length;
}

unsigned int ROADcoder::ROADoverCoder::FractalFirstOrderItem::getDomainOffset() {
	return this->_domainOffset;
}

double ROADcoder::ROADoverCoder::FractalFirstOrderItem::getScale() {
	return this->_scale;
}

unsigned int ROADcoder::ROADoverCoder::FractalFirstOrderItem::getPosition() {
	return this->_position;
}

