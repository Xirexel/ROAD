#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "LplusRMixing.h"
#include "IMixingChannels.h"

void FractalEncoding::LplusRMixing::compute(double* aFirstChannel, double* aSecondChannel, unsigned int aLength) {


    for(decltype(aLength) index = 0;
        index < aLength;
        ++index)
    {
        double aver = aFirstChannel[index] + aSecondChannel[index];

        aver *= 0.5;

        double diff = aFirstChannel[index] - aSecondChannel[index];

        diff *= 0.5;

        aFirstChannel[index] = aver;

        aSecondChannel[index] = diff;
    }
}

FractalEncoding::LplusRMixing::~LplusRMixing()
{

}
