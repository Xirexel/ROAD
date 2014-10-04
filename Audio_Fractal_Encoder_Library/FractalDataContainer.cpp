#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "FractalDataContainer.h"
#include "DoubleDataContainer.h"
#include "UCharDataContainer.h"
#include "IDoubleDataContainer.h"
#include "IUCharDataContainer.h"
#include "IFractalDataContainer.h"
#include "FrameFractalItemCollection.h"
//#include "LogPrintOut.h"

FractalEncoding::IDoubleDataContainer* FractalEncoding::FractalDataContainer::getAver() {
    return this->_averContainer;
}

FractalEncoding::IDoubleDataContainer* FractalEncoding::FractalDataContainer::getExtendAver() {
    return this->_extenAverContainer;
}

FractalEncoding::IUCharDataContainer* FractalEncoding::FractalDataContainer::getIndex() {
    return this->_indexContainer;
}

FractalEncoding::IUCharDataContainer* FractalEncoding::FractalDataContainer::getDomain() {
    return this->_domainContainer;
}

FractalEncoding::IUCharDataContainer* FractalEncoding::FractalDataContainer::getScale() {
    return this->_scaleContainer;
}

FractalEncoding::FractalDataContainer::FractalDataContainer(unsigned int aSize)
    : _averContainer(new DoubleDataContainer(aSize)),
      _extenAverContainer(new DoubleDataContainer(aSize)),
     _indexContainer(new UCharDataContainer(aSize)),
     _domainContainer(new UCharDataContainer(aSize)),
     _scaleContainer(new UCharDataContainer(aSize))
{
}

FractalEncoding::FractalDataContainer::~FractalDataContainer()
{
    delete _averContainer;
    delete _extenAverContainer;
    delete _indexContainer;
    delete _domainContainer;
    delete _scaleContainer;
}

void FractalEncoding::FractalDataContainer::populate(FractalEncoding::FrameFractalItemCollection* aCollection)
{
    decltype(aCollection->getCount()) count = aCollection->getCount();



    double * lptrAver = _averContainer->getData();

    lptrAver += _averContainer->getCount();



    double * lptrExtendAver = _extenAverContainer->getData();

    lptrExtendAver += _extenAverContainer->getCount();



    unsigned char *lptrIndeces = _indexContainer->getData();

    lptrIndeces += _indexContainer->getCount();



    unsigned char *lptrDomains = _domainContainer->getData();

    lptrDomains += _domainContainer->getCount();



    unsigned char *lptrScales = _scaleContainer->getData();

    lptrScales += _scaleContainer->getCount();


    for(decltype(count) index = 0;
        index < count;
        ++index)
    {

        FractalItem *lptrFractalItem = aCollection->getFractalItem(index);




        double laver = lptrFractalItem->getAver();


        *lptrAver = laver;

        lptrAver++;

        auto tempCount = _averContainer->getCount();

        _averContainer->setCount(++tempCount);



        auto indexRang = lptrFractalItem->getIndex();

        unsigned char lIndex = 0;

        if(lptrFractalItem->isSilence())
        {
            auto length = 1 << indexRang;

            tempCount = _extenAverContainer->getCount() + length;

            _extenAverContainer->setCount(tempCount);

            while(length > 0)
            {
                *lptrExtendAver = laver;

                lptrExtendAver++;

                --length;
            }

            lIndex = indexRang;

            lIndex |= 128;
        }
        else
        {
            auto length = 1 << indexRang;

            tempCount = _extenAverContainer->getCount() + length;

            _extenAverContainer->setCount(tempCount);

            while(length > 0)
            {
                *lptrExtendAver = laver;

                lptrExtendAver++;

                --length;
            }

            lIndex = indexRang << 5;

            if(lptrFractalItem->isDirection())
                lIndex |= 16;


            float lScale = lptrFractalItem->getScale();

            if(lScale < 0.0f)
            {
                lScale = -lScale;

                lIndex |= 8;
            }

            unsigned char lUCScale =  (lScale * 255.0f);


            *lptrScales = lUCScale;

            ++lptrScales;

            tempCount = _scaleContainer->getCount();

            _scaleContainer->setCount(++tempCount);




            unsigned int lDomain = lptrFractalItem->getDomain();

            unsigned char lHDomain = lDomain >> 8;

            unsigned char lLDomain = lDomain & 255;


            lIndex |= lHDomain;



            *lptrDomains = lLDomain;

            ++lptrDomains;

            tempCount = _domainContainer->getCount();

            _domainContainer->setCount(++tempCount);

        }




        *lptrIndeces = lIndex;

        ++lptrIndeces;

        tempCount = _indexContainer->getCount();

        _indexContainer->setCount(++tempCount);

    }

}

void FractalEncoding::FractalDataContainer::reset()
{
    _averContainer->setCount(0);
    _extenAverContainer->setCount(0);
    _indexContainer->setCount(0);
    _domainContainer->setCount(0);
    _scaleContainer->setCount(0);
}
