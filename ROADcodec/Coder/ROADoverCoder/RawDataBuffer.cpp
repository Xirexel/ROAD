#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "RawDataBuffer.h"
#include "DoubleDataContainer.h"
#include "IRawDataBuffer.h"

double* ROADoverEncoding::RawDataBuffer::getData(unsigned int aIndex) {
	throw "Not yet implemented";
}

unsigned int ROADoverEncoding::RawDataBuffer::getCount() {
	throw "Not yet implemented";
}

ROADoverEncoding::RawDataBuffer::RawDataBuffer(unsigned int aCount, unsigned int aLength) {
}

