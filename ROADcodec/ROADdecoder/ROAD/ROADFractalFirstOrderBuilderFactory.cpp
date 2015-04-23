#include "ROADFractalFirstOrderBuilderFactory.h"
#include "ROADFractalFirstOrderBuilder.h"
#include "ROADDataFormat.h"
#include "ROADFrameDataContainer.h"


ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* ROADdecoder::ROAD::ROADFractalFirstOrderBuilderFactory::getIROADFractalFirstOrderBuilder(ROADUInt8 aROADRawDataFormat,
                                                                                                                                           ROADUInt32 aMaxRangSampleLength)
{
    ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* result = nullptr;

    switch (aROADRawDataFormat)
    {

    case ROADDataFormat::Double:
        result = new ROADFractalFirstOrderBuilder<ROADReal>(aMaxRangSampleLength);
        break;

    default:
        break;
    }


    return result;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROAD::ROADFractalFirstOrderBuilderFactory::getOrder()
{
    return 1;
}
