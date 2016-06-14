#ifndef DATACONTAINER_H
#define DATACONTAINER_H



#include <memory>
#include <atomic>


#include "platformdependencies.h"

namespace ROADdecoder
{
    namespace Driver
    {
        class DataContainer
        {
        public:

            DataContainer(std::unique_ptr<PlatformDependencies::ROADByte> &aData):
                refCount(1),
                _data(aData.release())
            {

            }

            DataContainer(PlatformDependencies::ROADInt64 aDataLength):
                refCount(1),
                _data(new PlatformDependencies::ROADByte[aDataLength])
            {

            }

            ~DataContainer() noexcept
            {
                if(_data != nullptr)
                    delete []_data;
            }


            long AddRef()
            {
                return ++refCount;
            }

            long Release() noexcept
            {
                auto lrefCount = --refCount;

                if(lrefCount == 0)
                {
                    delete this;
                }

                return lrefCount;
            }

            operator PlatformDependencies::PtrROADByte()
            {
                return _data;
            }

            PlatformDependencies::PtrROADByte get()
            {
                return _data;
            }

        private:

            std::atomic<long> refCount;

            PlatformDependencies::PtrROADByte _data;
    };

    }
}

#endif // DATACONTAINER_H
