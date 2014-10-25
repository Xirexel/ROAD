#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalItem.h"
#include "IFractalItem.h"

void ROADEncoding::FractalItem::setAver(double aValue) {
    this->_aver = aValue;
}

void ROADEncoding::FractalItem::setDomain(unsigned int aValue) {
    this->_domain = aValue;
}

void ROADEncoding::FractalItem::setScale(float aValue) {
    this->_scale = aValue;
}

void ROADEncoding::FractalItem::setIndex(unsigned int aValue) {
    this->_index = aValue;
}

void ROADEncoding::FractalItem::setDirection(bool aValue) {
    this->_direction = aValue;
}

void ROADEncoding::FractalItem::setSilence(bool aValue) {
    this->_silence = aValue;
}

double ROADEncoding::FractalItem::getAver() {
	return this->_aver;
}

unsigned int ROADEncoding::FractalItem::getDomain() {
	return this->_domain;
}

float ROADEncoding::FractalItem::getScale() {
	return this->_scale;
}

unsigned int ROADEncoding::FractalItem::getIndex() {
	return this->_index;
}

bool ROADEncoding::FractalItem::isDirection() {
	return this->_direction;
}

bool ROADEncoding::FractalItem::isSilence() {
	return this->_silence;
}

