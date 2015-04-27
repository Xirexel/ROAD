#include "ROADFractalFirstOrderBuilderFactory.h"
#include "ROADFractalFirstOrderBuilder.h"
#include "ROADDataFormat.h"
#include "ROADFrameDataContainer.h"

#include "iostream"

ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* ROADdecoder::ROAD::ROADFractalFirstOrderBuilderFactory::getIROADFractalFirstOrderBuilder(ROADUInt8 aROADRawDataFormat,
                                                                                                                                           ROADUInt32 aMaxRangSampleLength,
                                                                                                                                           ROADUInt8 aBinTreeDepth)
{
    ROADdecoder::ROAD::IROADFractalFirstOrderBuilder* result = nullptr;

    switch (aROADRawDataFormat)
    {

    case ROADDataFormat::Double:
        {
            switch (aBinTreeDepth)
            {
            default:
                {
                    result = new ROADFractalFirstOrderBuilder<ROADReal, false, 2048>(aMaxRangSampleLength);
                }
                break;
            }
        }
        break;

    case ROADDataFormat::Int32:
        {
            switch (aBinTreeDepth)
            {
            default:
                {
                    result = new ROADFractalFirstOrderBuilder<ROADInt32, false, 2048>(aMaxRangSampleLength);
                }
                break;
            }
        }
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
