#include "RawDataBuffer.h"
#include "DoubleDataContainer.h"

ROADcoder::ROADoverCoder::IDoubleDataContainer* ROADcoder::ROADoverCoder::RawDataBuffer::getIDoubleDataContainer(unsigned int aIndex) {
    return this->_dataCollection.at(aIndex);
}

unsigned int ROADcoder::ROADoverCoder::RawDataBuffer::getCount() {
    return this->_channelCount;
}

ROADcoder::ROADoverCoder::RawDataBuffer::RawDataBuffer(unsigned int aChannelCount, unsigned int aLength)
    : _channelCount(aChannelCount)
{
    for(decltype(this->_channelCount) lindex = 0;
        lindex < this->_channelCount;
        ++lindex)
    {
        this->_dataCollection.push_back(new DoubleDataContainer(aLength));
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
