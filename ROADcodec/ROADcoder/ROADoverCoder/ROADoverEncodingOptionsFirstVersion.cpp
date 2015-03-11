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

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setMaxSuperFrameLength(ROADUInt8 aMaxSuperFrameLength) {
    this->_maxSuperFrameLength = aMaxSuperFrameLength;
}

PlatformDependencies::ROADUInt8 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getMaxSuperFrameLength() {
    return this->_maxSuperFrameLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setRangSampleLengthPowerOfTwoScale(ROADUInt8 aRangSampleLength) {
    this->_rangSampleLengthPowerOfTwoScale = aRangSampleLength;
}

PlatformDependencies::ROADUInt8 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getRangSampleLengthPowerOfTwoScale() {
    return this->_rangSampleLengthPowerOfTwoScale;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getRangSampleLength() {

    ROADUInt32 lresult = getInitRangSampleLength() << this->_rangSampleLengthPowerOfTwoScale;

    if((lresult << 1) > getFrameSampleLength())
        lresult = getFrameSampleLength() >> 1;

    return lresult;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getInitRangSampleLength()
{
    return 4;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setAmountRangLevels(ROADUInt8 aAmountRangLevels) {
    this->_amountRangLevels = aAmountRangLevels;
}

PlatformDependencies::ROADUInt8 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getAmountRangLevels() {
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

PlatformDependencies::ROADUInt8 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::getEndianType()
{
    return this->_endianType;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion::setEndianType(ROADUInt8 aEndianType)
{
    if(aEndianType == 0)
        this->_endianType = Endian::BIG;
    else
        this->_endianType = Endian::LITTLE;
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

    ROADUInt8 lHead = this->_endianType;



    auto lptrIDataWriteDriver = ROADcoder::Driver::DataDriver::getIDataWriteDriver(lFractalFormat, lLength, Endian::EndianType(this->_endianType));

    lptrIDataWriteDriver.get()->operator<<('R') // 1 byte
                                       << 'o' // 1 byte
                                       << 'A' // 1 byte
                                       << 'd' // 1 byte
                                       << lHead // 1 byte: 7 bit - Endian flag, 6 to 0 bits - code of block: ROADINFO - 0
                                       << (ROADUInt16) (lLength - 7) // 2 bytes: length of block
                                       << getAmountOfChannels() // 2 bytes: original amount of channels
                                       << getBitsPerSampleCode() // 1 byte: code of bits per sample:
                                          /* U8 = 0x08 - unsigned integer 8 bits,
                                           * S8 = 0xF8 - signed integer 8 bits,
                                           * U12 = 0xF4 - unsigned integer 12 bits,
                                           * S12 = 0x0C - signed integer 12 bits,
                                           * U16 = 0xF0 - unsigned integer 16 bits,
                                           * S16 = 0x10 - signed integer 16 bits,
                                           * U20 = 0xEC - unsigned integer 20 bits,
                                           * S20 = 0x14 - signed integer 20 bits,
                                           * U24 = 0xE8 - unsigned integer 24 bits,
                                           * S24 = 0x18 - signed integer 24 bits,
                                           * U32 = 0xE0 - unsigned integer 32 bits,
                                           * S32 = 0x20 - signed integer 32 bits,
                                           * U64 = 0xC0 - unsigned integer 64 bits,
                                           * S64 = 0x40 - signed integer 64 bits,
                                           * F32 = 0x46 - float 32 bits,
                                           * D64 = 0x44 - double 64 bits*/
                                       << getOriginalFrequency() // 4 bytes: original frequency of samples.
                                       << getMixingChannelsMode() // 1 byte: code of mixing channels - 0(NONE), 1(MID - prelistening channel is averade of sterio), 2(SIDE - prelistening channel is diff of sterio), 3(CUSTOMIZE - select one channel for prelistening)
                                       << getSelectedPreListeningChannel() // 2 bytes: selected channel for prelistening.
                                       << (ROADUInt8)(getMaxSuperFrameLength() - 1) // 1 byte: maximum amount of frames in one super frame - from 1 to 256 (0 to 255).
                                       << getAmountRangLevels() // 1 byte:  Depth of bintree of the fractal analyse (0 - 3)
                                       << getRangSampleLengthPowerOfTwoScale() // 1 byte: ths scale of initial range length 4 samples - 4 * 2^n (0 to 11)
                                       << getConstantScale() // 1 byte: value of constant scale - if equal 0 than scale is read from data stream.
                                       << getDomainShift() // 1 byte: shifting between two neighbour domains by 2^n
                                       << getEncryptionFormat() // 4 bytes: unique code of encription.
                                       << CRCSupport::CRC::CRC16(lPtrFractalFormat,lptrIDataWriteDriver->getPosition() - 4); // 2 bytes - CRC16 code.

    std::unique_ptr<FractalFormatRawDataContainer> lptrfractalFormatRawDataContainer(new FractalFormatRawDataContainer(lFractalFormat, lLength));

    return lptrfractalFormatRawDataContainer;
}

