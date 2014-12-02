#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverDecodingOptionsFactory.h"
#include "ROADoverDecodingOptionsExperemental.h"


ROADdecoder::ROADover::IROADoverDecodingOptions *ROADdecoder::ROADover::ROADoverDecodingOptionsFactory::getIROADoverDecodingOptions(unique_ptr<Driver::IDataReadDriver> &aPtrIDataReadDriver)
{
    ROADdecoder::ROADover::IROADoverDecodingOptions* result = nullptr;

    unsigned int formatMode = 0;

    aPtrIDataReadDriver.get()->operator >>(formatMode);

    if(formatMode == 0)
    {
        result = new ROADoverDecodingOptionsExperemental(aPtrIDataReadDriver);
    }

    return result;
}
