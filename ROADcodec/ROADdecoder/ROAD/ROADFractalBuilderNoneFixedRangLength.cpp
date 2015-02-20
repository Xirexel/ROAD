#include <string>
#include <vector>
#include <exception>
using namespace std;


#include "ROADFractalFirstOrderBuilderNoneFixedRangLength.h"
#include "IFractalFirstOrderItemContainer.h"
#include "IFractalFirstOrderItem.h"
#include "IFractalAverItem.h"

void ROADdecoder::ROAD::ROADFractalFirstOrderBuilderNoneFixedRangLength::build(PtrROADReal aData, ROADdecoder::ROAD::IFractalFirstOrderItemContainer* aFractalFirstOrderItemContainer) {

    ROADUInt32 countFractalItems = 0;

    PtrROADReal lFramePos = aData;

    ROADUInt32 lmaxCount = aFractalFirstOrderItemContainer->getIFractalAverItemCount();

    while(countFractalItems < lmaxCount)
    {
        IFractalAverItem * item = aFractalFirstOrderItemContainer->getIFractalAverItem(countFractalItems);

        ROADUInt32 lrangeLength = item->getLength();

        ROADUInt32 lrangPosition = item->getPosition();

        ROADReal lAver = item->getAver();

        lFramePos = aData + lrangPosition;

        for(ROADUInt32 index = 0;
                index < lrangeLength;
                ++index)
        {
            *lFramePos = lAver;

            lFramePos++;
        }

        ++countFractalItems;
    }

    lmaxCount = aFractalFirstOrderItemContainer->getIFractalFirstOrderItemCount();

    if(lmaxCount == 0)
        return;

    for(ROADUInt32 index = 0;
        index < 4;
        ++index)
    {

        countFractalItems = 0;

        while(countFractalItems < lmaxCount)
        {
            IFractalFirstOrderItem * item = aFractalFirstOrderItemContainer->getIFractalFirstOrderItem(countFractalItems);

            ROADUInt32 lrangLength = item->getLength();

            ROADUInt32 lrangPosition = item->getPosition();

            ROADReal lAver = item->getAver();

            ROADBool lInversDirection = item->isInversDirection();

            ROADUInt32 lDomainOffset = item->getDomainOffset();

            ROADReal lScale = item->getScale();

            auto lptrDomain = _domainProcessor.process(aData, lrangLength, lInversDirection, lDomainOffset);

            lFramePos = aData + lrangPosition;

            for(ROADUInt32 index = 0;
                    index < lrangLength;
                    ++index)
            {
                ROADReal t = lptrDomain[index] * lScale + lAver;

                *lFramePos = t;

                lFramePos++;
            }

            ++countFractalItems;
        }
    }
}

ROADdecoder::ROAD::ROADFractalFirstOrderBuilderNoneFixedRangLength::~ROADFractalFirstOrderBuilderNoneFixedRangLength()
{

}

ROADdecoder::ROAD::ROADFractalFirstOrderBuilderNoneFixedRangLength::ROADFractalFirstOrderBuilderNoneFixedRangLength(ROADUInt32 aMaxRangeLength)
    :_domainProcessor(DomainProcessorFirstOrderNoneFixedLength(aMaxRangeLength))
{

}
