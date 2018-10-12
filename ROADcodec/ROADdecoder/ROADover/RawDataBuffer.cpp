#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "RawDataBuffer.h"
#include "DoubleDataContainer.h"

ROADdecoder::ROADover::IDoubleDataContainer* ROADdecoder::ROADover::RawDataBuffer::getIDoubleDataContainer(unsigned int aIndex) {
    return this->_dataCollection.at(aIndex);
}

unsigned int ROADdecoder::ROADover::RawDataBuffer::getCount() {
    return this->_count;
}

unsigned int ROADdecoder::ROADover::RawDataBuffer::getLength()
{
    return this->_length;
}

ROADdecoder::ROADover::RawDataBuffer::~RawDataBuffer() {

    for(DoubleDataContainer *item: _dataCollection)
        delete item;

    _dataCollection.clear();
}

ROADdecoder::ROADover::RawDataBuffer::RawDataBuffer(unsigned int aCount, unsigned int aSuperFrameLength)
    : _count(aCount),
      _length(aSuperFrameLength)
{
    for(decltype(aCount) index = 0;
        index < aCount;
        ++index)
        _dataCollection.push_back(new DoubleDataContainer(aSuperFrameLength));
}
