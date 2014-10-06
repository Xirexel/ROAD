#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalEncoder.h"
#include "ROADEncodingOptions.h"
#include "SuperFrameFractalItemCollection.h"
#include "DomainPool.h"
#include "IROADDataContainer.h"

ROADEncoding::IROADDataContainer* ROADEncoding::FractalEncoder::encode(double* aData) {

    unsigned int lFrameOffset = 0;

    for(decltype (_options.getSuperFrameLength()) index = 0;
        index < _options.getSuperFrameLength();
        ++index)
    {
        lFrameOffset = index * _options.getFrameSampleLength();

        IFrameFractalItemCollection* lptrFractalItemCollection = _superFrameFractalItemCollections.at(0)->getIFrameFractalItemCollection(index);

        populateDomainPools(aData + lFrameOffset);

        silenceMatch(aData + lFrameOffset, _options.getFrameSampleLength(), lptrFractalItemCollection);
    }

    return _superFrameFractalItemCollections.at(0)->getIFractalDataContainer();
}

void ROADEncoding::FractalEncoder::silenceMatch(double* aData, unsigned int aSilenceSampleLength, ROADEncoding::IFrameFractalItemCollection* aPtrFrameFractalItemCollection) {

    double laver = computeSumValue(aData, aSilenceSampleLength);

    laver /= aSilenceSampleLength;

    double ldev = computeDeviationValue(aData, aSilenceSampleLength, laver);

    if( ldev > _options.getSilenceThreshold())
    {
        auto subLength = aSilenceSampleLength >> 1;

        if(subLength > _options.getRangeTopSampleLength())
        {
            silenceMatch(aData, subLength, aPtrFrameFractalItemCollection);

            silenceMatch(aData + subLength, subLength, aPtrFrameFractalItemCollection);
        }
        else
        {
            rangeMatch(aData, subLength, _options.getAmountRangeLevels(), aPtrFrameFractalItemCollection);

            rangeMatch(aData + subLength, subLength, _options.getAmountRangeLevels(), aPtrFrameFractalItemCollection);
        }

    }
    else
    {
        IFractalItem* lptrIFractalItem = aPtrFrameFractalItemCollection->getNextIFractalItem();

        lptrIFractalItem->setSilence(true);

        lptrIFractalItem->setAver(laver);

        unsigned int lLength = aSilenceSampleLength/ (_options.getRangeTopSampleLength() / (1 << _options.getAmountRangeLevels()));

        unsigned int index = log2(static_cast<double>(lLength));

        lptrIFractalItem->setIndex(index);
    }


}

void ROADEncoding::FractalEncoder::rangeMatch(double* aData, unsigned int aRangeLength, unsigned int aDeepthIndex, ROADEncoding::IFrameFractalItemCollection* aPtrFrameFractalItemCollection) {

    double lRangSum = computeSumValue(aData, aRangeLength);

    double lRangAver = lRangSum / aRangeLength;

    bool lDirection = false;

    unsigned int lDomain = 0;

    double lScale = 0.0f;

    DomainPool *lptrDomainPool = _domainPools.at(aDeepthIndex);

    unsigned int countDomains = lptrDomainPool->getSize();



    double leastError = std::numeric_limits<double>::max();

    for(unsigned int lDomainIndex = 0;
        lDomainIndex < countDomains;
        ++lDomainIndex)
    {
        IDomain *lptrIDomain = lptrDomainPool->getIDomain(lDomainIndex);

        double lBeta = lptrIDomain->getBeta();

        if(lBeta == 0.0)
            continue;

        double lDomainSum = lptrIDomain->getSum();

        double lDomainAver = lptrIDomain->getAver();

        double lTempValue;



        const double *lptrDomainData = lptrIDomain->getForwardDirectionData();

        double lForwardDirectionError = 0.0;

        double lForwardDirectionScale = 0.0;

        double lForwardDirectionValueOffset = 0.0;



        double lAlpha = computeAlpha(aData, lptrDomainData, aRangeLength, lRangSum, lDomainSum);

        lForwardDirectionScale = lAlpha/lBeta;

        if(lForwardDirectionScale > 0.996)
            lForwardDirectionScale = 0.996;
        else if(lForwardDirectionScale < -0.996)
            lForwardDirectionScale = -0.996;

        int ldecinScale = lForwardDirectionScale * 255.0;

        lForwardDirectionScale = static_cast<double>(ldecinScale) / 255.0;

        lForwardDirectionValueOffset = lRangAver - lForwardDirectionScale * lDomainAver;


        for(unsigned int index = 0;
            index < aRangeLength;
            ++index)
        {
            lTempValue = lptrDomainData[index] * lForwardDirectionScale + lForwardDirectionValueOffset - aData[index];

            lTempValue = lTempValue * lTempValue;

            lForwardDirectionError += lTempValue;

        }





        lptrDomainData = lptrIDomain->getBackDirectionData();

        double lBackDirectionError = 0.0;

        double lBackDirectionScale = 0.0;

        double lBackDirectionValueOffset = 0.0;


        lAlpha = computeAlpha(aData, lptrDomainData, aRangeLength, lRangSum, lDomainSum);

        lBackDirectionScale = lAlpha/lBeta;

        if(lBackDirectionScale > 0.996)
            lBackDirectionScale = 0.996;
        else if(lBackDirectionScale < -0.996)
            lBackDirectionScale = -0.996;

        ldecinScale = lBackDirectionScale * 255.0;

        lBackDirectionScale = static_cast<double>(ldecinScale) / 255.0;

        lBackDirectionValueOffset = lRangAver - lBackDirectionScale * lDomainAver;




        for(unsigned int index = 0;
            index < aRangeLength;
            ++index)
        {
            lTempValue = lptrDomainData[index] * lBackDirectionScale + lBackDirectionValueOffset - aData[index];

            lTempValue = lTempValue * lTempValue;

            lBackDirectionError += lTempValue;
        }




        lTempValue = lForwardDirectionError;                

        bool lTempDirection = false;

        double lTempScale = lForwardDirectionScale;

        if(lForwardDirectionError > lBackDirectionError)
        {
            lTempValue = lBackDirectionError;

            lTempDirection = true;

            lTempScale = lBackDirectionScale;
        }


        if(leastError > lTempValue)
        {
            leastError = lTempValue;

            lDirection = lTempDirection;

            lDomain = lDomainIndex;

            lScale = lTempScale;
        }

    }

    if(aDeepthIndex == 0 || _options.getRangeThreshold() > leastError)
    {
        IFractalItem* lptrIFractalItem = aPtrFrameFractalItemCollection->getNextIFractalItem();

        lptrIFractalItem->setSilence(false);

        lptrIFractalItem->setAver(lRangAver);

        lptrIFractalItem->setDirection(lDirection);

        lptrIFractalItem->setDomain(lDomain);

        lptrIFractalItem->setScale(lScale);

        unsigned int index = aDeepthIndex;

        lptrIFractalItem->setIndex(index);
    }
    else
    {
        auto subLength = aRangeLength >> 1;

        auto lDeepthIndex = aDeepthIndex - 1;

        rangeMatch(aData, subLength, lDeepthIndex, aPtrFrameFractalItemCollection);

        rangeMatch(aData + subLength, subLength, lDeepthIndex, aPtrFrameFractalItemCollection);
    }
}

double ROADEncoding::FractalEncoder::computeSumValue(double* aData, unsigned int aLength) {

    double laver = 0.0;

    for(decltype(aLength) index = 0;
        index < aLength;
        ++index)
        laver += aData[index];

    return laver;
}

double ROADEncoding::FractalEncoder::computeDeviationValue(double* aData, unsigned int aLength, double aAverValue) {

    double ldev = 0.0;

    double ltemp = 0.0;

    for(decltype(aLength) index = 0;
        index < aLength;
        ++index)
    {
        ltemp = aData[index] - aAverValue;

        ltemp *= ltemp;

        ldev += ltemp;
    }

    ldev /= aLength;

    return ldev;
}

void ROADEncoding::FractalEncoder::populateDomainPools(double* aData)
{
    for(ROADEncoding::DomainPool* item: _domainPools)
         item->populate(aData);
}

ROADEncoding::FractalEncoder::FractalEncoder(ROADEncoding::ROADEncodingOptions aOptions)
    : _options(aOptions)
{
    _superFrameFractalItemCollections.push_back(
                new ROADEncoding::SuperFrameFractalItemCollection(aOptions.getSuperFrameLength(),
                                                                     (aOptions.getFrameSampleLength() / aOptions.getRangeTopSampleLength()) * (1 << aOptions.getAmountRangeLevels())));

    unsigned lTopDomainLength = aOptions.getRangeTopSampleLength() / (1 << aOptions.getAmountRangeLevels());


    for(decltype(aOptions.getAmountRangeLevels()) index = 0;
        index <= aOptions.getAmountRangeLevels();
        ++index)
    {
        lTopDomainLength *= 2;

        unsigned int lDomainPoolSize = aOptions.getFrameSampleLength() - lTopDomainLength + 1;

        _domainPools.push_back( new ROADEncoding::DomainPool(lDomainPoolSize, lTopDomainLength, aOptions.getDomainShift()));
    }





}

ROADEncoding::FractalEncoder::~FractalEncoder()
{
    for(ROADEncoding::SuperFrameFractalItemCollection* item: _superFrameFractalItemCollections)
        delete item;

    _superFrameFractalItemCollections.clear();


    for(ROADEncoding::DomainPool* item: _domainPools)
        delete item;

    _domainPools.clear();

}

double ROADEncoding::FractalEncoder::computeAlpha(const double* aDataRang,
                                                     const double* aDataDomain,
                                                     unsigned int aLength,
                                                     double aSumRang,
                                                     double aSumDomain)
{
    double result = 0.0;

    for(unsigned int index = 0;
        index < aLength;
        ++index)
    {
        result += aDataRang[index] * aDataDomain[index];
    }

    result *= aLength;

    result -= aSumRang * aSumDomain;

    return result;
}
