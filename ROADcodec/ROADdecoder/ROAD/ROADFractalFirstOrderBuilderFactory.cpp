#include "ROADFractalFirstOrderBuilderFactory.h"
#include "ROADFractalFirstOrderBuilder.h"
#include "ROADRawDataFormat.h"


ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* ROADdecoder::ROAD::ROADFractalFirstOrderBuilderFactory::getIROADFractalFirstOrderBuilder(ROADUInt8 aROADRawDataFormat,
                                                                                                                                           ROADUInt32 aMaxSuperFrameSampleLength,
                                                                                                                                           ROADUInt32 aMaxRangeLength,
                                                                                                                                           ROADUInt32 aMaxRangSampleLength)
{
    ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* result = nullptr;

    switch (aROADRawDataFormat)
    {
    case ROADRawDataFormat::S32:
        result = new ROADFractalFirstOrderBuilder<ROADInt32>(aMaxSuperFrameSampleLength,
                                                             aMaxRangeLength,
                                                             aMaxRangSampleLength);
        break;

    default:
        break;
    }

//    if(index == 0)
//        result = new ROADFractalFirstOrderBuilderNoneFixedRangLength(aMaxRangeLength);

    return result;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROAD::ROADFractalFirstOrderBuilderFactory::getOrder()
{
    return 1;
}
