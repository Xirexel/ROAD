#include "ROADFractalFirstOrderBuilderFactory.h"
#include "ROADFractalFirstOrderBuilderNoneFixedRangLength.h"

ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* ROADdecoder::ROAD::ROADFractalFirstOrderBuilderFactory::getIROADFractalFirstOrderBuilder(ROADUInt32 index, ROADUInt32 aMaxRangeLength)
{
    ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* result = nullptr;

    if(index == 0)
        result = new ROADFractalFirstOrderBuilderNoneFixedRangLength(aMaxRangeLength);

    return result;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROAD::ROADFractalFirstOrderBuilderFactory::getOrder()
{
    return 1;
}
