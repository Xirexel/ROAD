#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalItem.h"
#include "IFractalItem.h"

double FractalDecoding::FractalItem::getAver() {
    return this->_aver;
}

unsigned int FractalDecoding::FractalItem::getLength() {
    return this->_length;
}

bool FractalDecoding::FractalItem::isSilence() {
    return this->_silence;
}

bool FractalDecoding::FractalItem::isForwardDirection() {
    return this->_forwardDirection;
}

unsigned int FractalDecoding::FractalItem::getDomainIndex() {
    return this->_domainIndex;
}

double FractalDecoding::FractalItem::getScale() {
    return this->_scale;
}

void FractalDecoding::FractalItem::setAver(double aAver) {
	this->_aver = aAver;
}

void FractalDecoding::FractalItem::setLength(unsigned int aLength) {
	this->_length = aLength;
}

void FractalDecoding::FractalItem::setSilence(bool aSilence) {
	this->_silence = aSilence;
}

void FractalDecoding::FractalItem::setForwardDirection(bool aForwardDirection) {
	this->_forwardDirection = aForwardDirection;
}

void FractalDecoding::FractalItem::setDomainIndex(unsigned int aDomainIndex) {
	this->_domainIndex = aDomainIndex;
}

void FractalDecoding::FractalItem::setScale(double aScale) {
	this->_scale = aScale;
}

unsigned int FractalDecoding::FractalItem::getPosition()
{
    return this->_position;
}

void FractalDecoding::FractalItem::setPosition(unsigned int aPosition)
{
    this->_position = aPosition;
}

FractalDecoding::FractalItem::~FractalItem()
{

}
