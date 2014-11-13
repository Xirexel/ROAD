#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverDecodingOptionsExperemental.h"

ROADdecoder::ROADover::ROADFormatMode ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getROADFormatMode() {
    return this->_formatMode;
}

ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::ROADoverDecodingOptionsExperemental(unsigned char *byteArray, unsigned int aLength)
{
}

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getAmountOfChannels() {
    return this->_channels;
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

unsigned int ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental::getBitsPerSample() {
    return this->_bitsPerSample;
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

