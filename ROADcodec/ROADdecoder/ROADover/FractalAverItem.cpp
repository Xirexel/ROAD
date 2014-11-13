#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalAverItem.h"

double ROADdecoder::ROADover::FractalAverItem::getAver() {
    return this->_aver;
}

unsigned int ROADdecoder::ROADover::FractalAverItem::getLength() {
    return this->_length;
}

void ROADdecoder::ROADover::FractalAverItem::setAver(double aAver) {
	this->_aver = aAver;
}

void ROADdecoder::ROADover::FractalAverItem::setLength(unsigned int aLength) {
	this->_length = aLength;
}

