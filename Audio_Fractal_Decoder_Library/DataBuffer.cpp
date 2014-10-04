#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DataBuffer.h"
FractalDecoding::DataBuffer::DataBuffer(unsigned int aLength)
    : _firstChannelData(new double[aLength]),
      _secondChannelData(new double[aLength]),
      _length(aLength)

{
}

FractalDecoding::DataBuffer::~DataBuffer()
{
    delete []_firstChannelData;

    delete []_secondChannelData;

}

double* FractalDecoding::DataBuffer::getFirstChannelData() {
	return this->_firstChannelData;
}

double* FractalDecoding::DataBuffer::getSecondChannelData() {
	return this->_secondChannelData;
}

unsigned int FractalDecoding::DataBuffer::getLength() {
	return this->_length;
}

