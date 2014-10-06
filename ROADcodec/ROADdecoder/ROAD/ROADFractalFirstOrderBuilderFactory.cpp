#include "ROADFractalFirstOrderBuilderFactory.h"
#include "ROADFractalFirstOrderBuilderNoneFixedRangLength.h"

ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* ROADdecoder::ROAD::ROADFractalFirstOrderBuilderFactory::getIROADFractalFirstOrderBuilder(unsigned int index, unsigned int aMaxRangeLength)
{
    ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* result = nullptr;

    if(index == 0)
        result = new ROADFractalFirstOrderBuilderNoneFixedRangLength(aMaxRangeLength);

    return result;
}

unsigned int ROADdecoder::ROAD::ROADFractalFirstOrderBuilderFactory::getOrder()
{
    return 1;
}
