#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "Domain.h"
ROADcoder::ROADCoder::Domain::Domain(unsigned int aLength)
    : _dataForwardDirection(new double[aLength]),
      _dataBackDirection(new double[aLength]),
      _length(aLength)
{
}

void ROADcoder::ROADCoder::Domain::populate(double* aData, unsigned int aDoubleLength)
{

    this->_sum = 0.0;

    this->_beta = 0.0;

    unsigned int lrangeLength = aDoubleLength >> 1;

    unsigned int loffsetDackDirection = lrangeLength - 1;

    unsigned int lPos = 0;

    for(unsigned int index = 0;
        index < aDoubleLength;
        index += 2)
    {
        lPos = index >> 1;

        _tempValue = (aData[index] + aData[index + 1]) * 0.5;

        this->_dataForwardDirection[lPos] = _tempValue;

        this->_dataBackDirection[loffsetDackDirection - lPos] = _tempValue;

        this->_sum += _tempValue;

        this->_beta += _tempValue * _tempValue;
    }

    this->_aver = this->_sum/lrangeLength;

    this->_beta *= lrangeLength;

    this->_beta -= this->_sum * this->_sum;
}


const double* ROADcoder::ROADCoder::Domain::getForwardDirectionData() {
	return this->_dataForwardDirection;
}

const double* ROADcoder::ROADCoder::Domain::getBackDirectionData() {
	return this->_dataBackDirection;
}

double ROADcoder::ROADCoder::Domain::getAver() {
	return this->_aver;
}

double ROADcoder::ROADCoder::Domain::getSum() {
	return this->_sum;
}

double ROADcoder::ROADCoder::Domain::getBeta() {
	return this->_beta;
}

unsigned int ROADcoder::ROADCoder::Domain::getLength() {
	return this->_length;
}

ROADcoder::ROADCoder::Domain::~Domain()
{
    delete[] this->_dataForwardDirection;

    delete[] this->_dataBackDirection;
}
