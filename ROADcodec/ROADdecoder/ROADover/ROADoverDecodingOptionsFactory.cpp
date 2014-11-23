#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverDecodingOptionsFactory.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "EndianConvertor.h"

void ROADdecoder::ROADover::ROADoverDecodingOptionsFactory::getIROADoverDecodingOptions(unsigned char* aData,
                                                                                                                                    unsigned int aLength)
{
    shared_ptr<ROADdecoder::ROADover::IROADoverDecodingOptions> result;

    unsigned int formatMode = Endian::EndianConvertor::getInstance().convertToUINT32(aData);

    if(formatMode == 0)
    {
        result.reset(new ROADoverDecodingOptionsExperemental(aData, aLength));
    }

  //  return result;
}
