#ifndef ROADFRAMEDATACONTAINER_H
#define ROADFRAMEDATACONTAINER_H


#include <memory>


#include "platformdependencies.h"
#include "ROADRawDataFormat.h"
#include "IFractalFirstOrderItem.h"
#include "IFractalFirstOrderItemContainer.h"


namespace ROADdecoder
{
    namespace ROAD
    {

    using namespace PlatformDependencies;


        class IROADFrameDataContainer
        {
            public: virtual ROADUInt8 getBaseDecodingSampleTypeFormat() = 0;
        };

        class FractalFirstOrderItemTransform: public IFractalFirstOrderItem
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
        class FractalFirstOrderItem: public FractalFirstOrderItemTransform
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

        template<typename BaseDecodingSampleType>
        class ROADFractalFirstOrderItemsFrameDataContainer;

        template<>
        class ROADFractalFirstOrderItemsFrameDataContainer<ROADReal>:
                public IROADFrameDataContainer,
                public IFractalFirstOrderItemContainer
        {
            public: typedef ROADReal DecodingSampleType;

            private: typedef DecodingSampleType* PtrDecodingSampleType;

            private: std::unique_ptr<DecodingSampleType> _scalesMassive;

            private: std::unique_ptr<DecodingSampleType> _averagesMassive;

            private: std::unique_ptr<FractalFirstOrderItem<DecodingSampleType>> _rangsMassive;

            private: ROADUInt32 _count;

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

            public: virtual ROADUInt8 getBaseDecodingSampleTypeFormat()
            {
                return ROADRawDataFormat(DecodingSampleType());
            }

            public: virtual void resetIFractalFirstOrderItemCount()
            {
                this->_count = 0;
            }

            public: virtual ROADdecoder::ROAD::IFractalFirstOrderItem* getIFractalFirstOrderItem(ROADUInt32 aIndex)
            {
                return &this->_rangsMassive.get()[aIndex];
            }

            public: FractalFirstOrderItem<DecodingSampleType>* getFractalFirstOrderItemTransform(ROADUInt32 aIndex)
            {
                return &this->_rangsMassive.get()[aIndex];
            }

            public: virtual ROADUInt32 getIFractalFirstOrderItemCount()
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
