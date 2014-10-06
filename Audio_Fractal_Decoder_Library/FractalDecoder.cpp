#include <string>
#include <vector>
#include <exception>
#include <random>
using namespace std;

#include "FractalDecoder.h"
#include "FractalDecodingOptions.h"
#include "SuperFrameFractaItemCollection.h"
#include "DomainProcessor.h"
#include "IFractalDataContainer.h"
#include "IFractalItemContainer.h"
#include "IFractalItem.h"


FractalDecoding::FractalDecoder::FractalDecoder(FractalDecoding::FractalDecodingOptions aOptions)
    : _options(aOptions),
      _superFrameFractalItemCollection(FractalDecoding::SuperFrameFractaItemCollection(aOptions.getSuperFrameLength(), aOptions.getFrameLength(),
                                                                                       aOptions.getFrameLength() * aOptions.getSamplesPerRang())),
      _domainProcessor(FractalDecoding::DomainProcessor(aOptions.getFrameLength() * aOptions.getSamplesPerRang()))
{
}

FractalDecoding::FractalDecoder::~FractalDecoder()
{

}

void FractalDecoding::FractalDecoder::decode(double* aData, FractalDecoding::IFractalDataContainer* aFractalDataContainer) {


    this->_superFrameFractalItemCollection.populate(aFractalDataContainer);

    unsigned int frameCount = 0;

    unsigned int sampleFrameOffset = _options.getFrameLength() * _options.getSamplesPerRang();

    while(frameCount < _options.getSuperFrameLength())
    {
        IFractalItemContainer * lptrIFractalItemContainer = this->_superFrameFractalItemCollection.getIFractalItemContainer(frameCount);

        decodeFrame(aData + frameCount * sampleFrameOffset, lptrIFractalItemContainer);

        ++frameCount;
    }

}

void FractalDecoding::FractalDecoder::decodeFrame(double* aData, FractalDecoding::IFractalItemContainer* aFractalItemContainer) {


    unsigned int samplesShift = 0;

    unsigned int countFractalItems = 0;

    double* lFramePos = aData;

    while(countFractalItems < aFractalItemContainer->getCount())
    {
        IFractalItem * item = aFractalItemContainer->getIFractalItem(countFractalItems);

        unsigned int lrangeLength = item->getLength();

        double lAver = item->getAver();

        for(decltype(lrangeLength) index = 0;
                index < lrangeLength;
                ++index)
        {
            *lFramePos = lAver;

            lFramePos++;
        }

        samplesShift += lrangeLength;

        ++countFractalItems;
    }

#ifdef NON_DETERINETED_DECODING

    // Non-determinated algorithm of decoding

    for(unsigned int index = 0;
        index < 4;
        ++index)
    {
        lFramePos = aData;

        setRangeOfRNG(0, aFractalItemContainer->getCount());

        int indexRange = getRNumber();

        while(indexRange >= 0)
        {
            IFractalItem * item = aFractalItemContainer->getIFractalItem((unsigned int)indexRange);

            unsigned int lrangeLength = item->getLength();

            double lAver = item->getAver();

            unsigned int lPosition = item->getPosition();

            if(!item->isSilence())
            {

                bool lBackDirection = item->isForwardDirection();

                unsigned int lDomainIndex = item->getDomainIndex();

                double lScale = item->getScale();


                double * lptrDomain = _domainProcessor.process(aData, lrangeLength, _options.getSamplesPerRang(), lDomainIndex, _options.getRelativeDomainShift(), _options.getScaleDomainShift(), lBackDirection);


                for(decltype(lrangeLength) index = 0;
                    index < lrangeLength;
                    ++index)
                {
                    double t = lptrDomain[index] * lScale + lAver;

                    lFramePos[lPosition + index] = t;
                }
            }

            indexRange = getRNumber();
        }
    }

#else

    // Determinated algorithm of decoding

    for(unsigned int index = 0;
        index < 4;
        ++index)
    {

        samplesShift = 0;

        countFractalItems = 0;

        lFramePos = aData;

        while(countFractalItems < aFractalItemContainer->getCount())
        {
            IFractalItem * item = aFractalItemContainer->getIFractalItem(countFractalItems);

            unsigned int lrangeLength = item->getLength();

            double lAver = item->getAver();

            if(!item->isSilence())
            {

                bool lBackDirection = item->isForwardDirection();

                unsigned int lDomainIndex = item->getDomainIndex();

                double lScale = item->getScale();


                double * lptrDomain = _domainProcessor.process(aData, lrangeLength, _options.getSamplesPerRang(), lDomainIndex, _options.getRelativeDomainShift(), _options.getScaleDomainShift(), lBackDirection);


                for(decltype(lrangeLength) index = 0;
                    index < lrangeLength;
                    ++index)
                {
                    double t = lptrDomain[index] * lScale + lAver;

                    *lFramePos = t;

                    lFramePos++;
                }
            }
            else
            {
                lFramePos+=lrangeLength;
            }

            samplesShift += lrangeLength;

            ++countFractalItems;
        }
    }

#endif



}

int FractalDecoding::FractalDecoder::getRNumber()
{
    if(_listRN.empty())
        return -1;

    int result = _listRN.back();

    _listRN.pop_back();

    return result;


}

void FractalDecoding::FractalDecoder::setRangeOfRNG(unsigned int aLowBoder, unsigned int aTopBorder)
{
    random_device f;

    typedef random_device::result_type result_type;

    result_type max = f.max();

    while(aLowBoder < aTopBorder)
    {
        result_type value = f();

        float normValue = (float)value / max;

        if(normValue < 0.5)
            this->_listRN.push_back(aLowBoder);
        else
            this->_listRN.push_front(aLowBoder);

        ++aLowBoder;
    }


}
