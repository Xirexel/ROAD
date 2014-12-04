#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverDecodingOptionsExperemental.h"

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getROADFormatMode() {
    return this->_formatMode;
}

ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::ROADoverDecodingOptionsExperemental(Driver::IDataReadDriver *aPtrIDataReadDriver)
{
    this->_formatMode = ROADFormatMode(0);

    *aPtrIDataReadDriver >>(this->_superframeLength);

    *aPtrIDataReadDriver >>(this->_frameRangLength);

    *aPtrIDataReadDriver >>(this->_relativeDomainShift);

    *aPtrIDataReadDriver >>(this->_scaleDomainShift);

    *aPtrIDataReadDriver >>(this->_amountOfChannels);

    unsigned int lchannelsMixingMode;

    *aPtrIDataReadDriver >>(lchannelsMixingMode);

    this->_channelsMixingMode = ChannelsMixingMode(lchannelsMixingMode);

    *aPtrIDataReadDriver >>(this->_encriptionCode);

    this->_samplesPerRang = _scaleDomainShift;

}

ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::~ROADoverDecodingOptionsExperemental()
{

}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getAmountOfChannels() {
    return this->_amountOfChannels;
}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getSuperframeLength() {
    return this->_superframeLength;
}

ROADdecoder::ROADover::ChannelsMixingMode ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getChannelsMixingMode() {
    return this->_channelsMixingMode;
}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getFrameRangLength() {
    return this->_frameRangLength;
}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getSamplesPerRang() {
    return this->_samplesPerRang;
}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getRelativeDomainShift() {
    return this->_relativeDomainShift;
}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getScaleDomainShift() {
    return this->_scaleDomainShift;
}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getOriginalSamplesPerRang() {
    return this->_scaleDomainShift;
}

void ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::setSamplesPerRang(unsigned int aValue) {
    this->_samplesPerRang = aValue;
}

void ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::setOriginalBitsPerSample(unsigned int aValue)
{
    this->_originalBitsPerSample = aValue;
}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getOriginalBitsPerSample()
{
    return this->_originalBitsPerSample;
}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getEncriptionCode()
{
    return this->_encriptionCode;
}
