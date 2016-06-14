#include "ROADoverEncodingOptionsFactory.h"
#include "ROADFormatMode.h"
#include "ROADoverEncodingOptionsFirstVersion.h"

#include "ROADFormatMode.h"


PlatformDependencies::Unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFactory::getIROADoverEncodingOptions(ROADUInt32 aType) {
    Unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> result;

    switch (aType) {
    case (PlatformDependencies::ROADInt32)ROADFormatMode::FIRSTVERSION:

        result.reset(new ROADoverEncodingOptionsFirstVersion);

        break;
    default:
        break;
    }

    return result;
}

std::vector<PlatformDependencies::ROADUInt32> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFactory::getSupportedFormats()
{

    std::vector<ROADUInt32> result = {(PlatformDependencies::ROADInt32)ROADFormatMode::FIRSTVERSION} ;

    return result;
}
