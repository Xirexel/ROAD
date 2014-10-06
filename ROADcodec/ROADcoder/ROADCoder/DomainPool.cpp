#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DomainPool.h"
#include "Domain.h"

ROADcoder::ROADCoder::DomainPool::DomainPool(unsigned int aSize,
                                             unsigned int aRangTopSampleLength,
                                             unsigned int aDomainRelativeShift)
    : _size(aSize),
      _domainRelativeShift(aDomainRelativeShift),
      _rangTopSampleLength(aRangTopSampleLength)
{
    unsigned int lcount = aSize;

    while(lcount > 0)
    {
        _domains.push_back(new ROADcoder::ROADCoder::Domain(aRangTopSampleLength));

        --lcount;
    }


}

ROADcoder::ROADCoder::Domain* ROADcoder::ROADCoder::DomainPool::getDomain(unsigned int aIndex) {
    return _domains.at(aIndex);
}

void ROADcoder::ROADCoder::DomainPool::populate(double* aData) {

    for(unsigned int index = 0;
        index < _size;
        ++index)
    {
        _domains.at(index)->populate(aData + index, _rangTopSampleLength);
    }
}


unsigned int ROADcoder::ROADCoder::DomainPool::getSize() {
	return this->_size;
}

ROADcoder::ROADCoder::DomainPool::~DomainPool()
{
    for(auto item: _domains)
        delete item;

    _domains.clear();
}
