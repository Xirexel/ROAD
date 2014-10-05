#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DataBuffer.h"
ROADEncoding::DataBuffer::DataBuffer(unsigned int aLength)
    :_data(new double[aLength]),
     _length(aLength)
{
}

ROADEncoding::DataBuffer::~DataBuffer()
{
    delete []_data;
}

double* ROADEncoding::DataBuffer::getData() {
    return this->_data;
}

unsigned int ROADEncoding::DataBuffer::getLength() {
	return this->_length;
}

