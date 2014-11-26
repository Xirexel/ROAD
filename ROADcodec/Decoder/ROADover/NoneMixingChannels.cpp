#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "NoneMixingChannels.h"
#include "IRawDataBuffer.h"
#include "IChannelsMixing.h"
// used to avoid warnings of unused parameters
#define UNUSED(x) (void)x;

void ROADover::NoneMixingChannels::compute(ROADover::IRawDataBuffer* aBuffer) {
UNUSED(aBuffer)

}

ROADover::NoneMixingChannels::~NoneMixingChannels()
{

}
