#include "FractalFirstOrderItem.h"

ROADdecoder::ROADover::FractalFirstOrderItem::FractalFirstOrderItem()
    : _aver(0),
      _length(0),
      _inversDirection(0),
      _domainOffset(0),
      _scale(0),
      _position(0)
{

}

PlatformDependencies::ROADReal ROADdecoder::ROADover::FractalFirstOrderItem::getAver() {
    return this->_aver;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::FractalFirstOrderItem::getLength() {
    return this->_length;
}

PlatformDependencies::ROADBool ROADdecoder::ROADover::FractalFirstOrderItem::isInversDirection() {
    return this->_inversDirection;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::FractalFirstOrderItem::getDomainOffset() {
    return this->_domainOffset;
}

PlatformDependencies::ROADReal ROADdecoder::ROADover::FractalFirstOrderItem::getScale() {
    return this->_scale;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::FractalFirstOrderItem::getPosition() {
    return this->_position;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setAver(ROADReal aAver) {
	this->_aver = aAver;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setLength(ROADUInt32 aLength) {
	this->_length = aLength;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setInversDirection(ROADBool aInversDirection) {
	this->_inversDirection = aInversDirection;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setDomainOffset(ROADUInt32 aDomainOffset) {
	this->_domainOffset = aDomainOffset;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setScale(ROADReal aScale) {
	this->_scale = aScale;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setPosition(ROADUInt32 aPosition) {
	this->_position = aPosition;
}

