#include "ROADFractalFirstOrderAnalyzerFactory.h"
#include "ROADFractalFirstOrderAnalyzerNoneFixedRangLength.h"
#include "IFractalEncodingOptions.h"


ROADcoder::ROADCoder::IROADFractalFirstOrderAnalyzer* ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerFactory::getIROADFractalFirstOrderAnalyzer(ROADcoder::ROADCoder::IFractalEncodingOptions* aOptions,
                                                                                                                      ROADUInt32 aType)
{
    ROADcoder::ROADCoder::IROADFractalFirstOrderAnalyzer *result = nullptr;

    if(aType == 0)
    {
        result = new ROADFractalFirstOrderAnalyzerNoneFixedRangLength(aOptions);
    }

    return result;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerFactory::getOrder()
{
    return 1;
}
