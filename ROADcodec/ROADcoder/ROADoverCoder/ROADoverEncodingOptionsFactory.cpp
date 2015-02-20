#include "ROADoverEncodingOptionsFactory.h"
#include "ROADoverEncodingOptionsExperemental.h"
#include "ROADoverEncodingOptionsFirstVersion.h"

#include "ROADFormatMode.h"


std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFactory::getIROADoverEncodingOptions(ROADUInt32 aType) {
    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> result;

    switch (aType) {
    case EXPEREMENTAL:

        result.reset(new ROADoverEncodingOptionsExperemental);

        break;
    case FIRSTVERSION:

        result.reset(new ROADoverEncodingOptionsFirstVersion);

        break;
    default:
        break;
    }

    return result;
}

std::vector<PlatformDependencies::ROADUInt32> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFactory::getSupportedFormats()
{

    std::vector<ROADUInt32> result = {EXPEREMENTAL, FIRSTVERSION} ;

    return result;
}
