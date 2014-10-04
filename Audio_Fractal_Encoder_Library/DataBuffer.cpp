#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DataBuffer.h"
FractalEncoding::DataBuffer::DataBuffer(unsigned int aLength)
    :_firstChannel(new double[aLength]),
     _secondChannel(new double[aLength]),
     _length(aLength)
{
}

FractalEncoding::DataBuffer::~DataBuffer()
{
    delete []_firstChannel;

    delete []_secondChannel;
}

double* FractalEncoding::DataBuffer::getFirstChannel() {
	return this->_firstChannel;
}

double* FractalEncoding::DataBuffer::getSecondChannel() {
	return this->_secondChannel;
}

unsigned int FractalEncoding::DataBuffer::getLength() {
	return this->_length;
}

