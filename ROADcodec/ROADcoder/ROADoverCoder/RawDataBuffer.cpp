#include "RawDataBuffer.h"
#include "RealDataContainer.h"

ROADcoder::ROADoverCoder::IRealDataContainer* ROADcoder::ROADoverCoder::RawDataBuffer::getIRealDataContainer(ROADUInt32 aIndex) {
    return this->_dataCollection.at(aIndex);
}

PlatformDependencies::ROADUInt32 ROADcoder::ROADoverCoder::RawDataBuffer::getCount() {
    return this->_channelCount;
}

ROADcoder::ROADoverCoder::RawDataBuffer::RawDataBuffer(ROADUInt32 aChannelCount, ROADUInt32 aLength)
    : _channelCount(aChannelCount)
{
    for(decltype(this->_channelCount) lindex = 0;
        lindex < this->_channelCount;
        ++lindex)
    {
        this->_dataCollection.push_back(new RealDataContainer(aLength));
    }
}


ROADcoder::ROADoverCoder::RawDataBuffer::~RawDataBuffer()
{
    for(auto item: this->_dataCollection)
    {
        delete item;
    }

    this->_dataCollection.clear();
}
