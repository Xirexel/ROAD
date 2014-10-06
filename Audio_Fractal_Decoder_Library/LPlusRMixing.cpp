#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "LPlusRMixing.h"
#include "IMixing.h"

void FractalDecoding::LPlusRMixing::compute(double* aFirstChannel, double* aSecondChannel, unsigned int aLength) {


    while(aLength > 0)
    {
        double sampleOfLeftChannel = (*aFirstChannel) + (*aSecondChannel);

        double sampleOfRightChannel = (*aFirstChannel) - (*aSecondChannel);

        *aFirstChannel = sampleOfLeftChannel;

        *aSecondChannel = sampleOfRightChannel;


        ++aFirstChannel;

        ++aSecondChannel;

        --aLength;
    }

}

