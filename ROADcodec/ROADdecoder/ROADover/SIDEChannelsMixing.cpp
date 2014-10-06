#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "SIDEChannelsMixing.h"
#include "IRawDataBuffer.h"
#include "IDoubleDataContainer.h"

void ROADdecoder::ROADover::SIDEChannelsMixing::compute(ROADdecoder::ROADover::IRawDataBuffer* aBuffer) {
    auto lchannelsCount = aBuffer->getCount();

    if(lchannelsCount == 1)
        return;

    if(lchannelsCount == 2)
    {
        IDoubleDataContainer * lptrMID = aBuffer->getIDoubleDataContainer(0);

        IDoubleDataContainer * lptrSIDE = aBuffer->getIDoubleDataContainer(1);

        auto lsamplesCount = lptrMID->getCount();

        double *lptrMIDDouble = lptrMID->getData();

        double *lptrSIDEDouble = lptrSIDE->getData();

        double tempValueL, tempValueR;

        for(decltype(lsamplesCount) index = 0;
            index < lsamplesCount;
            ++index)
        {
            tempValueL = *lptrMIDDouble + *lptrSIDEDouble;

            tempValueR = *lptrMIDDouble - *lptrSIDEDouble;


            *lptrMIDDouble = tempValueR;

            *lptrSIDEDouble = tempValueL;


            lptrMIDDouble++;

            lptrSIDEDouble++;
        }

    }

}

