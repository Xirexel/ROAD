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

            long AddRef()
            {
                return ++refCount;
            }

            long Release()
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
                return _data.get();
            }

            PlatformDependencies::PtrROADByte get()
            {
                return _data.get();
            }

        private:

            std::atomic<long> refCount;

            std::unique_ptr<PlatformDependencies::ROADByte> _data;
    };

    }
}

#endif // DATACONTAINER_H
