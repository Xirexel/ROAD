#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADFractalBuilderFactory.h"
#include "ROADFractalBuilderNoneFixedRangLength.h"

ROADdecoder::ROAD::IROADFractalBuilder* ROADdecoder::ROAD::ROADFractalBuilderFactory::getIROADFractalBuilder(unsigned int aMaxRangeLength)
{
    ROADdecoder::ROAD::IROADFractalBuilder* result = new ROADFractalBuilderNoneFixedRangLength(aMaxRangeLength);

    return result;
}
