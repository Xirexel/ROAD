#include "ROADoverEncodingOptionsFirstVersion.h"
#include "ROADFormatMode.h"
#include "../Driver/DataDriver.h"
#include "../../Endian/EndianType.h"
#include "crc.h"



PlatformDependencies::ROADByte ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getROADFormatMode() {
    return FIRSTVERSION;
}

std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::clone() {

    ROADoverEncodingOptionsFirstVersion *lptrOptions = new ROADoverEncodingOptionsFirstVersion;

    *lptrOptions = *this;

    std::unique_ptr<IROADoverEncodingOptions> result(lptrOptions);

    return result;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getFrameSampleLength() {
    return 2048;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setSuperFrameLength(ROADByte aSuperFrameLength) {
	this->_superFrameLength = aSuperFrameLength;
}

PlatformDependencies::ROADByte ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getSuperFrameLength() {
	return this->_superFrameLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setPowerRangSampleLength(ROADByte aRangSampleLength) {
    this->_rangSampleLength = aRangSampleLength;
}

PlatformDependencies::ROADByte ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getRangSampleLength() {
//    return this->_rangSampleLength;
    return 4;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setAmountRangLevels(ROADByte aAmountRangLevels) {
    this->_amountRangLevels = aAmountRangLevels;
}

PlatformDependencies::ROADByte ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getAmountRangLevels() {
    return this->_amountRangLevels;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setDomainShift(ROADByte aDomainShift) {
	this->_domainShift = aDomainShift;
}

PlatformDependencies::ROADByte ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getDomainShift() {
	return this->_domainShift;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setSilenceThreshold(ROADReal aSilenceThreshold) {
	this->_silenceThreshold = aSilenceThreshold;
}

PlatformDependencies::ROADReal ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getSilenceThreshold() {
	return this->_silenceThreshold;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setRangThreshold(ROADReal aRangThreshold) {
	this->_rangThreshold = aRangThreshold;
}

PlatformDependencies::ROADReal ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getRangThreshold() {
	return this->_rangThreshold;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setMixingChannelsMode(ROADByte aMixingChannelsMode) {
	this->_mixingChannelsMode = aMixingChannelsMode;
}

PlatformDependencies::ROADByte ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getMixingChannelsMode() {
	return this->_mixingChannelsMode;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setAmountOfChannels(ROADUInt16 aAmountOfChannels) {
	this->_amountOfChannels = aAmountOfChannels;
}

PlatformDependencies::ROADUInt16 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getAmountOfChannels() {
	return this->_amountOfChannels;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setEncryptionFormat(ROADUInt32 aEncryptionFormat) {
	this->_encryptionFormat = aEncryptionFormat;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getEncryptionFormat() {
	return this->_encryptionFormat;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setBitsPerSampleCode(ROADByte aBitsPerSampleCode) {
    this->_bitsPerSampleCode = aBitsPerSampleCode;
}

PlatformDependencies::ROADByte ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getBitsPerSampleCode() {
    return this->_bitsPerSampleCode;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setSelectedPreListeningChannel(ROADUInt16 aSelectedPreListeningChannel) {
	this->_selectedPreListeningChannel = aSelectedPreListeningChannel;
}

PlatformDependencies::ROADUInt16 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getSelectedPreListeningChannel() {
	return this->_selectedPreListeningChannel;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getEndianType()
{
    return this->_endianType;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setEndianType(ROADUInt32 aEndianType)
{
    this->_endianType = aEndianType;
}

PlatformDependencies::ROADInt8 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getConstantScale()
{
    return this->_constantScale;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setConstantScale(ROADInt8 aConstantScale)
{
    this->_constantScale = aConstantScale;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getOriginalFrequency()
{
    return this->_originalFrequency;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setOriginalFrequency(ROADUInt32 aOriginalFrequency)
{
    this->_originalFrequency = aOriginalFrequency;
}

ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::ROADoverEncodingOptionsFirstVersion()
    : _endianType(Endian::LITTLE),
      _constantScale(0)
{

}

ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::~ROADoverEncodingOptionsFirstVersion()
{

}

std::unique_ptr<ROADcoder::ROADoverCoder::FractalFormatRawDataContainer> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getFractalFormatRawDataContainer()
{
    ROADUInt32 lLength = 28;

    std::unique_ptr<ROADByte> lFractalFormat(new ROADByte[lLength]);

    PtrROADByte lPtrFractalFormat = lFractalFormat.get();

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

    lptrIDataWriteDriver.get()->operator<<('R') // 1 byte
                                       << 'o' // 1 byte
                                       << 'A' // 1 byte
                                       << 'd' // 1 byte
                                       << (ROADUInt8) lEndianType << 7 // 1 byte
                                       << (ROADUInt16) (lLength - 7) // 2 bytes
                                       << getAmountOfChannels() // 2 bytes
                                       << getMixingChannelsMode() // 1 byte
                                       << getSelectedPreListeningChannel() // 2 bytes
                                       << getBitsPerSampleCode() // 1 byte
                                       << getOriginalFrequency() // 4 bytes
                                       << getSuperFrameLength() // 1 byte
                                       << getAmountRangLevels() // 1 byte
                                       << getRangSampleLength() // 1 byte
                                       << getConstantScale() // 1 byte
                                       << getDomainShift() // 1 byte
                                       << getEncryptionFormat() // 4 bytes
                                       << CRCSupport::CRC::CRC16(lPtrFractalFormat,lptrIDataWriteDriver->getPosition() - 4); // 2 bytes

    std::unique_ptr<FractalFormatRawDataContainer> lptrfractalFormatRawDataContainer(new FractalFormatRawDataContainer(lFractalFormat, lLength));

    return lptrfractalFormatRawDataContainer;
}

