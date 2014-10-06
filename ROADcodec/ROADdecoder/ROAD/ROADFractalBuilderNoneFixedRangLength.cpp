#include <string>
#include <vector>
#include <exception>
using namespace std;


#include "ROADFractalFirstOrderBuilderNoneFixedRangLength.h"
#include "IFractalFirstOrderItemContainer.h"
#include "IFractalFirstOrderItem.h"
#include "IFractalAverItem.h"

void ROADdecoder::ROAD::ROADFractalFirstOrderBuilderNoneFixedRangLength::build(double* aData, ROADdecoder::ROAD::IFractalFirstOrderItemContainer* aFractalFirstOrderItemContainer) {

    unsigned int countFractalItems = 0;

    double* lFramePos = aData;

    unsigned int lmaxCount = aFractalFirstOrderItemContainer->getIFractalAverItemCount();

    while(countFractalItems < lmaxCount)
    {
        IFractalAverItem * item = aFractalFirstOrderItemContainer->getIFractalAverItem(countFractalItems);

        unsigned int lrangeLength = item->getLength();

        unsigned int lrangPosition = item->getPosition();

        double lAver = item->getAver();

        lFramePos = aData + lrangPosition;

        for(unsigned int index = 0;
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

    for(unsigned int index = 0;
        index < 4;
        ++index)
    {

        countFractalItems = 0;

        while(countFractalItems < lmaxCount)
        {
            IFractalFirstOrderItem * item = aFractalFirstOrderItemContainer->getIFractalFirstOrderItem(countFractalItems);

            unsigned int lrangLength = item->getLength();

            unsigned int lrangPosition = item->getPosition();

            double lAver = item->getAver();

            bool lInversDirection = item->isInversDirection();

            unsigned int lDomainOffset = item->getDomainOffset();

            double lScale = item->getScale();

            double * lptrDomain = _domainProcessor.process(aData, lrangLength, lInversDirection, lDomainOffset);

            lFramePos = aData + lrangPosition;

            for(unsigned int index = 0;
                    index < lrangLength;
                    ++index)
            {
                double t = lptrDomain[index] * lScale + lAver;

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

ROADdecoder::ROAD::ROADFractalFirstOrderBuilderNoneFixedRangLength::ROADFractalFirstOrderBuilderNoneFixedRangLength(unsigned int aMaxRangeLength)
    :_domainProcessor(DomainProcessorFirstOrderNoneFixedLength(aMaxRangeLength))
{

}
