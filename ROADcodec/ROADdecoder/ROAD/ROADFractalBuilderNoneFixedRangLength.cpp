#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADFractalBuilderNoneFixedRangLength.h"
#include "IFractalItemContainer.h"
#include "IFractalItem.h"
#include "IFractalAverItem.h"

void ROADdecoder::ROAD::ROADFractalBuilderNoneFixedRangLength::build(double* aData, ROADdecoder::ROAD::IFractalItemContainer* aFractalItemContainer) {

    unsigned int countFractalItems = 0;

    double* lFramePos = aData;

    unsigned int lmaxCount = aFractalItemContainer->getIFractalAverItemCount();

    while(countFractalItems < lmaxCount)
    {
        IFractalAverItem * item = aFractalItemContainer->getIFractalAverItem(countFractalItems);

        unsigned int lrangeLength = item->getLength();

        double lAver = item->getAver();

        for(unsigned int index = 0;
                index < lrangeLength;
                ++index)
        {
            *lFramePos = lAver;

            lFramePos++;
        }

        ++countFractalItems;
    }

    lmaxCount = aFractalItemContainer->getIFractalItemCount();

    for(unsigned int index = 0;
        index < 4;
        ++index)
    {

        countFractalItems = 0;

        while(countFractalItems < lmaxCount)
        {
            IFractalItem * item = aFractalItemContainer->getIFractalItem(countFractalItems);

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

