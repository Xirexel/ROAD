#include "ROADoverEncodingOptionsExperemental.h"

PlatformDependencies::ROADUInt8 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getROADFormatMode() {
    return ROADcoder::ROADoverCoder::EXPEREMENTAL;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setFrameSampleLength(ROADUInt32 aFrameSampleLength) {
	this->_frameSampleLength = aFrameSampleLength;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getFrameSampleLength() {
	return this->_frameSampleLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setSuperFrameLength(ROADUInt32 aSuperFrameLength) {
	this->_superFrameLength = aSuperFrameLength;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getSuperFrameLength() {
	return this->_superFrameLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setRangTopSampleLength(ROADUInt32 aRangTopSampleLength) {
	this->_rangTopSampleLength = aRangTopSampleLength;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getRangTopSampleLength() {
	return this->_rangTopSampleLength;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setAmountRangLevels(ROADUInt32 aAmountRangLevels) {
	this->_amountRangLevels = aAmountRangLevels;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getAmountRangLevels() {
	return this->_amountRangLevels;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setDomainShift(ROADUInt32 aDomainShift) {
	this->_domainShift = aDomainShift;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getDomainShift() {
	return this->_domainShift;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setSilenceThreshold(ROADReal aSilenceThreshold) {
	this->_silenceThreshold = aSilenceThreshold;
}

PlatformDependencies::ROADReal ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getSilenceThreshold() {
	return this->_silenceThreshold;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setRangThreshold(ROADReal aRangThreshold) {
	this->_rangThreshold = aRangThreshold;
}

PlatformDependencies::ROADReal ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getRangThreshold() {
	return this->_rangThreshold;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setMixingChannelsMode(ROADcoder::ROADoverCoder::ChannelsMixingMode aMixingChannelsMode) {
    this->_mixingChannelsMode = aMixingChannelsMode;
}

ROADcoder::ROADoverCoder::ChannelsMixingMode ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getMixingChannelsMode() {
	return this->_mixingChannelsMode;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setAmountOfChannels(ROADUInt16 aAmountOfChannels)
{
    this->_amountOfChannels = aAmountOfChannels;
}

PlatformDependencies::ROADUInt16 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getAmountOfChannels()
{
    return this->_amountOfChannels;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getEncryptionFormat()
{
    return this->_encryptionFormat;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setEncryptionFormat(ROADUInt32 aEncryptionFormat)
{
    this->_encryptionFormat = aEncryptionFormat;
}

void ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::setBitsPerSampleCode(ROADUInt8 aBitsPerSample)
{
    this->_bitsPerSample = aBitsPerSample;
}

PlatformDependencies::ROADUInt8 ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getBitsPerSample()
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

std::unique_ptr<ROADcoder::ROADoverCoder::FractalFormatRawDataContainer> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsExperemental::getFractalFormatRawDataContainer()
{
    ROADUInt32 lLength = 40;

    std::unique_ptr<ROADByte> lFractalFormat(new ROADByte[lLength]);

    PtrROADByte lptrFractalFormat = lFractalFormat.get();

    lptrFractalFormat[0] = 'R';

    lptrFractalFormat[1] = 'O';

    lptrFractalFormat[2] = 'A';

    lptrFractalFormat[3] = 'D';


    lptrFractalFormat+=4;


    ROADUInt32 ldata = 32;

    memcpy(lptrFractalFormat, (void*) &ldata , 4);

    lptrFractalFormat+=4;



    lptrFractalFormat[0] = 0;

    lptrFractalFormat[1] = 0;

    lptrFractalFormat[2] = 0;

    lptrFractalFormat[3] = 0;



    lptrFractalFormat+=4;




    ldata = getSuperFrameLength();

    memcpy(lptrFractalFormat, (void*) &ldata , 4);

    lptrFractalFormat+=4;




    ldata = getFrameSampleLength() / (getRangTopSampleLength() >> getAmountRangLevels());

    memcpy(lptrFractalFormat, (void*) &ldata , 4);

    lptrFractalFormat+=4;




    ldata = getDomainShift();

    memcpy(lptrFractalFormat, (void*) &ldata , 4);

    lptrFractalFormat+=4;




    ldata = (getRangTopSampleLength() >> getAmountRangLevels());

    memcpy(lptrFractalFormat, (void*) &ldata , 4);

    lptrFractalFormat+=4;




    ldata = getAmountOfChannels();

    memcpy(lptrFractalFormat, (void*) &ldata , 4);

    lptrFractalFormat+=4;




    ldata = getMixingChannelsMode();

    memcpy(lptrFractalFormat, (void*) &ldata , 4);

    lptrFractalFormat+=4;




    ldata = 0;

    memcpy(lptrFractalFormat, (void*) &ldata , 4);

    lptrFractalFormat+=4;





    std::unique_ptr<FractalFormatRawDataContainer> lptrfractalFormatRawDataContainer(new FractalFormatRawDataContainer(lFractalFormat, lLength));


    return lptrfractalFormatRawDataContainer;
}
