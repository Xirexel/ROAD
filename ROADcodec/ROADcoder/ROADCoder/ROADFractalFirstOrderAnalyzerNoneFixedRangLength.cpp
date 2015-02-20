#include <string>
#include <vector>
#include <exception>
#include <math.h>
#include <limits>

#include "ROADFractalFirstOrderAnalyzerNoneFixedRangLength.h"
#include "DomainPool.h"
#include "Domain.h"
#include "IFractalFirstOrderItemContainer.h"
#include "IFractalEncodingOptions.h"
#include "IFractalFirstOrderItem.h"
#include "IFractalAverItem.h"


ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::ROADFractalFirstOrderAnalyzerNoneFixedRangLength(ROADcoder::ROADCoder::IFractalEncodingOptions *aOptions)
    : _amountRangLevels(aOptions->getAmountRangLevels()),
      _domainShift(aOptions->getDomainShift()),
      _frameSampleLength(aOptions->getFrameSampleLength()),
      _rangTopSampleLength(aOptions->getRangTopSampleLength()),
      _rangThreshold(aOptions->getRangThreshold()),
      _silenceThreshold(aOptions->getSilenceThreshold())
{
    auto lTopDomainLength = this->_rangTopSampleLength / (1 << this->_amountRangLevels);


    for(decltype(this->_amountRangLevels) index = 0;
        index <= this->_amountRangLevels;
        ++index)
    {
        lTopDomainLength *= 2;

        ROADUInt32 lDomainPoolSize = this->_frameSampleLength - lTopDomainLength + 1;

        _domainPools.push_back( new ROADcoder::ROADCoder::DomainPool(lDomainPoolSize, lTopDomainLength, this->_domainShift));
    }

}

void ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::analyze(PtrROADReal aData, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalItemContainer) {

    this->_currentPosition = 0;

    populateDomainPools(aData);

    silenceMatch(aData, this->_frameSampleLength, aFractalItemContainer);
}

void ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::silenceMatch(PtrROADReal aData, ROADUInt32 aSilenceSampleLength, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalItemContainer) {


    ROADReal laver = computeSumValue(aData, aSilenceSampleLength);

    laver /= aSilenceSampleLength;

    ROADReal ldev = computeDeviationValue(aData, aSilenceSampleLength, laver);

    if( ldev > this->_silenceThreshold)
    {
        auto subLength = aSilenceSampleLength >> 1;

        if(subLength > this->_rangTopSampleLength)
        {
            silenceMatch(aData, subLength, aFractalItemContainer);

            silenceMatch(aData + subLength, subLength, aFractalItemContainer);
        }
        else
        {
            domainIntoRangMatch(aData, subLength, this->_amountRangLevels, aFractalItemContainer);

            domainIntoRangMatch(aData + subLength, subLength, this->_amountRangLevels, aFractalItemContainer);
        }

    }
    else
    {
        IFractalAverItem* lptrIFractalAverItem = aFractalItemContainer->getIFractalAverItem();

        lptrIFractalAverItem ->setAver(laver);

        ROADUInt32 lLength = aSilenceSampleLength / (this->_rangTopSampleLength / (1 << this->_amountRangLevels));

        lptrIFractalAverItem->setLength(lLength);

        this->_currentPosition += lLength;

        ROADUInt32 index = log2(static_cast<double>(lLength));

        index |= 128;

        lptrIFractalAverItem->setIndex(index);
    }




}

void ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::domainIntoRangMatch(PtrROADReal aData, ROADUInt32 aRangSampleLength, ROADUInt32 aDeepthIndex, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalItemContainer) {

    ROADReal lRangSum = computeSumValue(aData, aRangSampleLength);

    ROADReal lRangAver = lRangSum / aRangSampleLength;

    ROADBool lDirection = false;

    ROADUInt32 lDomain = 0;

    ROADReal lScale = 0.0f;

    DomainPool *lptrDomainPool = _domainPools.at(aDeepthIndex);

    ROADUInt32 countDomains = lptrDomainPool->getSize();



    ROADReal leastError = std::numeric_limits<double>::max();

    for(ROADUInt32 lDomainIndex = 0;
        lDomainIndex < countDomains;
        ++lDomainIndex)
    {
        Domain *lptrIDomain = lptrDomainPool->getDomain(lDomainIndex);

        ROADReal lBeta = lptrIDomain->getBeta();

        if(lBeta == 0.0)
            continue;

        ROADReal lDomainSum = lptrIDomain->getSum();

        ROADReal lDomainAver = lptrIDomain->getAver();

        ROADReal lTempValue;



        PtrROADReal lptrDomainData = lptrIDomain->getForwardDirectionData();

        ROADReal lForwardDirectionError = 0.0;

        ROADReal lForwardDirectionScale = 0.0;

        ROADReal lForwardDirectionValueOffset = 0.0;



        ROADReal lAlpha = computeAlpha(aData, lptrDomainData, aRangSampleLength, lRangSum, lDomainSum);

        lForwardDirectionScale = lAlpha/lBeta;

        if(lForwardDirectionScale > 0.996)
            lForwardDirectionScale = 0.996;
        else if(lForwardDirectionScale < -0.996)
            lForwardDirectionScale = -0.996;

        ROADInt32 ldecinScale = lForwardDirectionScale * 255.0;

        lForwardDirectionScale = static_cast<double>(ldecinScale) / 255.0;

        lForwardDirectionValueOffset = lRangAver - lForwardDirectionScale * lDomainAver;


        for(ROADUInt32 index = 0;
            index < aRangSampleLength;
            ++index)
        {
            lTempValue = lptrDomainData[index] * lForwardDirectionScale + lForwardDirectionValueOffset - aData[index];

            lTempValue = lTempValue * lTempValue;

            lForwardDirectionError += lTempValue;

        }





        lptrDomainData = lptrIDomain->getBackDirectionData();

        ROADReal lBackDirectionError = 0.0;

        ROADReal lBackDirectionScale = 0.0;

        ROADReal lBackDirectionValueOffset = 0.0;


        lAlpha = computeAlpha(aData, lptrDomainData, aRangSampleLength, lRangSum, lDomainSum);

        lBackDirectionScale = lAlpha/lBeta;

        if(lBackDirectionScale > 0.996)
            lBackDirectionScale = 0.996;
        else if(lBackDirectionScale < -0.996)
            lBackDirectionScale = -0.996;

        ldecinScale = lBackDirectionScale * 255.0;

        lBackDirectionScale = static_cast<double>(ldecinScale) / 255.0;

        lBackDirectionValueOffset = lRangAver - lBackDirectionScale * lDomainAver;




        for(ROADUInt32 index = 0;
            index < aRangSampleLength;
            ++index)
        {
            lTempValue = lptrDomainData[index] * lBackDirectionScale + lBackDirectionValueOffset - aData[index];

            lTempValue = lTempValue * lTempValue;

            lBackDirectionError += lTempValue;
        }




        lTempValue = lForwardDirectionError;

        ROADBool lTempDirection = false;

        ROADReal lTempScale = lForwardDirectionScale;

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

    if(aDeepthIndex == 0 || this->_rangThreshold > leastError)
    {
        IFractalAverItem* lptrIFractalAverItem = aFractalItemContainer->getIFractalAverItem();

        IFractalFirstOrderItem* lptrIFractalFirstOrderItem = aFractalItemContainer->getIFractalFirstOrderItem();

        lptrIFractalFirstOrderItem->setAver(lRangAver);

        lptrIFractalAverItem->setAver(lRangAver);

        ROADUInt32 lLength = aRangSampleLength / (this->_rangTopSampleLength / (1 << this->_amountRangLevels));

        lptrIFractalFirstOrderItem->setLength(lLength);

        lptrIFractalAverItem->setLength(lLength);

        lptrIFractalFirstOrderItem->setIsInversDirection(lDirection);

        lptrIFractalFirstOrderItem->setDomainOffset(lDomain);

        lptrIFractalFirstOrderItem->setScale(lScale);

        lptrIFractalFirstOrderItem->setPosition(this->_currentPosition);

        ROADUInt32 index = aDeepthIndex;

        lptrIFractalAverItem->setIndex(index);

        this->_currentPosition += lLength;
    }
    else
    {
        auto subLength = aRangSampleLength >> 1;

        auto lDeepthIndex = aDeepthIndex - 1;

        domainIntoRangMatch(aData, subLength, lDeepthIndex, aFractalItemContainer);

        domainIntoRangMatch(aData + subLength, subLength, lDeepthIndex, aFractalItemContainer);
    }
}

PlatformDependencies::ROADReal ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::computeSumValue(PtrROADReal aData, ROADUInt32 aLength) {

    ROADReal laver = 0.0;

    for(decltype(aLength) index = 0;
        index < aLength;
        ++index)
        laver += aData[index];

    return laver;
}

PlatformDependencies::ROADReal ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::computeDeviationValue(PtrROADReal aData, ROADUInt32 aLength, ROADReal aAverValue) {

    ROADReal ldev = 0.0;

    ROADReal ltemp = 0.0;

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

void ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::populateDomainPools(PtrROADReal aData) {

    for(auto item: _domainPools)
         item->populate(aData);
}

PlatformDependencies::ROADReal ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::computeAlpha(const PtrROADReal aDataRang,
                                                                                  const PtrROADReal aDataDomain,
                                                                                  ROADUInt32 aLength,
                                                                                  ROADReal aSumRang,
                                                                                  ROADReal aSumDomain)
{
    ROADReal result = 0.0;

    for(ROADUInt32 index = 0;
        index < aLength;
        ++index)
    {
        result += aDataRang[index] * aDataDomain[index];
    }

    result *= aLength;

    result -= aSumRang * aSumDomain;

    return result;
}

ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::~ROADFractalFirstOrderAnalyzerNoneFixedRangLength()
{
    for(auto item: _domainPools)
        delete item;

    _domainPools.clear();
}
