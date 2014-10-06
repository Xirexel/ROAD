#include <string>
#include <vector>
#include <exception>
#include <math.h>
#include <limits>
using namespace std;

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

        unsigned int lDomainPoolSize = this->_frameSampleLength - lTopDomainLength + 1;

        _domainPools.push_back( new ROADcoder::ROADCoder::DomainPool(lDomainPoolSize, lTopDomainLength, this->_domainShift));
    }

}

void ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::analyze(double* aData, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalItemContainer) {

    this->_currentPosition = 0;

    populateDomainPools(aData);

    silenceMatch(aData, this->_frameSampleLength, aFractalItemContainer);
}

void ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::silenceMatch(double* aData, unsigned int aSilenceSampleLength, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalItemContainer) {


    double laver = computeSumValue(aData, aSilenceSampleLength);

    laver /= aSilenceSampleLength;

    double ldev = computeDeviationValue(aData, aSilenceSampleLength, laver);

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

        unsigned int lLength = aSilenceSampleLength / (this->_rangTopSampleLength / (1 << this->_amountRangLevels));

        lptrIFractalAverItem->setLength(lLength);

        this->_currentPosition += lLength;

        unsigned int index = log2(static_cast<double>(lLength));

        index |= 128;

        lptrIFractalAverItem->setIndex(index);
    }




}

void ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::domainIntoRangMatch(double* aData, unsigned int aRangSampleLength, unsigned int aDeepthIndex, ROADcoder::ROADCoder::IFractalFirstOrderItemContainer* aFractalItemContainer) {

    double lRangSum = computeSumValue(aData, aRangSampleLength);

    double lRangAver = lRangSum / aRangSampleLength;

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
        Domain *lptrIDomain = lptrDomainPool->getDomain(lDomainIndex);

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



        double lAlpha = computeAlpha(aData, lptrDomainData, aRangSampleLength, lRangSum, lDomainSum);

        lForwardDirectionScale = lAlpha/lBeta;

        if(lForwardDirectionScale > 0.996)
            lForwardDirectionScale = 0.996;
        else if(lForwardDirectionScale < -0.996)
            lForwardDirectionScale = -0.996;

        int ldecinScale = lForwardDirectionScale * 255.0;

        lForwardDirectionScale = static_cast<double>(ldecinScale) / 255.0;

        lForwardDirectionValueOffset = lRangAver - lForwardDirectionScale * lDomainAver;


        for(unsigned int index = 0;
            index < aRangSampleLength;
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


        lAlpha = computeAlpha(aData, lptrDomainData, aRangSampleLength, lRangSum, lDomainSum);

        lBackDirectionScale = lAlpha/lBeta;

        if(lBackDirectionScale > 0.996)
            lBackDirectionScale = 0.996;
        else if(lBackDirectionScale < -0.996)
            lBackDirectionScale = -0.996;

        ldecinScale = lBackDirectionScale * 255.0;

        lBackDirectionScale = static_cast<double>(ldecinScale) / 255.0;

        lBackDirectionValueOffset = lRangAver - lBackDirectionScale * lDomainAver;




        for(unsigned int index = 0;
            index < aRangSampleLength;
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

    if(aDeepthIndex == 0 || this->_rangThreshold > leastError)
    {
        IFractalAverItem* lptrIFractalAverItem = aFractalItemContainer->getIFractalAverItem();

        IFractalFirstOrderItem* lptrIFractalFirstOrderItem = aFractalItemContainer->getIFractalFirstOrderItem();

        lptrIFractalFirstOrderItem->setAver(lRangAver);

        lptrIFractalAverItem->setAver(lRangAver);

        unsigned int lLength = aRangSampleLength / (this->_rangTopSampleLength / (1 << this->_amountRangLevels));

        lptrIFractalFirstOrderItem->setLength(lLength);

        lptrIFractalAverItem->setLength(lLength);

        lptrIFractalFirstOrderItem->setIsInversDirection(lDirection);

        lptrIFractalFirstOrderItem->setDomainOffset(lDomain);

        lptrIFractalFirstOrderItem->setScale(lScale);

        lptrIFractalFirstOrderItem->setPosition(this->_currentPosition);

        unsigned int index = aDeepthIndex;

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

double ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::computeSumValue(double* aData, unsigned int aLength) {

    double laver = 0.0;

    for(decltype(aLength) index = 0;
        index < aLength;
        ++index)
        laver += aData[index];

    return laver;
}

double ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::computeDeviationValue(double* aData, unsigned int aLength, double aAverValue) {

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

void ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::populateDomainPools(double* aData) {

    for(auto item: _domainPools)
         item->populate(aData);
}

double ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::computeAlpha(const double* aDataRang,
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

ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerNoneFixedRangLength::~ROADFractalFirstOrderAnalyzerNoneFixedRangLength()
{
    for(auto item: _domainPools)
        delete item;

    _domainPools.clear();
}
