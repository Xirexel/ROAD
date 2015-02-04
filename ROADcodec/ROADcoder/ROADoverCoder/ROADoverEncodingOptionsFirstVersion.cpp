#include "ROADoverEncodingOptionsFirstVersion.h"
#include "ROADFormatMode.h"



unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getROADFormatMode() {
    return FIRSTVERSION;
}

std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::clone() {


    ROADoverEncodingOptionsFirstVersion *lptrOptions = new ROADoverEncodingOptionsFirstVersion;

    *lptrOptions = *this;

    std::unique_ptr<IROADoverEncodingOptions> result(lptrOptions);

    return result;
}


void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setFrameSampleLength(unsigned int aFrameSampleLength) {
	this->_frameSampleLength = aFrameSampleLength;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getFrameSampleLength() {
	return this->_frameSampleLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setSuperFrameLength(unsigned int aSuperFrameLength) {
	this->_superFrameLength = aSuperFrameLength;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getSuperFrameLength() {
	return this->_superFrameLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setRangTopSampleLength(unsigned int aRangTopSampleLength) {
	this->_rangTopSampleLength = aRangTopSampleLength;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getRangTopSampleLength() {
	return this->_rangTopSampleLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setAmountRangLevels(unsigned int aAmountRangLevels) {
	this->_amountRangLevels = aAmountRangLevels;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getAmountRangLevels() {
	return this->_amountRangLevels;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setDomainShift(unsigned int aDomainShift) {
	this->_domainShift = aDomainShift;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getDomainShift() {
	return this->_domainShift;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setSilenceThreshold(double aSilenceThreshold) {
	this->_silenceThreshold = aSilenceThreshold;
}

double ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getSilenceThreshold() {
	return this->_silenceThreshold;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setRangThreshold(double aRangThreshold) {
	this->_rangThreshold = aRangThreshold;
}

double ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getRangThreshold() {
	return this->_rangThreshold;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setMixingChannelsMode(ROADcoder::ROADoverCoder::ChannelsMixingMode aMixingChannelsMode) {
	this->_mixingChannelsMode = aMixingChannelsMode;
}

ROADcoder::ROADoverCoder::ChannelsMixingMode ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getMixingChannelsMode() {
	return this->_mixingChannelsMode;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setAmountOfChannels(unsigned int aAmountOfChannels) {
	this->_amountOfChannels = aAmountOfChannels;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getAmountOfChannels() {
	return this->_amountOfChannels;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setEncryptionFormat(unsigned int aEncryptionFormat) {
	this->_encryptionFormat = aEncryptionFormat;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getEncryptionFormat() {
	return this->_encryptionFormat;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setBitsPerSample(int aBitsPerSample) {
	this->_bitsPerSample = aBitsPerSample;
}

int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getBitsPerSample() {
	return this->_bitsPerSample;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setSelectedPreListeningChannel(int aSelectedPreListeningChannel) {
	this->_selectedPreListeningChannel = aSelectedPreListeningChannel;
}

int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getSelectedPreListeningChannel() {
	return this->_selectedPreListeningChannel;
}

ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::~ROADoverEncodingOptionsFirstVersion()
{

}
