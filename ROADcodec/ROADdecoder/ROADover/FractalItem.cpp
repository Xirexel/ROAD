#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalItem.h"

double ROADdecoder::ROADover::FractalItem::getAver() {
    return this->_aver;
}

unsigned int ROADdecoder::ROADover::FractalItem::getLength() {
    return this->_length;
}

bool ROADdecoder::ROADover::FractalItem::isInversDirection() {
    return this->_domainOffset;
}

unsigned int ROADdecoder::ROADover::FractalItem::getDomainOffset() {
    return this->_domainOffset;
}

double ROADdecoder::ROADover::FractalItem::getScale() {
    return this->_scale;
}

unsigned int ROADdecoder::ROADover::FractalItem::getPosition() {
    return this->_position;
}

void ROADdecoder::ROADover::FractalItem::setAver(double aAver) {
	this->_aver = aAver;
}

void ROADdecoder::ROADover::FractalItem::setLength(unsigned int aLength) {
	this->_length = aLength;
}

void ROADdecoder::ROADover::FractalItem::setInversDirection(bool aInversDirection) {
	this->_inversDirection = aInversDirection;
}

void ROADdecoder::ROADover::FractalItem::setDomainOffset(unsigned int aDomainOffset) {
	this->_domainOffset = aDomainOffset;
}

void ROADdecoder::ROADover::FractalItem::setScale(double aScale) {
	this->_scale = aScale;
}

void ROADdecoder::ROADover::FractalItem::setPosition(unsigned int aPosition) {
	this->_position = aPosition;
}

