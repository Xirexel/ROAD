#include "ROADoverDecodingOptionsExperemental.h"

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getROADFormatMode() {
    return this->_formatMode;
}

ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::ROADoverDecodingOptionsExperemental(Driver::IDataReadDriver *aPtrIDataReadDriver)
    : _formatMode(ROADFormatMode(0))
{


    *aPtrIDataReadDriver >>(this->_superframeLength);

    *aPtrIDataReadDriver >>(this->_frameRangLength);

    *aPtrIDataReadDriver >>(this->_relativeDomainShift);

    *aPtrIDataReadDriver >>(this->_scaleDomainShift);

    *aPtrIDataReadDriver >>(this->_amountOfChannels);

    ROADInt32 lchannelsMixingMode;

    *aPtrIDataReadDriver >>(lchannelsMixingMode);

    this->_channelsMixingMode = ChannelsMixingMode(lchannelsMixingMode);

    *aPtrIDataReadDriver >>(this->_encriptionCode);

    this->_samplesPerRang = _scaleDomainShift;

}

ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::~ROADoverDecodingOptionsExperemental()
{

}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getAmountOfChannels() {
    return this->_amountOfChannels;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getSuperframeLength() {
    return this->_superframeLength;
}

ROADdecoder::ROADover::ChannelsMixingMode ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getChannelsMixingMode() {
    return this->_channelsMixingMode;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getFrameRangLength() {
    return this->_frameRangLength;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getSamplesPerRang() {
    return this->_samplesPerRang;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getRelativeDomainShift() {
    return this->_relativeDomainShift;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getScaleDomainShift() {
    return this->_scaleDomainShift;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getOriginalSamplesPerRang() {
    return this->_scaleDomainShift;
}

void ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::setSamplesPerRang(ROADUInt32 aValue) {
    this->_samplesPerRang = aValue;
}

void ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::setOriginalBitsPerSample(ROADUInt32 aValue)
{
    this->_originalBitsPerSample = aValue;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getOriginalBitsPerSample()
{
    return this->_originalBitsPerSample;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getEncriptionCode()
{
    return this->_encriptionCode;
}
