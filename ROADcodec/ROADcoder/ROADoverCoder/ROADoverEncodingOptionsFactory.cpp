#include "ROADoverEncodingOptionsFactory.h"
#include "ROADoverEncodingOptionsExperemental.h"

#include "ROADFormatMode.h"


std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFactory::getIROADoverEncodingOptions(unsigned int aType) {
    std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions> result;

    switch (aType) {
    case EXPEREMENTAL:

        result.reset(new ROADoverEncodingOptionsExperemental);

        break;
    default:
        break;
    }

    return result;
}

std::vector<unsigned int> ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFactory::getSupportedFormats()
{

    std::vector<unsigned int> result = {EXPEREMENTAL, FIRSTVERSION} ;

    return result;
}
