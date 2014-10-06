#include "MIDChannelsMixing.h"
#include "IRawDataBuffer.h"
#include "IDoubleDataContainer.h"

void ROADcoder::ROADoverCoder::MIDChannelsMixing::compute(ROADcoder::ROADoverCoder::IRawDataBuffer* aBuffer) {

    auto lchannelsCount = aBuffer->getCount();

    if(lchannelsCount == 1)
        return;

    if(lchannelsCount == 2)
    {
        IDoubleDataContainer * lptrLeftChannel = aBuffer->getIDoubleDataContainer(0);

        IDoubleDataContainer * lptrRightChannel = aBuffer->getIDoubleDataContainer(1);

        auto lsamplesCount = lptrLeftChannel->getLength();

        double *lptrLeftChannelDouble = lptrLeftChannel->getData();

        double *lptrRightChannnelDouble = lptrRightChannel->getData();

        double tempValueMID, tempValueSIDE;

        for(decltype(lsamplesCount) index = 0;
            index < lsamplesCount;
            ++index)
        {
            tempValueMID = *lptrLeftChannelDouble + *lptrRightChannnelDouble;

            tempValueSIDE = *lptrLeftChannelDouble - *lptrRightChannnelDouble;


            *lptrLeftChannelDouble = tempValueMID * 0.5;

            *lptrRightChannnelDouble = tempValueSIDE * 0.5;


            lptrLeftChannelDouble++;

            lptrRightChannnelDouble++;
        }

    }


}

