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
            private: std::shared_ptr<PlatformDependencies::ROADByte> _data;

            private: PlatformDependencies::ROADUInt64 _dataLength;

            private: PlatformDependencies::ROADByte _head;

            public: ROADRawMetaDataContainer(std::shared_ptr<PlatformDependencies::ROADByte> &aData,
                                             PlatformDependencies::ROADUInt64 aDataLength,
                                             PlatformDependencies::ROADByte aHead)
                    :_data(aData),
                     _dataLength(aDataLength),
                     _head(aHead){}

            public: std::shared_ptr<PlatformDependencies::ROADByte> getData()
                {
                    return _data;
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
