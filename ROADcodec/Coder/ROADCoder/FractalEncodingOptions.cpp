#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalEncodingOptions.h"
#include "MixingChannelsMode.h"

void FractalEncoding::FractalEncodingOptions::setFrameSampleLength(unsigned int aFrameSampleLength) {
	this->_frameSampleLength = aFrameSampleLength;
}

unsigned int FractalEncoding::FractalEncodingOptions::getFrameSampleLength() {
	return this->_frameSampleLength;
}

void FractalEncoding::FractalEncodingOptions::setSuperFrameLength(unsigned int aSuperFrameLength) {
	this->_superFrameLength = aSuperFrameLength;
}

unsigned int FractalEncoding::FractalEncodingOptions::getSuperFrameLength() {
	return this->_superFrameLength;
}

void FractalEncoding::FractalEncodingOptions::setRangeTopSampleLength(unsigned int aRangeTopSampleLength) {
	this->_rangeTopSampleLength = aRangeTopSampleLength;
}

unsigned int FractalEncoding::FractalEncodingOptions::getRangeTopSampleLength() {
	return this->_rangeTopSampleLength;
}

void FractalEncoding::FractalEncodingOptions::setAmountRangeLevels(unsigned int aAmountRangeLevels) {
	this->_amountRangeLevels = aAmountRangeLevels;
}

unsigned int FractalEncoding::FractalEncodingOptions::getAmountRangeLevels() {
	return this->_amountRangeLevels;
}

void FractalEncoding::FractalEncodingOptions::setDomainShift(unsigned int aDomainShift) {
	this->_domainShift = aDomainShift;
}

unsigned int FractalEncoding::FractalEncodingOptions::getDomainShift() {
	return this->_domainShift;
}

void FractalEncoding::FractalEncodingOptions::setMixingChannelsMode(FractalEncoding::MixingChannelsMode aMixingChannelsMode) {
	this->_mixingChannelsMode = aMixingChannelsMode;
}

FractalEncoding::MixingChannelsMode FractalEncoding::FractalEncodingOptions::getMixingChannelsMode() {
	return this->_mixingChannelsMode;
}

void FractalEncoding::FractalEncodingOptions::setSilenceThreshold(double aSilenceThreshold) {
	this->_silenceThreshold = aSilenceThreshold;
}

double FractalEncoding::FractalEncodingOptions::getSilenceThreshold() {
	return this->_silenceThreshold;
}

void FractalEncoding::FractalEncodingOptions::setRangeThreshold(double aRangeThreshold) {
	this->_rangeThreshold = aRangeThreshold;
}

double FractalEncoding::FractalEncodingOptions::getRangeThreshold() {
	return this->_rangeThreshold;
}

