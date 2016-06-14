#include "SIDEChannelsMixing.h"
#include "IRawDataBuffer.h"
#include "IRealDataContainer.h"

void ROADcoder::ROADoverCoder::SIDEChannelsMixing::compute(ROADcoder::ROADoverCoder::IRawDataBuffer* aBuffer) {

    auto lchannelsCount = aBuffer->getCount();

    if(lchannelsCount == 1)
        return;

    if(lchannelsCount == 2)
    {
        IRealDataContainer * lptrLeftChannel = aBuffer->getIRealDataContainer(0);

        IRealDataContainer * lptrRightChannel = aBuffer->getIRealDataContainer(1);

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

