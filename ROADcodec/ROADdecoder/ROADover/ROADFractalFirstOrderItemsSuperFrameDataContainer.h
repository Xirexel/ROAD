#ifndef ROADFRACTALFIRSTORDERITEMSSUPERFRAMEDATACONTAINER_H
#define ROADFRACTALFIRSTORDERITEMSSUPERFRAMEDATACONTAINER_H


#include "../ROAD/ROADFrameDataContainer.h"

namespace ROADdecoder
{
    namespace ROADover
    {

        using namespace PlatformDependencies;

        template<typename BaseDecodingSampleType>
        class ROADFractalFirstOrderItemsSuperFrameDataContainer
        {
            public: typedef BaseDecodingSampleType DecodingSampleType;

        private: typedef ROADdecoder::ROAD::ROADFractalFirstOrderItemsFrameDataContainer<DecodingSampleType> FrameContainerType;

        private: std::unique_ptr<FrameContainerType> _FrameMassive;

        public: ROADFractalFirstOrderItemsSuperFrameDataContainer(ROADUInt32 aMaxSuperFrameLength,
                                                                  ROADUInt32 aMaxFrameRangLength,
                                                                  ROADUInt32 aMaxRangSampleLength):
                _FrameMassive(new FrameContainerType[aMaxSuperFrameLength])
            {
                for(decltype(aMaxSuperFrameLength) lindex = 0;
                    lindex < aMaxSuperFrameLength;
                    ++lindex)
                {
                    getFrameDataContainer(lindex)->Init(aMaxFrameRangLength,aMaxRangSampleLength);
                }
            }

        public: FrameContainerType* getFrameDataContainer(ROADUInt32 aIndex)
            {
                return _FrameMassive.get() + aIndex;
            }

        };
    }
}

#endif // ROADFRACTALFIRSTORDERITEMSSUPERFRAMEDATACONTAINER_H
