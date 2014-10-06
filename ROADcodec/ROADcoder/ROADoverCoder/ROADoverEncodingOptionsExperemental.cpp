#include "ROADoverEncodingOptionsExperemental.h"

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getROADFormatMode() {
    return ROADcoder::ROADoverCoder::EXPEREMENTAL;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setFrameSampleLength(unsigned int aFrameSampleLength) {
	this->_frameSampleLength = aFrameSampleLength;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getFrameSampleLength() {
	return this->_frameSampleLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setSuperFrameLength(unsigned int aSuperFrameLength) {
	this->_superFrameLength = aSuperFrameLength;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getSuperFrameLength() {
	return this->_superFrameLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setRangTopSampleLength(unsigned int aRangTopSampleLength) {
	this->_rangTopSampleLength = aRangTopSampleLength;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getRangTopSampleLength() {
	return this->_rangTopSampleLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setAmountRangLevels(unsigned int aAmountRangLevels) {
	this->_amountRangLevels = aAmountRangLevels;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getAmountRangLevels() {
	return this->_amountRangLevels;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setDomainShift(unsigned int aDomainShift) {
	this->_domainShift = aDomainShift;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getDomainShift() {
	return this->_domainShift;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setSilenceThreshold(double aSilenceThreshold) {
	this->_silenceThreshold = aSilenceThreshold;
}

double ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getSilenceThreshold() {
	return this->_silenceThreshold;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setRangThreshold(double aRangThreshold) {
	this->_rangThreshold = aRangThreshold;
}

double ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getRangThreshold() {
	return this->_rangThreshold;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setMixingChannelsMode(ROADcoder::ROADoverCoder::ChannelsMixingMode aMixingChannelsMode) {
    this->_mixingChannelsMode = aMixingChannelsMode;
}

ROADcoder::ROADoverCoder::ChannelsMixingMode ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getMixingChannelsMode() {
	return this->_mixingChannelsMode;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setAmountOfChannels(unsigned int aAmountOfChannels)
{
    this->_amountOfChannels = aAmountOfChannels;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getAmountOfChannels()
{
    return this->_amountOfChannels;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getEncryptionFormat()
{
    return this->_encryptionFormat;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setEncryptionFormat(unsigned int aEncryptionFormat)
{
    this->_encryptionFormat = aEncryptionFormat;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setBitsPerSample(unsigned int aBitsPerSample)
{
    this->_bitsPerSample = aBitsPerSample;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getBitsPerSample()
{
    return this->_bitsPerSample;
}

std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::clone()
{
    ROADoverEncodingOptionsExperemental *lptrOptions = new ROADoverEncodingOptionsExperemental;

    *lptrOptions = *this;

    std::unique_ptr<IROADoverEncodingOptions> result(lptrOptions);

    return result;
}
