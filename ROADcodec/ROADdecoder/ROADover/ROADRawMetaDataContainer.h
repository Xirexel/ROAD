#ifndef ROADRAWMETADATACONTAINER_H
#define ROADRAWMETADATACONTAINER_H


#include <memory>


#include "platformdependencies.h"

#include "roadover_global.h"

namespace ROADdecoder
{
    namespace ROADover
    {
        class ROADOVERSHARED_EXPORT ROADRawMetaDataContainer
        {
            private: std::unique_ptr<PlatformDependencies::ROADByte> _data;

            private: PlatformDependencies::ROADByte _head;

            private: PlatformDependencies::ROADUInt64 _dataLength;

            public: ROADRawMetaDataContainer(std::unique_ptr<PlatformDependencies::ROADByte> &aData,
                                             PlatformDependencies::ROADUInt64 aDataLength,
                                             PlatformDependencies::ROADByte aHead)
                    :_data(aData.release()),
                     _dataLength(aDataLength),
                     _head(aHead){}

            public: PlatformDependencies::PtrROADByte getData()
                {
                    return this->_data.get();
                }

            public: PlatformDependencies::ROADUInt64 getDataLength()
                {
                    return this->_dataLength;
                }

            public: PlatformDependencies::ROADByte getHead()
                {
                    return this->_head;
                }

        };
    }
}


#endif // ROADRAWMETADATACONTAINER_H
