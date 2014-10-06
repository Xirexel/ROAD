#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalDecodingOptions.h"
#include "MixingChannelMode.h"

void FractalDecoding::FractalDecodingOptions::setMixingChannelMode(FractalDecoding::MixingChannelMode aMixingChannelMode) {
	this->_mixingChannelMode = aMixingChannelMode;
}

FractalDecoding::MixingChannelMode FractalDecoding::FractalDecodingOptions::getMixingChannelMode() {
	return this->_mixingChannelMode;
}

void FractalDecoding::FractalDecodingOptions::setFrameLength(unsigned int aFrameLength) {
	this->_frameLength = aFrameLength;
}

unsigned int FractalDecoding::FractalDecodingOptions::getFrameLength() {
	return this->_frameLength;
}

void FractalDecoding::FractalDecodingOptions::setSamplesPerRang(unsigned int aSamplesPerRang) {
	this->_samplesPerRang = aSamplesPerRang;
}

unsigned int FractalDecoding::FractalDecodingOptions::getSamplesPerRang() {
	return this->_samplesPerRang;
}

void FractalDecoding::FractalDecodingOptions::setSuperFrameLength(unsigned int aSuperFrameLength) {
	this->_superFrameLength = aSuperFrameLength;
}

unsigned int FractalDecoding::FractalDecodingOptions::getSuperFrameLength() {
	return this->_superFrameLength;
}

void FractalDecoding::FractalDecodingOptions::setAmountOfChannels(unsigned int aAmountOfChannels) {
	this->_amountOfChannels = aAmountOfChannels;
}

unsigned int FractalDecoding::FractalDecodingOptions::getAmountOfChannels() {
	return this->_amountOfChannels;
}

void FractalDecoding::FractalDecodingOptions::setRelativeDomainShift(unsigned int aRelativeDomainShift) {
	this->_relativeDomainShift = aRelativeDomainShift;
}

unsigned int FractalDecoding::FractalDecodingOptions::getRelativeDomainShift() {
	return this->_relativeDomainShift;
}

void FractalDecoding::FractalDecodingOptions::setScaleDomainShift(unsigned int aScaleDomainShift) {
	this->_scaleDomainShift = aScaleDomainShift;
}

unsigned int FractalDecoding::FractalDecodingOptions::getScaleDomainShift() {
	return this->_scaleDomainShift;
}

