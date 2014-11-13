#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DomainProcessorNoneFixedLength.h"
ROADdecoder::ROAD::DomainProcessorNoneFixedLength::~DomainProcessorNoneFixedLength() {
    delete []this->_data;
}

ROADdecoder::ROAD::DomainProcessorNoneFixedLength::DomainProcessorNoneFixedLength(unsigned int aMaxLength)
    : _data(new double[aMaxLength])
{
}

double* ROADdecoder::ROAD::DomainProcessorNoneFixedLength::process(double* aData, unsigned int aLength, bool aInversDirection, unsigned int aDomainOffset) {
    double lAver = 0.0;

    double lTmepValue = 0;

    unsigned int lOffset = 0;

    for(unsigned int index = 0;
        index < aLength;
        ++index)
    {
        lOffset = aDomainOffset + (index << 1);

        lTmepValue = (aData[lOffset] + aData[lOffset + 1]) * 0.5;

        lAver += lTmepValue;

        this->_data[index] = lTmepValue;
    }

    lAver /= aLength;

    for(unsigned int index = 0;
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

void ROADdecoder::ROAD::DomainProcessorNoneFixedLength::backFlip(unsigned int aLength) {

    double lTempValue;

    unsigned int lHalfLength = aLength >> 1;

    for(unsigned int index = 0;
        index < lHalfLength;
        ++index)
    {
        lTempValue = this->_data[index];

        this->_data[index] = this->_data[aLength - 1 - index];

        this->_data[aLength - 1 - index] = lTempValue;
    }
}

