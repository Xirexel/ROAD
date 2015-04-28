#ifndef __ROADdecoder__ROADover__RawDataBuffer_h__
#define __ROADdecoder__ROADover__RawDataBuffer_h__

#include <vector>

#include "IRawDataBuffer.h"


#include "DecodedDataContainer.h"


namespace ROADdecoder
{
	namespace ROADover
	{

        template<typename ROADDecodedSampleType>
        class RawDataBuffer: public IRawDataBuffer
        {
            private: typedef ROADDecodedSampleType DecodedSampleType;
            private: typedef DecodedDataContainer<DecodedSampleType> DecodedDataContainerType;
            private: typedef DecodedDataContainer<DecodedSampleType>* PtrDecodedDataContainerType;
            private: ROADUInt32 _count;
            private: ROADUInt32 _length;
            private: std::vector<PtrDecodedDataContainerType> _dataCollection;

            public: RawDataBuffer(ROADUInt32 aCount, ROADUInt32 aSuperFrameLength)
                : _count(aCount),
                  _length(aSuperFrameLength)
            {
                for(decltype(aCount) index = 0;
                    index < aCount;
                    ++index)
                    _dataCollection.push_back(new DecodedDataContainerType(aSuperFrameLength));
            }

            public: virtual ~RawDataBuffer()
            {

                for(auto item: _dataCollection)
                    delete item;

                _dataCollection.clear();
            }

            public: PtrDecodedDataContainerType getPtrDecodedDataContainer(ROADUInt32 aIndex)
            {
                return this->_dataCollection.at(aIndex);
            }

            public: ROADUInt32 getCount()
            {
                return this->_count;
            }

            public: ROADUInt32 getLength()
            {
                return this->_length;
            }

            public: virtual ROADdecoder::ROADover::ROADRawDataFormat getDecodedSampleTypeCode()
            {
                return DecodedSampleTypeToROADRawDataFormat<DecodedSampleType>::_code;
            }

        };
	}
}

#endif
