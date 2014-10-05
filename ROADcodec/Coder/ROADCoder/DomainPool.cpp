#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "DomainPool.h"
#include "Domain.h"
#include "IDomain.h"

ROADEncoding::DomainPool::DomainPool(unsigned int aSize,
                                        unsigned int aRangeTopSampleLength,
                                        unsigned int aDomainRelativeShift)
    : _size(aSize),
      _domainRelativeShift(aDomainRelativeShift),
      _rangeTopSampleLength(aRangeTopSampleLength)
{
    unsigned int lcount = aSize;

    while(lcount > 0)
    {
        _domains.push_back(new ROADEncoding::Domain(aRangeTopSampleLength));

        --lcount;
    }


}

ROADEncoding::DomainPool::~DomainPool()
{
    for(ROADEncoding::Domain* item: _domains)
        delete item;

    _domains.clear();
}

ROADEncoding::IDomain* ROADEncoding::DomainPool::getIDomain(unsigned int aIndex) {
    return _domains.at(aIndex);
}

void ROADEncoding::DomainPool::populate(double* aData) {

    for(unsigned int index = 0;
        index < _size;
        ++index)
    {
        _domains.at(index)->populate(aData + index, _rangeTopSampleLength);
    }
}

unsigned int ROADEncoding::DomainPool::getSize() {
	return this->_size;
}

