#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverDecodingOptionsFactory.h"

ROADdecoder::ROADover::IROADoverDecodingOptions* ROADdecoder::ROADover::ROADoverDecodingOptionsFactory::getIROADoverDecodingOptions(unsigned char* aData,
                                                                                                                                    unsigned int aLength)
{
    ROADdecoder::ROADover::IROADoverDecodingOptions* result = nullptr;

    if(aData[0] == 0
       && aData[1] == 0
       && aData[2] == 0
       && aData[3] == 0)
    {

    }

    return result;
}
