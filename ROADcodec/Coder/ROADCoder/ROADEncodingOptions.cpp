#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADEncodingOptions.h"
void ROADEncoding::ROADEncodingOptions::setFrameSampleLength(unsigned int aFrameSampleLength) {
	this->_frameSampleLength = aFrameSampleLength;
}

unsigned int ROADEncoding::ROADEncodingOptions::getFrameSampleLength() {
	return this->_frameSampleLength;
}

void ROADEncoding::ROADEncodingOptions::setSuperFrameLength(unsigned int aSuperFrameLength) {
	this->_superFrameLength = aSuperFrameLength;
}

unsigned int ROADEncoding::ROADEncodingOptions::getSuperFrameLength() {
	return this->_superFrameLength;
}

void ROADEncoding::ROADEncodingOptions::setRangeTopSampleLength(unsigned int aRangeTopSampleLength) {
	this->_rangeTopSampleLength = aRangeTopSampleLength;
}

unsigned int ROADEncoding::ROADEncodingOptions::getRangeTopSampleLength() {
	return this->_rangeTopSampleLength;
}

void ROADEncoding::ROADEncodingOptions::setAmountRangeLevels(unsigned int aAmountRangeLevels) {
	this->_amountRangeLevels = aAmountRangeLevels;
}

unsigned int ROADEncoding::ROADEncodingOptions::getAmountRangeLevels() {
	return this->_amountRangeLevels;
}

void ROADEncoding::ROADEncodingOptions::setDomainShift(unsigned int aDomainShift) {
	this->_domainShift = aDomainShift;
}

unsigned int ROADEncoding::ROADEncodingOptions::getDomainShift() {
	return this->_domainShift;
}

void ROADEncoding::ROADEncodingOptions::setSilenceThreshold(double aSilenceThreshold) {
	this->_silenceThreshold = aSilenceThreshold;
}

double ROADEncoding::ROADEncodingOptions::getSilenceThreshold() {
	return this->_silenceThreshold;
}

void ROADEncoding::ROADEncodingOptions::setRangeThreshold(double aRangeThreshold) {
	this->_rangeThreshold = aRangeThreshold;
}

double ROADEncoding::ROADEncodingOptions::getRangeThreshold() {
	return this->_rangeThreshold;
}

