#include "ROADOrderedFractalAnalyzerFactory.h"
#include "ROADFractalFirstOrderAnalyzerFactory.h"

std::unique_ptr<ROADcoder::ROADCoder::IROADFractalAnalyzerFactory> ROADcoder::ROADCoder::ROADOrderedFractalAnalyzerFactory::getIROADFractalAnalyzerFactory(ROADUInt32 aOrder) {

    std::unique_ptr<ROADcoder::ROADCoder::IROADFractalAnalyzerFactory> result;

    if(aOrder == 1)
    {
        result.reset(new ROADFractalFirstOrderAnalyzerFactory);
    }

    return result;
}
