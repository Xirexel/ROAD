#ifndef ROADFRACTALFIRSTORDERBUILDERTEMPLATE_H
#define ROADFRACTALFIRSTORDERBUILDERTEMPLATE_H

#include <memory>


#include "DomainProcessorFirstOrderNoneFixedLength.h"
#include "IROADFractalFirstOrderBuilder.h"

namespace ROADdecoder
{
    namespace ROAD
    {
        class DomainProcessorFirstOrderNoneFixedLength;
        class IFractalFirstOrderItemContainer;
    }
}

namespace ROADdecoder
{
    namespace ROAD
    {
    using namespace PlatformDependencies;

    class FractalFirstOrderItemInt32
    {

    private: PtrROADInt32 _scalesMassive;

        PtrROADInt32 _averagesMassive;

        ROADUInt32 _rangposition;

        ROADUInt32 _domainposition;

        ROADBool _inversDirection;

        ROADUInt32 _rangLength;

    public: FractalFirstOrderItemInt32(PtrROADInt32 aScalesMassive,
                                       PtrROADInt32 aAveragesMassive):
            _scalesMassive(aScalesMassive),
            _averagesMassive(aAveragesMassive)
        {

        }

        public: virtual ROADUInt32 getLength()
        {
            return this->_rangLength;
        }

        public: virtual ROADBool isInversDirection()
        {
            return this->_inversDirection;
        }

        public: virtual ROADUInt32 getDomainPosition()
        {
            return this->_domainposition;
        }

        public: virtual ROADUInt32 getRangPosition()
        {
            return this->_rangposition;
        }

        public: virtual ~FractalFirstOrderItemInt32(){}

    };

        class IFractalFirstOrderItemContainerInt32
        {

            public: virtual ROADdecoder::ROAD::FractalFirstOrderItemInt32* getIFractalFirstOrderItem(ROADUInt32 aIndex) = 0;

            public: virtual ROADUInt32 getIFractalFirstOrderItemCount() = 0;

            public: virtual ~IFractalFirstOrderItemContainer(){}
        };

        class FractalFirstOrderItemContainerInt32: public IFractalFirstOrderItemContainerInt32
        {
            std::unique_ptr<FractalFirstOrderItemInt32> _rangsMassive;

            ROADUInt32 _count;

        public: FractalFirstOrderItemContainerInt32(ROADUInt32 aMaxCount):
                _rangsMassive(new FractalFirstOrderItemInt32[aMaxCount]),
                _count(0)
            {

            }

        public: virtual ROADdecoder::ROAD::FractalFirstOrderItemInt32* getIFractalFirstOrderItem(ROADUInt32 aIndex)
            {

            }

        public: virtual ROADUInt32 getIFractalFirstOrderItemCount()
            {
                return _count;
            }

        public: virtual ~FractalFirstOrderItemContainerInt32()
            {

            }

        };
    }
}

namespace ROADdecoder
{
    namespace ROAD
    {

        class ROADFractalFirstOrderBuilderInt32
        {
            private: std::unique_ptr<ROADInt32> _ScalesMassive;

            private: std::unique_ptr<ROADInt32> _AveragesMassive;

            FractalFirstOrderItemContainerInt32 _container;

            public: ROADFractalFirstOrderBuilder(ROADUInt32 aSuperFrameSampleLength, ROADUInt32 aMaxRangs):
                    _ScalesMassive(new SampleType[aSuperFrameSampleLength]),
                    _AveragesMassive(new SampleType[aSuperFrameSampleLength]),
                    _container(aMaxRangs)
                {}

            public: void build(PtrROADByte aData, ROADdecoder::ROAD::IFractalFirstOrderItemContainerInt32* aFractalFirstOrderItemContainer)
            {
                ROADUInt32 lmaxCount = 0;

//                ROADUInt32 countFractalItems = 0;

//                PtrROADReal lFramePos = aData;

//                lmaxCount = aFractalFirstOrderItemContainer->getIFractalAverItemCount();

//                while(countFractalItems < lmaxCount)
//                {
//                    IFractalAverItem * item = aFractalFirstOrderItemContainer->getIFractalAverItem(countFractalItems);

//                    ROADUInt32 lrangeLength = item->getLength();

//                    ROADUInt32 lrangPosition = item->getPosition();

//                    ROADReal lAver = item->getAver();

//                    lFramePos = aData + lrangPosition;

//                    for(ROADUInt32 index = 0;
//                            index < lrangeLength;
//                            ++index)
//                    {
//                        *lFramePos = lAver;

//                        lFramePos++;
//                    }

//                    ++countFractalItems;
//                }

                lmaxCount = aFractalFirstOrderItemContainer->getIFractalFirstOrderItemCount();

                if(lmaxCount == 0)
                    return;

                for(ROADUInt32 index = 0;
                    index < 4;
                    ++index)
                {

//                    countFractalItems = 0;

//                    while(countFractalItems < lmaxCount)
//                    {
//                        IFractalFirstOrderItem * item = aFractalFirstOrderItemContainer->getIFractalFirstOrderItem(countFractalItems);

//                        ROADUInt32 lrangLength = item->getLength();

//                        ROADUInt32 lrangPosition = item->getPosition();

//                        ROADReal lAver = item->getAver();

//                        ROADBool lInversDirection = item->isInversDirection();

//                        ROADUInt32 lDomainOffset = item->getDomainOffset();

//                        ROADReal lScale = item->getScale();

//                        auto lptrDomain = _domainProcessor.process(aData, lrangLength, lInversDirection, lDomainOffset);

//                        lFramePos = aData + lrangPosition;

//                        for(ROADUInt32 index = 0;
//                                index < lrangLength;
//                                ++index)
//                        {
//                            ROADReal t = lptrDomain[index] * lScale + lAver;

//                            *lFramePos = t;

//                            lFramePos++;
//                        }

//                        ++countFractalItems;
//                    }
                }
            }


            public: virtual ~ROADFractalFirstOrderBuilder()
            {

            }
        };
    }
}

#endif // ROADFRACTALFIRSTORDERBUILDERTEMPLATE_H
