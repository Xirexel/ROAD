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
        class ROADFractalFirstOrderBuilder: public ROADdecoder::ROAD::IROADFractalFirstOrderBuilder
        {
        private: typedef SampleType* PtrSampleType;

        private:

            class FractalFirstOrderItemTransform
            {

                protected: ROADUInt32 _Position;

                protected: ROADUInt32 _Length;

                protected: ROADBool _IsInversDirection;

                protected: ROADUInt32 _DomainOffset;

                public: FractalFirstOrderItemTransform(){}

                public: ROADUInt32 getLength()
                {
                    return this->_Length;
                }

                public: ROADBool isInversDirection()
                {
                    return this->_IsInversDirection;
                }

                public: ROADUInt32 getDomainOffset()
                {
                    return this->_DomainOffset;
                }

                public: ROADUInt32 getPosition()
                {
                    return this->_Position;
                }

                public: virtual ~FractalFirstOrderItemTransform(){}
            };


            template<typename SampleTypeItem>
            class FractalFirstOrderItem: public FractalFirstOrderItemTransform, public IFractalFirstOrderItem
            {
                private: typedef SampleTypeItem* PtrSampleTypeItem;

                private: SampleTypeItem _sampleTypeItem;

                private: PtrSampleTypeItem _PtrScalesMassive;

                private: PtrSampleTypeItem _PtrAveragesMassive;

                public: FractalFirstOrderItem(){}

                public: void setScalesAndAveragerMassives(PtrSampleTypeItem aPtrScalesMassive,
                                                          PtrSampleTypeItem aPtrAveragesMassive)
                {
                    _PtrScalesMassive = aPtrScalesMassive;

                    _PtrAveragesMassive = aPtrAveragesMassive;
                }

                public: virtual void setAverage(ROADUInt32 aPosition,
                                                 ROADUInt32 aLength,
                                                 PtrROADVoid aPtrDataSample)
                {
                    this->_Position = aPosition;

                    this->_Length = aLength;

                    _sampleTypeItem = *(reinterpret_cast<PtrSampleTypeItem>(aPtrDataSample));

                    PtrSampleTypeItem lpositionPtrSampleType = _PtrAveragesMassive + aPosition;

                    for(decltype(aLength) lindex = 0;
                        lindex < aLength;
                        ++lindex)
                    {
                        *lpositionPtrSampleType = _sampleTypeItem;

                        ++lpositionPtrSampleType;
                    }

                }

                public: virtual void setRangTransform(ROADBool aIsInversDirection,
                                                      ROADUInt32 aDomainOffset,
                                                      ROADInt8 aScale)
                {
                    this->_IsInversDirection = aIsInversDirection;

                    this->_DomainOffset = aDomainOffset;

                    _sampleTypeItem = aScale;

                    PtrSampleTypeItem lpositionPtrSampleType = _PtrScalesMassive + this->_Position;

                    for(decltype(this->_Length) lindex = 0;
                        lindex < this->_Length;
                        ++lindex)
                    {
                        *lpositionPtrSampleType = _sampleTypeItem;

                        ++lpositionPtrSampleType;
                    }
                }

                public: virtual ~FractalFirstOrderItem(){}
            };

            template<typename SampleTypeItem>
            class FractalFirstOrderItemContainer: public IFractalFirstOrderItemContainer
            {
                private: typedef SampleTypeItem* PtrSampleTypeItem;

                private: std::unique_ptr<FractalFirstOrderItem<SampleTypeItem>> _rangsMassive;

                private: ROADUInt32 _count;

                public: FractalFirstOrderItemContainer(ROADUInt32 aMaxFrameRangLength,
                                                       PtrSampleTypeItem aPtrScalesMassive,
                                                       PtrSampleTypeItem aPtrAveragesMassive):
                    _rangsMassive(new FractalFirstOrderItem<SampleTypeItem>[aMaxFrameRangLength]),
                    _count(0)
                {
                    for(decltype(aMaxFrameRangLength) lindex = 0;
                        lindex < aMaxFrameRangLength;
                        ++lindex)
                        _rangsMassive.get()[lindex].setScalesAndAveragerMassives(aPtrScalesMassive,
                                                                                 aPtrAveragesMassive);
                }

                public: virtual void resetIFractalFirstOrderItemCount()
                {
                    this->_count = 0;
                }

                public: virtual ROADdecoder::ROAD::IFractalFirstOrderItem* getIFractalFirstOrderItem(ROADUInt32 aIndex)
                {
                    return &this->_rangsMassive.get()[aIndex];
                }

                public: FractalFirstOrderItemTransform* getFractalFirstOrderItemTransform(ROADUInt32 aIndex)
                {
                    return &this->_rangsMassive.get()[aIndex];
                }

                public: virtual ROADUInt32 getIFractalFirstOrderItemCount()
                {
                    return this->_count;
                }

                public: virtual ~FractalFirstOrderItemContainer(){}
            };

            template<typename SampleTypeItem>
            class DomainProcessorFirstOrder
            {
                private: typedef SampleTypeItem* PtrSampleTypeItem;

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


        private: std::unique_ptr<SampleType> _scalesMassive;

        private: std::unique_ptr<SampleType> _averagesMassive;

        private: PtrSampleType _ptrScalesMassive;

        private: PtrSampleType _ptrAveragesMassive;

        private: std::shared_ptr<FractalFirstOrderItemContainer<SampleType>> _container;

        private: DomainProcessorFirstOrder<SampleType> _domainProcessor;

        public: ROADFractalFirstOrderBuilder(ROADUInt32 aMaxSuperFrameSampleLength,
                                             ROADUInt32 aMaxFrameRangLength,
                                             ROADUInt32 aMaxRangSampleLength):
                _scalesMassive(new SampleType[aMaxSuperFrameSampleLength]),
                _averagesMassive(new SampleType[aMaxSuperFrameSampleLength]),
                _container(new FractalFirstOrderItemContainer<SampleType>(aMaxFrameRangLength,
                                                                          _scalesMassive.get(),
                                                                          _averagesMassive.get())),
                _domainProcessor(DomainProcessorFirstOrder<SampleType>(aMaxRangSampleLength))
            {
                _ptrScalesMassive = _scalesMassive.get();

                _ptrAveragesMassive = _averagesMassive.get();
            }

            public: virtual void build(PtrROADVoid aPtrData)
            {

                PtrSampleType lPtrRangPos;

                PtrSampleType lPtrScalePos;

                PtrSampleType lPtrAveragePos;


                PtrSampleType lPtrFramePos = reinterpret_cast<PtrSampleType>(aPtrData);

                ROADUInt32 countFractalItems = 0;

                ROADUInt32 lmaxCount = _container->getIFractalFirstOrderItemCount();

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
                        auto item = _container->getFractalFirstOrderItemTransform(countFractalItems);

                        ROADUInt32 lrangLength = item->getLength();

                        ROADUInt32 lrangPosition = item->getPosition();

                //                        ROADReal lAver = item->getAver();

                        ROADBool lInversDirection = item->isInversDirection();

                        ROADUInt32 lDomainOffset = item->getDomainOffset();

                //                        ROADReal lScale = item->getScale();

                        auto lptrDomain = _domainProcessor.process(lPtrFramePos, lrangLength, lInversDirection, lDomainOffset);

                        lPtrRangPos = lPtrFramePos + lrangPosition;

                        lPtrScalePos = _ptrScalesMassive + lrangPosition;

                        lPtrAveragePos = this->_ptrAveragesMassive + lrangPosition;

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

            public: virtual std::shared_ptr<ROADdecoder::ROAD::IFractalFirstOrderItemContainer> getContainer()
            {
                return _container;
            }

            public: virtual ~ROADFractalFirstOrderBuilder(){}
        };
    }
}

#endif // ROADFRACTALFIRSTORDERBUILDER_H
