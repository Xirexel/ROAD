#ifndef ROADFRACTALFIRSTORDERBUILDER_H
#define ROADFRACTALFIRSTORDERBUILDER_H

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
        template<typename SampleType>
        class ROADFractalFirstOrderBuilder: public ROADdecoder::ROAD::IROADFractalFirstOrderBuilder
        {
        private: std::unique_ptr<SampleType> _scalesMassive;

        private: std::unique_ptr<SampleType> _averagesMassive;

        private: std::shared_ptr<ROADdecoder::ROAD::IFractalFirstOrderItemContainer> _container;

        public: ROADFractalFirstOrderBuilder(ROADUInt32 aMaxSuperFrameSampleLength):
                _scalesMassive(new SampleType[aMaxSuperFrameSampleLength]),
                _averagesMassive(new SampleType[aMaxSuperFrameSampleLength])
            {

            }

            public: virtual void build(PtrROADVoid aData)
            {

            }

            public: virtual std::shared_ptr<ROADdecoder::ROAD::IFractalFirstOrderItemContainer> getContainer() = 0;

            public: virtual ~ROADFractalFirstOrderBuilder();
        };
    }
}

#endif // ROADFRACTALFIRSTORDERBUILDER_H
