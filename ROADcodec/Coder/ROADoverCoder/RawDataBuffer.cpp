#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "RawDataBuffer.h"
#include "DoubleDataContainer.h"
#include "IRawDataBuffer.h"
// used to avoid warnings of unused parameters
#define UNUSED(x) (void)x;

double* ROADoverEncoding::RawDataBuffer::getData(unsigned int aIndex) {
    UNUSED(aIndex)
	throw "Not yet implemented";
}

unsigned int ROADoverEncoding::RawDataBuffer::getCount() {
	throw "Not yet implemented";
}

ROADoverEncoding::RawDataBuffer::RawDataBuffer(unsigned int aCount, unsigned int aLength) {
    UNUSED(aCount)
    UNUSED(aLength)
}

