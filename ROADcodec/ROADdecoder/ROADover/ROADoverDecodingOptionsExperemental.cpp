#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverDecodingOptionsExperemental.h"

ROADdecoder::ROADover::ROADFormatMode ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getROADFormatMode() {
    return this->_formatMode;
}

ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::ROADoverDecodingOptionsExperemental(unsigned char* aData,
                                                                                                unsigned int aLength)
{
    this->_formatMode = ROADFormatMode(*((unsigned int *)aData));

    aData+=4;

    this->_superframeLength = *((unsigned int *)aData);

    aData+=4;

    this->_frameRangLength = *((unsigned int *)aData);

    aData+=4;

    this->_relativeDomainShift = *((unsigned int *)aData);

    aData+=4;

    this->_scaleDomainShift = *((unsigned int *)aData);

    aData+=4;

    this->_amountOfChannels = *((unsigned int *)aData);

    aData+=4;

    this->_channelsMixingMode = ChannelsMixingMode(*((unsigned int *)aData));

    aData+=4;

    this->_encriptionCode = *((unsigned int *)aData);


    this->_samplesPerRang = _scaleDomainShift;


//    length = fread(&lfractDescr._format._superFrameLength, 1, sizeof(lfractDescr._format._superFrameLength),pFile);

//    length = fread(&lfractDescr._format._frameRangeLength, 1, sizeof(lfractDescr._format._frameRangeLength),pFile);

//    length = fread(&lfractDescr._format._domainShift, 1, sizeof(lfractDescr._format._domainShift),pFile);

//    length = fread(&lfractDescr._format._domainShiftScale, 1, sizeof(lfractDescr._format._domainShiftScale),pFile);

//    length = fread(&lfractDescr._format._originalAmountOfChannels, 1, sizeof(lfractDescr._format._originalAmountOfChannels),pFile);

//    length = fread(&lfractDescr._format._averDiffMode, 1, sizeof(lfractDescr._format._averDiffMode),pFile);

//    length = fread(&lfractDescr._format._encriptionCode, 1, sizeof(lfractDescr._format._encriptionCode),pFile);
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

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getEncriptionCode()
{
    this->_encriptionCode;
}
