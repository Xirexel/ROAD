#include "ROADOrderedFractalAnalyzerFactory.h"
#include "ROADFractalFirstOrderAnalyzerFactory.h"

std::unique_ptr<ROADcoder::ROADCoder::IROADFractalAnalyzerFactory> ROADcoder::ROADCoder::ROADOrderedFractalAnalyzerFactory::getIROADFractalAnalyzerFactory(unsigned int aOrder) {

    std::unique_ptr<ROADcoder::ROADCoder::IROADFractalAnalyzerFactory> result;

    if(aOrder == 1)
    {
        result.reset(new ROADFractalFirstOrderAnalyzerFactory);
    }

    return result;
}
