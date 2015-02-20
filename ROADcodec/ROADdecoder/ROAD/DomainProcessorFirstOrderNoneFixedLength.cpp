#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DomainProcessorFirstOrderNoneFixedLength.h"
ROADdecoder::ROAD::DomainProcessorFirstOrderNoneFixedLength::~DomainProcessorFirstOrderNoneFixedLength() {
    delete []this->_data;
}

ROADdecoder::ROAD::DomainProcessorFirstOrderNoneFixedLength::DomainProcessorFirstOrderNoneFixedLength(ROADUInt32 aMaxLength)
    : _data(new ROADReal[aMaxLength])
{
}

PlatformDependencies::PtrROADReal ROADdecoder::ROAD::DomainProcessorFirstOrderNoneFixedLength::process(PtrROADReal aData, ROADUInt32 aLength, ROADBool aInversDirection, ROADUInt32 aDomainOffset) {
    ROADReal lAver = 0.0;

    ROADReal lTmepValue = 0;

    ROADUInt32 lOffset = 0;

    for(ROADUInt32 index = 0;
        index < aLength;
        ++index)
    {
        lOffset = aDomainOffset + (index << 1);

        lTmepValue = (aData[lOffset] + aData[lOffset + 1]) * 0.5;

        lAver += lTmepValue;

        this->_data[index] = lTmepValue;
    }

    lAver /= aLength;

    for(ROADUInt32 index = 0;
        index < aLength;
        ++index)
    {
        this->_data[index] = this->_data[index] - lAver;
    }

    if(aInversDirection)
    {
        backFlip(aLength);
    }

    return this->_data;
}

void ROADdecoder::ROAD::DomainProcessorFirstOrderNoneFixedLength::backFlip(ROADUInt32 aLength) {

    ROADReal lTempValue;

    ROADUInt32 lHalfLength = aLength >> 1;

    for(ROADUInt32 index = 0;
        index < lHalfLength;
        ++index)
    {
        lTempValue = this->_data[index];

        this->_data[index] = this->_data[aLength - 1 - index];

        this->_data[aLength - 1 - index] = lTempValue;
    }
}

