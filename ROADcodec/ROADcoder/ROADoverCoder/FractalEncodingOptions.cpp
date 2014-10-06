#include "FractalEncodingOptions.h"

unsigned int ROADcoder::ROADoverCoder::FractalEncodingOptions::getFrameSampleLength() {
    return this->_frameSampleLength;
}

unsigned int ROADcoder::ROADoverCoder::FractalEncodingOptions::getRangTopSampleLength() {
    return this->_rangTopSampleLength;
}

unsigned int ROADcoder::ROADoverCoder::FractalEncodingOptions::getAmountRangLevels() {
    return this->_amountRangLevels;
}

unsigned int ROADcoder::ROADoverCoder::FractalEncodingOptions::getDomainShift() {
    return this->_domainShift;
}

double ROADcoder::ROADoverCoder::FractalEncodingOptions::getSilenceThreshold() {
    return this->_silenceThreshold;
}

double ROADcoder::ROADoverCoder::FractalEncodingOptions::getRangThreshold() {
    return this->_rangThreshold;
}

ROADcoder::ROADoverCoder::FractalEncodingOptions::FractalEncodingOptions(unsigned int aFrameSampleLength,
                                                                         unsigned int aRangTopSampleLength,
                                                                         unsigned int aAmountRangLevels,
                                                                         unsigned int aDomainShift,
                                                                         double aSilenceThreshold,
                                                                         double aRangThreshold)
    : _frameSampleLength(aFrameSampleLength),
      _rangTopSampleLength(aRangTopSampleLength),
      _amountRangLevels(aAmountRangLevels),
      _domainShift(aDomainShift),
      _silenceThreshold(aSilenceThreshold),
      _rangThreshold(aRangThreshold)
{
}

