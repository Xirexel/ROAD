#ifndef DECODEDDATACONTAINER_H
#define DECODEDDATACONTAINER_H

#include <memory>

#include "IDoubleDataContainer.h"

#include "platformdependencies.h"

namespace ROADdecoder
{
    namespace ROADover
    {
    using namespace PlatformDependencies;

        template<typename ROADDecodedSampleType>
        class DecodedDataContainer
        {
            private: typedef ROADDecodedSampleType DecodedSampleType;

            private: typedef DecodedSampleType* PtrDecodedSampleType;

            private: std::unique_ptr<DecodedSampleType> _data;

            private: ROADUInt32 _count;

            public: PtrDecodedSampleType getData()
            {
                return this->_data.get();
            }

            public: ROADUInt32 getCount()
            {
                return this->_count;
            }

            public: void setCount(ROADUInt32 aValue);

            public: ~DecodedDataContainer(){}

            public: DecodedDataContainer(ROADUInt32 aLength)
                : _data(new DecodedSampleType[aLength]), _count(aLength)
            {
                memset(_data.get(), 0, aLength * sizeof(DecodedSampleType));
            }
        };
    }
}

#endif // DECODEDDATACONTAINER_H
