#ifndef ROADRAWMETADATACONTAINER_H
#define ROADRAWMETADATACONTAINER_H


#include "platformdependencies.h"
#include "DataContainer.h"
#include "SmartPtr.h"

#include "roadover_global.h"

namespace ROADdecoder
{
    namespace ROADover
    {

//        class ROADRawMetaData
//        {
//        public:

//            ROADRawMetaData(std::unique_ptr<PlatformDependencies::ROADByte> &aData):
//                refCount(1),
//                _data(aData.release())
//            {

//            }

//            long AddRef()
//            {
//                return ++refCount;
//            }

//            long Release()
//            {
//                auto lrefCount = --refCount;

//                if(lrefCount == 0)
//                {
//                    delete this;
//                }

//                return lrefCount;
//            }

//            operator PlatformDependencies::ROADByte*()
//            {
//                return _data.get();
//            }

//            PlatformDependencies::ROADByte* releaseData()
//            {
//                return _data.release();
//            }


//        private:

//            std::atomic<long> refCount;

//            std::unique_ptr<PlatformDependencies::ROADByte> _data;

//        };

        class ROADOVERSHARED_EXPORT ROADRawMetaDataContainer
        {
//            private: std::shared_ptr<PlatformDependencies::ROADByte> _data;

            private: ROADdecoder::Driver::SmartPtr<ROADdecoder::Driver::DataContainer> _ROADRawMetaData;

            private: PlatformDependencies::ROADUInt64 _dataLength;

            private: PlatformDependencies::ROADByte _head;

            public: ROADRawMetaDataContainer(const ROADRawMetaDataContainer& aInstance)
                :_dataLength(aInstance.getDataLength()),
                 _head(aInstance.getHead())
            {
                _ROADRawMetaData = aInstance.getDataContainer();
            }

            public: ROADRawMetaDataContainer(ROADdecoder::Driver::DataContainer* aData,
                                             PlatformDependencies::ROADUInt64 aDataLength,
                                             PlatformDependencies::ROADByte aHead)
                    :_dataLength(aDataLength),
                     _head(aHead)
            {
                _ROADRawMetaData = aData;
            }

            public: ~ROADRawMetaDataContainer()
                {
                }

            public: ROADdecoder::Driver::DataContainer* getDataContainer()  const
                {
                    return _ROADRawMetaData;
                }

            public: PlatformDependencies::ROADUInt64 getDataLength() const
                {
                    return this->_dataLength;
                }

            public: PlatformDependencies::ROADByte getHead()  const
                {
                    return this->_head;
                }

        };
    }
}


#endif // ROADRAWMETADATACONTAINER_H
