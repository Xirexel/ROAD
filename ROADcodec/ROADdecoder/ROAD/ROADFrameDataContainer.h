#ifndef ROADFRAMEDATACONTAINER_H
#define ROADFRAMEDATACONTAINER_H


#include <memory>

#include <iostream>


#include "platformdependencies.h"
#include "ROADDataFormat.h"


namespace ROADdecoder
{
    namespace ROAD
    {

    using namespace PlatformDependencies;


        class IROADFrameDataContainer
        {
            public: virtual ROADUInt8 getBaseDecodingSampleTypeFormat() = 0;
        };

        class FractalFirstOrderItemTransform//: public IFractalFirstOrderItem
        {

            protected: ROADUInt32 _Position;

            protected: ROADUInt32 _Length;

            protected: ROADBool _IsInversDirection;

            protected: ROADUInt32 _DomainOffset;

            protected: ROADUInt8 _FractalItemIndex;

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

            public: ROADUInt8 getFractalItemIndex()
            {
                return this->_FractalItemIndex;
            }

            public: ~FractalFirstOrderItemTransform(){}
        };

        template<typename SampleTypeItem>
        class FractalFirstOrderItem: public FractalFirstOrderItemTransform
        {
            private: typedef SampleTypeItem* PtrSampleTypeItem;

            private: SampleTypeItem _sampleTypeItem;

            private: SampleTypeItem _scale;

            private: PtrSampleTypeItem _PtrScalesMassive;

            private: PtrSampleTypeItem _PtrAveragesMassive;

            public: FractalFirstOrderItem(){}

            public: void setScalesAndAveragerMassives(PtrSampleTypeItem aPtrScalesMassive,
                                                      PtrSampleTypeItem aPtrAveragesMassive)
            {
                _PtrScalesMassive = aPtrScalesMassive;

                _PtrAveragesMassive = aPtrAveragesMassive;
            }

            public: void setIndexInfo(ROADUInt32 aPosition,
                                      ROADUInt32 aLength,
                                      ROADUInt8 aFractalItemIndex)
            {

                this->_Position = aPosition;

                this->_Length = aLength;

                this->_FractalItemIndex = aFractalItemIndex;
            }


            public: void setAverage(PtrROADVoid aPtrDataSample)
            {
                _sampleTypeItem = *((PtrSampleTypeItem)aPtrDataSample);

                PtrSampleTypeItem lpositionPtrSampleType = _PtrAveragesMassive + this->_Position;

                for(decltype(this->_Length) lindex = 0;
                    lindex < this->_Length;
                    ++lindex)
                {
                    *lpositionPtrSampleType++ = _sampleTypeItem;
                }

            }

            public: void setRangTransform(ROADBool aIsInversDirection,
                                                  ROADUInt32 aDomainOffset,
                                                  SampleTypeItem aScale)
            {
                this->_IsInversDirection = aIsInversDirection;

                this->_DomainOffset = aDomainOffset;

                _scale = aScale;

                PtrSampleTypeItem lpositionPtrSampleType = _PtrScalesMassive + this->_Position;

                for(decltype(this->_Length) lindex = 0;
                    lindex < this->_Length;
                    ++lindex)
                {
                    *lpositionPtrSampleType = _scale;

                    ++lpositionPtrSampleType;
                }
            }

            public: SampleTypeItem getScale()
            {
                return this->_scale;
            }

            public: void setScale(SampleTypeItem aScale)
            {

                PtrSampleTypeItem lpositionPtrSampleType = _PtrScalesMassive + this->_Position;

                for(decltype(this->_Length) lindex = 0;
                    lindex < this->_Length;
                    ++lindex)
                {
                    *lpositionPtrSampleType = aScale;

                    ++lpositionPtrSampleType;
                }
            }

            public: ~FractalFirstOrderItem(){}
        };

        template<>
        class FractalFirstOrderItem<ROADReal>: public FractalFirstOrderItemTransform
        {

            private: typedef ROADReal SampleTypeItem;

            private: typedef SampleTypeItem* PtrSampleTypeItem;

            private: SampleTypeItem _sampleTypeItem;

            private: SampleTypeItem _scale;

            private: SampleTypeItem _tempScale;

            private: PtrSampleTypeItem _PtrScalesMassive;

            private: PtrSampleTypeItem _PtrAveragesMassive;

            public: FractalFirstOrderItem(){}

            public: void setScalesAndAveragerMassives(PtrSampleTypeItem aPtrScalesMassive,
                                                      PtrSampleTypeItem aPtrAveragesMassive)
            {
                _PtrScalesMassive = aPtrScalesMassive;

                _PtrAveragesMassive = aPtrAveragesMassive;
            }

            public: void setIndexInfo(ROADUInt32 aPosition,
                                      ROADUInt32 aLength,
                                      ROADUInt8 aFractalItemIndex)
            {


                this->_Position = aPosition;

                this->_Length = aLength;

                this->_FractalItemIndex = aFractalItemIndex;
            }


            public: void setAverage(PtrROADVoid aPtrDataSample)
            {
                _sampleTypeItem = *((PtrSampleTypeItem)aPtrDataSample);

                PtrSampleTypeItem lpositionPtrSampleType = _PtrAveragesMassive + this->_Position;

                for(decltype(this->_Length) lindex = 0;
                    lindex < this->_Length;
                    ++lindex)
                {
                    *lpositionPtrSampleType++ = _sampleTypeItem;
                }

            }

            public: void setRangTransform(ROADBool aIsInversDirection,
                                                  ROADUInt32 aDomainOffset,
                                                  SampleTypeItem aScale)
            {
                this->_IsInversDirection = aIsInversDirection;

                this->_DomainOffset = aDomainOffset;

                _scale = aScale;

                PtrSampleTypeItem lpositionPtrSampleType = _PtrScalesMassive + this->_Position;

                for(decltype(this->_Length) lindex = 0;
                    lindex < this->_Length;
                    ++lindex)
                {
                    *lpositionPtrSampleType = _scale;

                    ++lpositionPtrSampleType;
                }
            }

            public: SampleTypeItem getScale()
            {
                return this->_scale;
            }

            public: void setScale(SampleTypeItem aScale)
            {
                _tempScale = aScale / 128.0;

                PtrSampleTypeItem lpositionPtrSampleType = _PtrScalesMassive + this->_Position;

                for(decltype(this->_Length) lindex = 0;
                    lindex < this->_Length;
                    ++lindex)
                {
                    *lpositionPtrSampleType = _tempScale;

                    ++lpositionPtrSampleType;
                }
            }

            public: ~FractalFirstOrderItem(){}
        };

        template<typename BaseDecodingSampleType>
        class ROADFractalFirstOrderItemsFrameDataContainer:
                public IROADFrameDataContainer
        {
            public: typedef BaseDecodingSampleType DecodingSampleType;

            private: typedef DecodingSampleType* PtrDecodingSampleType;

            private: std::unique_ptr<DecodingSampleType> _scalesMassive;

            private: std::unique_ptr<DecodingSampleType> _averagesMassive;

            private: std::unique_ptr<FractalFirstOrderItem<DecodingSampleType>> _rangsMassive;

            private: ROADUInt32 _count;

            public: ROADFractalFirstOrderItemsFrameDataContainer(){}

            public: ROADFractalFirstOrderItemsFrameDataContainer(ROADUInt32 aMaxFrameRangLength,
                                                                 ROADUInt32 aMaxRangSampleLength):
                _scalesMassive(new DecodingSampleType[aMaxFrameRangLength * aMaxRangSampleLength]),
                _averagesMassive(new DecodingSampleType[aMaxFrameRangLength * aMaxRangSampleLength]),
                _rangsMassive(new FractalFirstOrderItem<DecodingSampleType>[aMaxFrameRangLength]),
                _count(0)
            {
                for(decltype(aMaxFrameRangLength) lindex = 0;
                    lindex < aMaxFrameRangLength;
                    ++lindex)
                    _rangsMassive.get()[lindex].setScalesAndAveragerMassives(_scalesMassive.get(),
                                                                             _averagesMassive.get());
            }

        public: void Init(ROADUInt32 aMaxFrameRangLength,
                          ROADUInt32 aMaxRangSampleLength)
            {
                _scalesMassive.reset(new DecodingSampleType[aMaxFrameRangLength * aMaxRangSampleLength]);

                _averagesMassive.reset(new DecodingSampleType[aMaxFrameRangLength * aMaxRangSampleLength]);

                _rangsMassive.reset(new FractalFirstOrderItem<DecodingSampleType>[aMaxFrameRangLength]);


                for(decltype(aMaxFrameRangLength) lindex = 0;
                    lindex < aMaxFrameRangLength;
                    ++lindex)
                    _rangsMassive.get()[lindex].setScalesAndAveragerMassives(_scalesMassive.get(),
                                                                             _averagesMassive.get());

                _count = 0;
            }

            public: virtual ROADUInt8 getBaseDecodingSampleTypeFormat()
            {
                return ROADDataFormat(DecodingSampleType());
            }

            public: void resetFractalFirstOrderItemCount()
            {
                this->_count = 0;
            }

            public: void incrementFractalFirstOrderItemCount()
            {
                ++this->_count;
            }

            public: void setFractalFirstOrderItemCount(ROADUInt32 aCount)
            {
                this->_count = aCount;
            }

            public: FractalFirstOrderItem<DecodingSampleType>* getFractalFirstOrderItemTransform(ROADUInt32 aIndex)
            {
                return &this->_rangsMassive.get()[aIndex];
            }

            public: ROADUInt32 getFractalFirstOrderItemCount()
            {
                return this->_count;
            }

            public: PtrDecodingSampleType getPtrScalesMassive()
            {
                return this->_scalesMassive.get();
            }

            public: PtrDecodingSampleType getPtrAveragesMassive()
            {
                return this->_averagesMassive.get();
            }

            public: ~ROADFractalFirstOrderItemsFrameDataContainer(){}
        };

        template<>
        class ROADFractalFirstOrderItemsFrameDataContainer<ROADInt32>:
                public IROADFrameDataContainer
        {
            public: typedef ROADInt32 DecodingSampleType;

            private: typedef DecodingSampleType* PtrDecodingSampleType;

            private: std::unique_ptr<DecodingSampleType> _scalesMassive;

            private: std::unique_ptr<DecodingSampleType> _averagesMassive;

            private: std::unique_ptr<FractalFirstOrderItem<DecodingSampleType>> _rangsMassive;

            private: ROADUInt32 _count;

            public: ROADFractalFirstOrderItemsFrameDataContainer(){}

            public: ROADFractalFirstOrderItemsFrameDataContainer(ROADUInt32 aMaxFrameRangLength,
                                                                 ROADUInt32 aMaxRangSampleLength):
                _scalesMassive(new DecodingSampleType[aMaxFrameRangLength * aMaxRangSampleLength]),
                _averagesMassive(new DecodingSampleType[aMaxFrameRangLength * aMaxRangSampleLength]),
                _rangsMassive(new FractalFirstOrderItem<DecodingSampleType>[aMaxFrameRangLength]),
                _count(0)
            {
                for(decltype(aMaxFrameRangLength) lindex = 0;
                    lindex < aMaxFrameRangLength;
                    ++lindex)
                    _rangsMassive.get()[lindex].setScalesAndAveragerMassives(_scalesMassive.get(),
                                                                             _averagesMassive.get());
            }

        public: void Init(ROADUInt32 aMaxFrameRangLength,
                          ROADUInt32 aMaxRangSampleLength)
            {
                _scalesMassive.reset(new DecodingSampleType[aMaxFrameRangLength * aMaxRangSampleLength]);

                _averagesMassive.reset(new DecodingSampleType[aMaxFrameRangLength * aMaxRangSampleLength]);

                _rangsMassive.reset(new FractalFirstOrderItem<DecodingSampleType>[aMaxFrameRangLength]);


                for(decltype(aMaxFrameRangLength) lindex = 0;
                    lindex < aMaxFrameRangLength;
                    ++lindex)
                    _rangsMassive.get()[lindex].setScalesAndAveragerMassives(_scalesMassive.get(),
                                                                             _averagesMassive.get());

                _count = 0;
            }

            public: virtual ROADUInt8 getBaseDecodingSampleTypeFormat()
            {
                return ROADDataFormat(DecodingSampleType());
            }

            public: void resetFractalFirstOrderItemCount()
            {
                this->_count = 0;
            }

            public: void incrementFractalFirstOrderItemCount()
            {
                ++this->_count;
            }

            public: void setFractalFirstOrderItemCount(ROADUInt32 aCount)
            {
                this->_count = aCount;
            }

            public: FractalFirstOrderItem<DecodingSampleType>* getFractalFirstOrderItemTransform(ROADUInt32 aIndex)
            {
                return &this->_rangsMassive.get()[aIndex];
            }

            public: ROADUInt32 getFractalFirstOrderItemCount()
            {
                return this->_count;
            }

            public: PtrDecodingSampleType getPtrScalesMassive()
            {
                return this->_scalesMassive.get();
            }

            public: PtrDecodingSampleType getPtrAveragesMassive()
            {
                return this->_averagesMassive.get();
            }

            public: ~ROADFractalFirstOrderItemsFrameDataContainer(){}
        };
    }
}

#endif // ROADFRAMEDATACONTAINER_H
