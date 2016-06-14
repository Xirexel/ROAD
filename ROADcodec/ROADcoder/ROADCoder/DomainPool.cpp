#include "DomainPool.h"
#include "Domain.h"

ROADcoder::ROADCoder::DomainPool::DomainPool(ROADSize aSize,
                                             ROADUInt32 aRangTopSampleLength,
                                             ROADUInt32 aDomainRelativeShift)
    : _size(aSize),
      _domainRelativeShift(aDomainRelativeShift),
      _rangTopSampleLength(aRangTopSampleLength),
      _domains(aSize)
{
    ROADUInt32 lcount = aSize;

    while(lcount > 0)
    {
        _domains.push_back(new ROADcoder::ROADCoder::Domain(aRangTopSampleLength >> 1));

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


PlatformDependencies::ROADSize ROADcoder::ROADCoder::DomainPool::getSize() {
	return this->_size;
}

ROADcoder::ROADCoder::DomainPool::~DomainPool()
{
    for(auto item: _domains)
        delete item;

    _domains.clear();
}
