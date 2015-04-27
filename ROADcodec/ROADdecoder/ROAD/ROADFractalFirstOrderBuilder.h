#ifndef ROADFRACTALFIRSTORDERBUILDER_H
#define ROADFRACTALFIRSTORDERBUILDER_H

#include "IROADFractalFirstOrderBuilder.h"
#include "ROADCommon.h"


#include <iostream>

namespace ROADdecoder
{
    namespace ROAD
    {
        class IFractalFirstOrderItemContainer;
    }
}

namespace ROADdecoder
{
    namespace ROAD
    {
        template<>
        class ROADFractalFirstOrderBuilder<ROADReal, false, 2048>: public ROADdecoder::ROAD::IROADFractalFirstOrderBuilder
        {
        private: typedef ROADReal DecodedSampleType;

        private: template<typename DecodedSampleType>
            class DomainProcessorFirstOrder
            {
                private: typedef DecodedSampleType* PtrSampleTypeItem;

                private: PtrSampleTypeItem _data;

                public: ~DomainProcessorFirstOrder()
                {
                    delete []_data;
                }

                public: DomainProcessorFirstOrder(ROADUInt32 aMaxLength):
                    _data(new DecodedSampleType[aMaxLength])
                {

                }

                public: PtrSampleTypeItem process(PtrSampleTypeItem aData, ROADUInt32 aLength, ROADBool aInversDirection, ROADUInt32 aDomainOffset)
                {
                    ROADReal lAver = 0.0;

                    ROADReal lTmepValue = 0;

                    ROADUInt32 lOffset = 0;

                    for(ROADUInt32 index = 0;
                        index < aLength;
                        ++index)
                    {
                        lOffset = aDomainOffset + (index << 1);

                        lTmepValue = aData[lOffset];// (aData[lOffset] + aData[lOffset + 1]) * 0.5;

                        lAver += lTmepValue;

                        this->_data[index] = lTmepValue;
                    }

                    lAver /= aLength;

                    for(ROADUInt32 index = 0;
                        index < aLength;
                        ++index)
                    {
                        this->_data[index] = this->_data[index] - lAver;
                    }

                    if(aInversDirection)
                    {
                        backFlip(aLength);
                    }

                    return this->_data;
                }

                private: void backFlip(ROADUInt32 aLength)
                {

                   ROADReal lTempValue;

                   ROADUInt32 lHalfLength = aLength >> 1;

                   for(ROADUInt32 index = 0;
                       index < lHalfLength;
                       ++index)
                   {
                       lTempValue = this->_data[index];

                       this->_data[index] = this->_data[aLength - 1 - index];

                       this->_data[aLength - 1 - index] = lTempValue;
                   }
               }
            };



        private: typedef DecodedSampleType* PtrSampleType;

        private: typedef ROADFractalFirstOrderItemsFrameDataContainer<DecodedSampleType>* PtrFrameDataContainerType;

        private: DomainProcessorFirstOrder<DecodedSampleType> _domainProcessor;

        public: ROADFractalFirstOrderBuilder(ROADUInt32 aMaxRangSampleLength):
                _domainProcessor(DomainProcessorFirstOrder<DecodedSampleType>(aMaxRangSampleLength))
            {
            }

            public: virtual void build(PtrROADVoid aPtrData, IROADFrameDataContainer* aPtrIROADFrameDataContainer)
            {
                auto lPtrFrameDataContainer = dynamic_cast<PtrFrameDataContainerType>(aPtrIROADFrameDataContainer);

                if(lPtrFrameDataContainer == nullptr)
                    return;

                PtrSampleType lPtrRangPos;

                PtrSampleType lPtrScalePos;

                PtrSampleType lPtrAveragePos;

                PtrSampleType lPtrScalesMassive = lPtrFrameDataContainer->getPtrScalesMassive();

                PtrSampleType lPtrAveragesMassive = lPtrFrameDataContainer->getPtrAveragesMassive();

                ROADInt32 lrangLength;

                ROADUInt32 lrangPosition;

                ROADBool lInversDirection;

                ROADUInt32 lDomainOffset;


                PtrSampleType lPtrFramePos = (PtrSampleType)(aPtrData);

                if(lPtrFramePos == nullptr)
                    return;

                ROADUInt32 countFractalItems = 0;

                ROADUInt32 lFractalIteration = 0;

                ROADUInt32 lmaxCount = lPtrFrameDataContainer->getFractalFirstOrderItemCount();


                if(lmaxCount == 0)
                    return;

                for(;
                    lFractalIteration < 4;
                    ++lFractalIteration)
                {

                    countFractalItems = 0;

                    while(countFractalItems < lmaxCount)
                    {
                        auto item = lPtrFrameDataContainer->getFractalFirstOrderItemTransform(countFractalItems);

                        lrangLength = item->getLength();

                        lrangPosition = item->getPosition();

                        lInversDirection = item->isInversDirection();

                        lDomainOffset = item->getDomainOffset();


                        auto lptrDomain = _domainProcessor.process(lPtrFramePos, lrangLength, lInversDirection, lDomainOffset);


                        lPtrRangPos = lPtrFramePos + lrangPosition;

                        lPtrScalePos = lPtrScalesMassive + lrangPosition;

                        lPtrAveragePos = lPtrAveragesMassive + lrangPosition;

                        while(--lrangLength >= 0)
                        {
                                *lPtrRangPos++ = (*lptrDomain++) * (*lPtrScalePos++) + (*lPtrAveragePos++);
                        }

                        ++countFractalItems;
                    }
                }
            }

            public: virtual ~ROADFractalFirstOrderBuilder(){}
        };

        template<>
        class ROADFractalFirstOrderBuilder<ROADInt32, false, 2048>: public ROADdecoder::ROAD::IROADFractalFirstOrderBuilder
        {
        private: typedef ROADInt32 DecodedSampleType;

        private: template<typename SampleType>
            class DomainProcessorFirstOrder
            {
                private: typedef SampleType* PtrSampleTypeItem;

                private: PtrSampleTypeItem _data;

                public: ~DomainProcessorFirstOrder()
                {
                    delete []_data;
                }

                public: DomainProcessorFirstOrder(ROADUInt32 aMaxLength):
                    _data(new SampleType[aMaxLength])
                {

                }

                public: PtrSampleTypeItem process(PtrSampleTypeItem aData, ROADUInt32 aLength, ROADBool aInversDirection, ROADUInt32 aDomainOffset)
                {
                    ROADReal lAver = 0.0;

                    ROADReal lTmepValue = 0;

                    ROADUInt32 lOffset = 0;

                    for(ROADUInt32 index = 0;
                        index < aLength;
                        ++index)
                    {
                        lOffset = aDomainOffset + (index << 1);

                        lTmepValue = aData[lOffset];// (aData[lOffset] + aData[lOffset + 1]) * 0.5;

                        lAver += lTmepValue;

                        this->_data[index] = lTmepValue;
                    }

                    lAver /= aLength;

                    for(ROADUInt32 index = 0;
                        index < aLength;
                        ++index)
                    {
                        this->_data[index] = this->_data[index] - lAver;
                    }

                    if(aInversDirection)
                    {
                        backFlip(aLength);
                    }

                    return this->_data;
                }

                private: void backFlip(ROADUInt32 aLength)
                {

                   ROADReal lTempValue;

                   ROADUInt32 lHalfLength = aLength >> 1;

                   for(ROADUInt32 index = 0;
                       index < lHalfLength;
                       ++index)
                   {
                       lTempValue = this->_data[index];

                       this->_data[index] = this->_data[aLength - 1 - index];

                       this->_data[aLength - 1 - index] = lTempValue;
                   }
               }
            };



        private: typedef DecodedSampleType* PtrSampleType;

        private: typedef ROADFractalFirstOrderItemsFrameDataContainer<DecodedSampleType>* PtrFrameDataContainerType;

        private: DomainProcessorFirstOrder<DecodedSampleType> _domainProcessor;

        public: ROADFractalFirstOrderBuilder(ROADUInt32 aMaxRangSampleLength):
                _domainProcessor(DomainProcessorFirstOrder<DecodedSampleType>(aMaxRangSampleLength))
            {
            }

            public: virtual void build(PtrROADVoid aPtrData, IROADFrameDataContainer* aPtrIROADFrameDataContainer)
            {
                auto lPtrFrameDataContainer = dynamic_cast<PtrFrameDataContainerType>(aPtrIROADFrameDataContainer);

                if(lPtrFrameDataContainer == nullptr)
                    return;

                PtrSampleType lPtrRangPos;

                PtrSampleType lPtrScalePos;

                PtrSampleType lPtrAveragePos;

                PtrSampleType lPtrScalesMassive = lPtrFrameDataContainer->getPtrScalesMassive();

                PtrSampleType lPtrAveragesMassive = lPtrFrameDataContainer->getPtrAveragesMassive();

                ROADInt32 lrangLength;

                ROADUInt32 lrangPosition;

                ROADBool lInversDirection;

                ROADUInt32 lDomainOffset;


                PtrSampleType lPtrFramePos = (PtrSampleType)(aPtrData);

                if(lPtrFramePos == nullptr)
                    return;

                ROADUInt32 countFractalItems = 0;

                ROADUInt32 lFractalIteration = 0;

                ROADUInt32 lmaxCount = lPtrFrameDataContainer->getFractalFirstOrderItemCount();


                if(lmaxCount == 0)
                    return;

                for(;
                    lFractalIteration < 4;
                    ++lFractalIteration)
                {

                    countFractalItems = 0;

                    while(countFractalItems < lmaxCount)
                    {
                        auto item = lPtrFrameDataContainer->getFractalFirstOrderItemTransform(countFractalItems);

                        lrangLength = item->getLength();

                        lrangPosition = item->getPosition();

                        lInversDirection = item->isInversDirection();

                        lDomainOffset = item->getDomainOffset();


                        auto lptrDomain = _domainProcessor.process(lPtrFramePos, lrangLength, lInversDirection, lDomainOffset);


                        lPtrRangPos = lPtrFramePos + lrangPosition;

                        lPtrScalePos = lPtrScalesMassive + lrangPosition;

                        lPtrAveragePos = lPtrAveragesMassive + lrangPosition;

                        while(--lrangLength >= 0)
                        {
                                *lPtrRangPos++ = (((*lptrDomain++) * (*lPtrScalePos++)) >> 7) + (*lPtrAveragePos++);
                        }

                        ++countFractalItems;
                    }
                }
            }

            public: virtual ~ROADFractalFirstOrderBuilder(){}
        };
    }
}

#endif // ROADFRACTALFIRSTORDERBUILDER_H
