#include "ROADFractalFirstOrderAnalyzerFactory.h"
#include "ROADFractalFirstOrderAnalyzerNoneFixedRangLength.h"
#include "IFractalEncodingOptions.h"


ROADcoder::ROADCoder::IROADFractalFirstOrderAnalyzer* ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerFactory::getIROADFractalFirstOrderAnalyzer(ROADcoder::ROADCoder::IFractalEncodingOptions* aOptions,
                                                                                                                      ROADUInt32 aType)
{
    if(aType == 0)
    {
        return new ROADFractalFirstOrderAnalyzerNoneFixedRangLength(aOptions);
    }

    return nullptr;
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerFactory::getOrder()
{
    return 1;
}
