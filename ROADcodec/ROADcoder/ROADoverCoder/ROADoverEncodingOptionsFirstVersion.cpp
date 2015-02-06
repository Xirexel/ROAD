#include "ROADoverEncodingOptionsFirstVersion.h"
#include "ROADFormatMode.h"
#include "../Driver/DataDriver.h"
#include "../../Endian/EndianType.h"



unsigned char ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getROADFormatMode() {
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

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setRangSampleLength(unsigned int aRangSampleLength) {
    this->_rangSampleLength = aRangSampleLength;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getRangSampleLength() {
    return this->_rangSampleLength;
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

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getEndianType()
{
    return this->_endianType;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setEndianType(unsigned int aEndianType)
{
    this->_endianType = aEndianType;
}

ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::ROADoverEncodingOptionsFirstVersion()
    : _endianType(Endian::LITTLE)
{

}

ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::~ROADoverEncodingOptionsFirstVersion()
{

}

std::unique_ptr<ROADcoder::ROADoverCoder::FractalFormatRawDataContainer> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getFractalFormatRawDataContainer()
{
    unsigned int lLength = 40;

    std::unique_ptr<unsigned char> lFractalFormat(new unsigned char[lLength]);

    Endian::EndianType lEndianType = Endian::LITTLE;

    switch (this->_endianType) {
    case 0:
        lEndianType = Endian::BIG;
        break;
    case 1:
        lEndianType = Endian::LITTLE;
        break;
    default:
        break;
    }

    auto lptrIDataWriteDriver = ROADcoder::Driver::DataDriver::getIDataWriteDriver(lFractalFormat, lLength, lEndianType);

    lptrIDataWriteDriver.get()->operator<<('R')
                                       << 'o'
                                       << 'A'
                                       << 'd'
                                       << getROADFormatMode()
                                       << this->_endianType
                                       << lLength - 10
                                       << getSuperFrameLength()
                                       << getFrameSampleLength()
                                       << getRangSampleLength()
                                       << getDomainShift()
                                       << getAmountOfChannels()
                                       << getMixingChannelsMode()
                                       << getSelectedPreListeningChannel()
                                       << getBitsPerSample()
                                       << getEncryptionFormat();


    std::unique_ptr<FractalFormatRawDataContainer> lptrfractalFormatRawDataContainer(new FractalFormatRawDataContainer(lFractalFormat, lLength));

    return lptrfractalFormatRawDataContainer;
}

