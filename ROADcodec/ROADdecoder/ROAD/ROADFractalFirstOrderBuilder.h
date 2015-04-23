#ifndef ROADFRACTALFIRSTORDERBUILDER_H
#define ROADFRACTALFIRSTORDERBUILDER_H

#include "IROADFractalFirstOrderBuilder.h"
#include "IFractalFirstOrderItem.h"


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

    template<typename SampleType>
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

                lTmepValue = (aData[lOffset] + aData[lOffset + 1]) * 0.5;

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


        template<typename DecodingSampleType>
        class ROADFractalFirstOrderBuilder;

        template<>
        class ROADFractalFirstOrderBuilder<ROADReal>: public ROADdecoder::ROAD::IROADFractalFirstOrderBuilder
        {

        private: typedef ROADFractalFirstOrderItemsFrameDataContainer<ROADReal>::DecodingSampleType SampleType;

        private: typedef SampleType* PtrSampleType;

        private: typedef ROADFractalFirstOrderItemsFrameDataContainer<SampleType>* PtrFrameDataContainerType;

        private: DomainProcessorFirstOrder<SampleType> _domainProcessor;

        public: ROADFractalFirstOrderBuilder(ROADUInt32 aMaxRangSampleLength):
                _domainProcessor(DomainProcessorFirstOrder<SampleType>(aMaxRangSampleLength))
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


                PtrSampleType lPtrFramePos = reinterpret_cast<PtrSampleType>(aPtrData);

                ROADUInt32 countFractalItems = 0;

                ROADUInt32 lmaxCount = lPtrFrameDataContainer->getFractalFirstOrderItemCount();

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

                //                lmaxCount = aFractalFirstOrderItemContainer->getIFractalFirstOrderItemCount();

                if(lmaxCount == 0)
                    return;

                for(ROADUInt32 index = 0;
                    index < 4;
                    ++index)
                {

                    countFractalItems = 0;

                    while(countFractalItems < lmaxCount)
                    {
                        auto item = lPtrFrameDataContainer->getFractalFirstOrderItemTransform(countFractalItems);

                        ROADUInt32 lrangLength = item->getLength();

                        ROADUInt32 lrangPosition = item->getPosition();

                //                        ROADReal lAver = item->getAver();

                        ROADBool lInversDirection = item->isInversDirection();

                        ROADUInt32 lDomainOffset = item->getDomainOffset();

                //                        ROADReal lScale = item->getScale();

                        auto lptrDomain = _domainProcessor.process(lPtrFramePos, lrangLength, lInversDirection, lDomainOffset);

                        lPtrRangPos = lPtrFramePos + lrangPosition;

                        lPtrScalePos = lPtrScalesMassive + lrangPosition;

                        lPtrAveragePos = lPtrAveragesMassive + lrangPosition;

                        for(ROADUInt32 index = 0;
                            index < lrangLength;
                            ++index)
                            {
                                SampleType ltempValue = (*lptrDomain++) * (*lPtrScalePos++) + (*lPtrAveragePos++);

                                *lPtrRangPos = ltempValue;

                                lPtrRangPos++;;
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
