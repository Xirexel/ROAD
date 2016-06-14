#include "ROADOrderedFractalAnalyzerFactory.h"
#include "ROADFractalFirstOrderAnalyzerFactory.h"

PlatformDependencies::Unique_ptr<ROADcoder::ROADCoder::IROADFractalAnalyzerFactory> ROADcoder::ROADCoder::ROADOrderedFractalAnalyzerFactory::getIROADFractalAnalyzerFactory(ROADUInt32 aOrder) {

    Unique_ptr<ROADcoder::ROADCoder::IROADFractalAnalyzerFactory> result;

    if(aOrder == 1)
    {
        result.reset(new ROADFractalFirstOrderAnalyzerFactory);
    }

    return result;
}
