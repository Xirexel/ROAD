#include "RawDataBuffer.h"
#include "DoubleDataContainer.h"

ROADdecoder::ROADover::IDoubleDataContainer* ROADdecoder::ROADover::RawDataBuffer::getIDoubleDataContainer(ROADUInt32 aIndex) {
    return this->_dataCollection.at(aIndex);
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::RawDataBuffer::getCount() {
    return this->_count;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::RawDataBuffer::getLength()
{
    return this->_length;
}

ROADdecoder::ROADover::RawDataBuffer::~RawDataBuffer() {

    for(auto item: _dataCollection)
        delete item;

    _dataCollection.clear();
}

ROADdecoder::ROADover::RawDataBuffer::RawDataBuffer(ROADUInt32 aCount, ROADUInt32 aSuperFrameLength)
    : _count(aCount),
      _length(aSuperFrameLength)
{
    for(decltype(aCount) index = 0;
        index < aCount;
        ++index)
        _dataCollection.push_back(new DoubleDataContainer(aSuperFrameLength));
}

