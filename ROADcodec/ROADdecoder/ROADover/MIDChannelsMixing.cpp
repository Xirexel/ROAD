#include "MIDChannelsMixing.h"
#include "IRawDataBuffer.h"
#include "IDoubleDataContainer.h"

void ROADdecoder::ROADover::MIDChannelsMixing::compute(ROADdecoder::ROADover::IRawDataBuffer* aBuffer) {

    auto lchannelsCount = aBuffer->getCount();

    if(lchannelsCount == 1)
        return;

    if(lchannelsCount == 2)
    {
        auto lptrMID = aBuffer->getIDoubleDataContainer(0);

        auto lptrSIDE = aBuffer->getIDoubleDataContainer(1);

        auto lsamplesCount = lptrMID->getCount();

        auto lptrMIDDouble = lptrMID->getData();

        auto lptrSIDEDouble = lptrSIDE->getData();

        ROADReal tempValueL, tempValueR;

        for(decltype(lsamplesCount) index = 0;
            index < lsamplesCount;
            ++index)
        {
            tempValueL = *lptrMIDDouble + *lptrSIDEDouble;

            tempValueR = *lptrMIDDouble - *lptrSIDEDouble;


            *lptrMIDDouble = tempValueL;

            *lptrSIDEDouble = tempValueR;


            lptrMIDDouble++;

            lptrSIDEDouble++;
        }

    }

}

