#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalItem.h"
#include "IFractalItem.h"

void FractalEncoding::FractalItem::setAver(double aValue) {
    this->_aver = aValue;
}

void FractalEncoding::FractalItem::setDomain(unsigned int aValue) {
    this->_domain = aValue;
}

void FractalEncoding::FractalItem::setScale(float aValue) {
    this->_scale = aValue;
}

void FractalEncoding::FractalItem::setIndex(unsigned int aValue) {
    this->_index = aValue;
}

void FractalEncoding::FractalItem::setDirection(bool aValue) {
    this->_direction = aValue;
}

void FractalEncoding::FractalItem::setSilence(bool aValue) {
    this->_silence = aValue;
}

double FractalEncoding::FractalItem::getAver() {
	return this->_aver;
}

unsigned int FractalEncoding::FractalItem::getDomain() {
	return this->_domain;
}

float FractalEncoding::FractalItem::getScale() {
	return this->_scale;
}

unsigned int FractalEncoding::FractalItem::getIndex() {
	return this->_index;
}

bool FractalEncoding::FractalItem::isDirection() {
	return this->_direction;
}

bool FractalEncoding::FractalItem::isSilence() {
	return this->_silence;
}

