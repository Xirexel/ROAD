#include "FractalFirstOrderItem.h"

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setAver(ROADReal aValue) {
    this->_aver = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setIsInversDirection(ROADBool aValue) {
    this->_isInversDirection = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setLength(ROADUInt32 aValue) {
    this->_length = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setDomainOffset(ROADUInt32 aValue) {
    this->_domainOffset = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setScale(ROADReal aValue) {
    this->_scale = aValue;
}

void ROADcoder::ROADoverCoder::FractalFirstOrderItem::setPosition(ROADUInt32 aValue) {
    this->_position = aValue;
}

PlatformDependencies::ROADReal ROADcoder::ROADoverCoder::FractalFirstOrderItem::getAver() {
	return this->_aver;
}

PlatformDependencies::ROADBool ROADcoder::ROADoverCoder::FractalFirstOrderItem::isIsInversDirection() {
	return this->_isInversDirection;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalFirstOrderItem::getLength() {
	return this->_length;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalFirstOrderItem::getDomainOffset() {
	return this->_domainOffset;
}

PlatformDependencies::ROADReal ROADcoder::ROADoverCoder::FractalFirstOrderItem::getScale() {
	return this->_scale;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalFirstOrderItem::getPosition() {
	return this->_position;
}

