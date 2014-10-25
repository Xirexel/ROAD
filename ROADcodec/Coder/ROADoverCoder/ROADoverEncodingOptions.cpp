#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverEncodingOptions.h"
#include "MixingChannelsMode.h"
#include "ROADFormat.h"

void ROADoverEncoding::ROADoverEncodingOptions::setMixingChannelsMode(ROADoverEncoding::MixingChannelsMode aMixingChannelsMode) {
	this->_mixingChannelsMode = aMixingChannelsMode;
}

ROADoverEncoding::MixingChannelsMode ROADoverEncoding::ROADoverEncodingOptions::getMixingChannelsMode() {
	return this->_mixingChannelsMode;
}

void ROADoverEncoding::ROADoverEncodingOptions::setChannels(unsigned int aChannels) {
	this->_channels = aChannels;
}

unsigned int ROADoverEncoding::ROADoverEncodingOptions::getChannels() {
	return this->_channels;
}

void ROADoverEncoding::ROADoverEncodingOptions::setSuperframeLength(unsigned int aSuperframeLength) {
	this->_superframeLength = aSuperframeLength;
}

unsigned int ROADoverEncoding::ROADoverEncodingOptions::getSuperframeLength() {
	return this->_superframeLength;
}

void ROADoverEncoding::ROADoverEncodingOptions::setFrameSampleLength(unsigned int aFrameSampleLength) {
	this->_frameSampleLength = aFrameSampleLength;
}

unsigned int ROADoverEncoding::ROADoverEncodingOptions::getFrameSampleLength() {
	return this->_frameSampleLength;
}

void ROADoverEncoding::ROADoverEncodingOptions::setBitsPerSample(unsigned int aBitsPerSample) {
	this->_bitsPerSample = aBitsPerSample;
}

unsigned int ROADoverEncoding::ROADoverEncodingOptions::getBitsPerSample() {
	return this->_bitsPerSample;
}

void ROADoverEncoding::ROADoverEncodingOptions::setFormat(ROADoverEncoding::ROADFormat aFormat) {
	this->_format = aFormat;
}

ROADoverEncoding::ROADFormat ROADoverEncoding::ROADoverEncodingOptions::getFormat() {
	return this->_format;
}

void ROADoverEncoding::ROADoverEncodingOptions::setShortestRangSampleLength(unsigned int aShortestRangSampleLength) {
	this->_shortestRangSampleLength = aShortestRangSampleLength;
}

unsigned int ROADoverEncoding::ROADoverEncodingOptions::getShortestRangSampleLength() {
	return this->_shortestRangSampleLength;
}

void ROADoverEncoding::ROADoverEncodingOptions::setLongestRangSampleLength(unsigned int aLongestRangSampleLength) {
	this->_longestRangSampleLength = aLongestRangSampleLength;
}

unsigned int ROADoverEncoding::ROADoverEncodingOptions::getLongestRangSampleLength() {
	return this->_longestRangSampleLength;
}

void ROADoverEncoding::ROADoverEncodingOptions::setDomainShift(unsigned int aDomainShift) {
	this->_domainShift = aDomainShift;
}

unsigned int ROADoverEncoding::ROADoverEncodingOptions::getDomainShift() {
	return this->_domainShift;
}

void ROADoverEncoding::ROADoverEncodingOptions::setEncryptionFromat(unsigned int aEncryptionFromat) {
	this->_encryptionFromat = aEncryptionFromat;
}

unsigned int ROADoverEncoding::ROADoverEncodingOptions::getEncryptionFromat() {
	return this->_encryptionFromat;
}

