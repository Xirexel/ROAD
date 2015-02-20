#include "DomainPool.h"
#include "Domain.h"

ROADcoder::ROADCoder::DomainPool::DomainPool(ROADUInt32 aSize,
                                             ROADUInt32 aRangTopSampleLength,
                                             ROADUInt32 aDomainRelativeShift)
    : _size(aSize),
      _domainRelativeShift(aDomainRelativeShift),
      _rangTopSampleLength(aRangTopSampleLength)
{
    ROADUInt32 lcount = aSize;

    while(lcount > 0)
    {
        _domains.push_back(new ROADcoder::ROADCoder::Domain(aRangTopSampleLength));

        --lcount;
    }


}

ROADcoder::ROADCoder::Domain* ROADcoder::ROADCoder::DomainPool::getDomain(ROADUInt32 aIndex) {
    return _domains.at(aIndex);
}

void ROADcoder::ROADCoder::DomainPool::populate(PtrROADReal aData) {

    for(ROADUInt32 index = 0;
        index < _size;
        ++index)
    {
        _domains.at(index)->populate(aData + index, _rangTopSampleLength);
    }
}


PlatformDependencies::ROADUInt32 ROADcoder::ROADCoder::DomainPool::getSize() {
	return this->_size;
}

ROADcoder::ROADCoder::DomainPool::~DomainPool()
{
    for(auto item: _domains)
        delete item;

    _domains.clear();
}
