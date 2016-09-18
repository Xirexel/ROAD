#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "Domain.h"
ROADcoder::ROADCoder::Domain::Domain(ROADSize aLength)
    : _dataForwardDirection(new ROADReal[aLength], aLength),
      _dataBackDirection(new ROADReal[aLength], aLength),
      _length(aLength)
{
}

void ROADcoder::ROADCoder::Domain::populate(PtrROADReal aData, ROADSize aDomainLength)
{

    this->_sum = 0.0;

    this->_beta = 0.0;

    ROADUInt32 lrangeLength = aDomainLength >> 1;

    ROADUInt32 loffsetBackDirection = lrangeLength - 1;

    ROADUInt32 lPos = 0;

    for(ROADUInt32 index = 0;
        index < aDomainLength;
        index += 2)
    {
        lPos = index >> 1;

        _tempValue = (aData[index] + aData[index + 1]) * 0.5;

        this->_dataForwardDirection[lPos] = _tempValue;

        this->_dataBackDirection[loffsetBackDirection - lPos] = _tempValue;

        this->_sum += _tempValue;

        this->_beta += _tempValue * _tempValue;
    }

    this->_aver = this->_sum/lrangeLength;

    this->_beta *= lrangeLength;

    this->_beta -= this->_sum * this->_sum;
}


PlatformDependencies::PtrROADReal ROADcoder::ROADCoder::Domain::getForwardDirectionData() {
	return this->_dataForwardDirection;
}

PlatformDependencies::PtrROADReal ROADcoder::ROADCoder::Domain::getBackDirectionData() {
	return this->_dataBackDirection;
}

PlatformDependencies::ROADReal ROADcoder::ROADCoder::Domain::getAver() {
	return this->_aver;
}

PlatformDependencies::ROADReal ROADcoder::ROADCoder::Domain::getSum() {
	return this->_sum;
}

PlatformDependencies::ROADReal ROADcoder::ROADCoder::Domain::getBeta() {
	return this->_beta;
}

PlatformDependencies::ROADSize ROADcoder::ROADCoder::Domain::getLength() {
	return this->_length;
}

ROADcoder::ROADCoder::Domain::~Domain()
{
}
