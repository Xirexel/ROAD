#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "NoneMixingChannels.h"
#include "IRawDataBuffer.h"
#include "IMixingChannels.h"
// used to avoid warnings of unused parameters
#define UNUSED(x) (void)x;

void ROADoverEncoding::NoneMixingChannels::compute(ROADoverEncoding::IRawDataBuffer* aBuffer) {
    UNUSED(aBuffer)
	throw "Not yet implemented";
}

