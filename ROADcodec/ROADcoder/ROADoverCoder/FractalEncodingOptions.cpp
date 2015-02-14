#include "FractalEncodingOptions.h"

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalEncodingOptions::getFrameSampleLength() {
    return this->_frameSampleLength;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalEncodingOptions::getRangTopSampleLength() {
    return this->_rangTopSampleLength;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalEncodingOptions::getAmountRangLevels() {
    return this->_amountRangLevels;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::FractalEncodingOptions::getDomainShift() {
    return this->_domainShift;
}

PlatformDependencies::ROADReal ROADcoder::ROADoverCoder::FractalEncodingOptions::getSilenceThreshold() {
    return this->_silenceThreshold;
}

PlatformDependencies::ROADReal ROADcoder::ROADoverCoder::FractalEncodingOptions::getRangThreshold() {
    return this->_rangThreshold;
}

ROADcoder::ROADoverCoder::FractalEncodingOptions::FractalEncodingOptions(ROADUInt32 aFrameSampleLength,
                                                                         ROADUInt32 aRangTopSampleLength,
                                                                         ROADUInt32 aAmountRangLevels,
                                                                         ROADUInt32 aDomainShift,
                                                                         ROADReal aSilenceThreshold,
                                                                         ROADReal aRangThreshold)
    : _frameSampleLength(aFrameSampleLength),
      _rangTopSampleLength(aRangTopSampleLength),
      _amountRangLevels(aAmountRangLevels),
      _domainShift(aDomainShift),
      _silenceThreshold(aSilenceThreshold),
      _rangThreshold(aRangThreshold)
{
}

