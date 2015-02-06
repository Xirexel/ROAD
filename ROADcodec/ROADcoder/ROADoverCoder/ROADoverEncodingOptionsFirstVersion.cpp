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




unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getFrameSampleLength() {
    return 2048;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setSuperFrameLength(unsigned char aSuperFrameLength) {
	this->_superFrameLength = aSuperFrameLength;
}

unsigned char ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getSuperFrameLength() {
	return this->_superFrameLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setPowerRangSampleLength(unsigned char aPowerRangSampleLength) {
    this->_powerRangSampleLength = aPowerRangSampleLength;
}

unsigned char ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getPowerRangSampleLength() {
    return this->_powerRangSampleLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setAmountRangLevels(unsigned char aAmountRangLevels) {
    this->_amountRangLevels = aAmountRangLevels;
}

unsigned char ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getAmountRangLevels() {
    return this->_amountRangLevels;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setDomainShift(unsigned char aDomainShift) {
	this->_domainShift = aDomainShift;
}

unsigned char ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getDomainShift() {
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

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setMixingChannelsMode(unsigned char aMixingChannelsMode) {
	this->_mixingChannelsMode = aMixingChannelsMode;
}

unsigned char ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getMixingChannelsMode() {
	return this->_mixingChannelsMode;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setAmountOfChannels(unsigned short aAmountOfChannels) {
	this->_amountOfChannels = aAmountOfChannels;
}

unsigned short ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getAmountOfChannels() {
	return this->_amountOfChannels;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setEncryptionFormat(unsigned int aEncryptionFormat) {
	this->_encryptionFormat = aEncryptionFormat;
}

unsigned int ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getEncryptionFormat() {
	return this->_encryptionFormat;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setBitsPerSample(unsigned char aBitsPerSample) {
	this->_bitsPerSample = aBitsPerSample;
}

unsigned char ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getBitsPerSample() {
	return this->_bitsPerSample;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setSelectedPreListeningChannel(unsigned short aSelectedPreListeningChannel) {
	this->_selectedPreListeningChannel = aSelectedPreListeningChannel;
}

unsigned short ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getSelectedPreListeningChannel() {
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
    unsigned int lLength = 23;

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
                                       << (unsigned char) lEndianType << 7
                                       << lLength - 9
                                       << getSuperFrameLength() // 1 byte
                                       << getAmountRangLevels() // 1 byte
                                       << getPowerRangSampleLength() // 1 byte
                                       << getDomainShift() // 1 byte
                                       << getAmountOfChannels() // 2 byte
                                       << getMixingChannelsMode() // 1 byte
                                       << getSelectedPreListeningChannel() // 2 byte
                                       << getBitsPerSample() // 1 byte
                                       << getEncryptionFormat(); // 4 byte


    std::unique_ptr<FractalFormatRawDataContainer> lptrfractalFormatRawDataContainer(new FractalFormatRawDataContainer(lFractalFormat, lLength));

    return lptrfractalFormatRawDataContainer;
}

