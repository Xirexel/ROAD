#include "SIDEChannelsMixing.h"
#include "IRawDataBuffer.h"
#include "IDoubleDataContainer.h"

void ROADcoder::ROADoverCoder::SIDEChannelsMixing::compute(ROADcoder::ROADoverCoder::IRawDataBuffer* aBuffer) {

    auto lchannelsCount = aBuffer->getCount();

    if(lchannelsCount == 1)
        return;

    if(lchannelsCount == 2)
    {
        IDoubleDataContainer * lptrLeftChannel = aBuffer->getIDoubleDataContainer(0);

        IDoubleDataContainer * lptrRightChannel = aBuffer->getIDoubleDataContainer(1);

        auto lsamplesCount = lptrLeftChannel->getLength();

        auto lptrLeftChannelDouble = lptrLeftChannel->getData();

        auto lptrRightChannnelDouble = lptrRightChannel->getData();

        ROADReal tempValueMID, tempValueSIDE;

        for(decltype(lsamplesCount) index = 0;
            index < lsamplesCount;
            ++index)
        {
            tempValueMID = *lptrLeftChannelDouble + *lptrRightChannnelDouble;

            tempValueSIDE = *lptrLeftChannelDouble - *lptrRightChannnelDouble;


            *lptrLeftChannelDouble = tempValueSIDE * 0.5;

            *lptrRightChannnelDouble = tempValueMID * 0.5;


            lptrLeftChannelDouble++;

            lptrRightChannnelDouble++;
        }

    }


}

