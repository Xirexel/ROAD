#include <string>
#include <vector>
#include <exception>
using namespace std;

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

double ROADdecoder::ROADover::FractalFirstOrderItem::getAver() {
    return this->_aver;
}

unsigned int ROADdecoder::ROADover::FractalFirstOrderItem::getLength() {
    return this->_length;
}

bool ROADdecoder::ROADover::FractalFirstOrderItem::isInversDirection() {
    return this->_inversDirection;
}

unsigned int ROADdecoder::ROADover::FractalFirstOrderItem::getDomainOffset() {
    return this->_domainOffset;
}

double ROADdecoder::ROADover::FractalFirstOrderItem::getScale() {
    return this->_scale;
}

unsigned int ROADdecoder::ROADover::FractalFirstOrderItem::getPosition() {
    return this->_position;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setAver(double aAver) {
	this->_aver = aAver;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setLength(unsigned int aLength) {
	this->_length = aLength;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setInversDirection(bool aInversDirection) {
	this->_inversDirection = aInversDirection;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setDomainOffset(unsigned int aDomainOffset) {
	this->_domainOffset = aDomainOffset;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setScale(double aScale) {
	this->_scale = aScale;
}

void ROADdecoder::ROADover::FractalFirstOrderItem::setPosition(unsigned int aPosition) {
	this->_position = aPosition;
}

