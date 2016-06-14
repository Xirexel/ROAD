#include "EndianConvertorFactory.h"
#include "BigEndianConvertor.h"
#include "LittleEndianConvertor.h"
#include "LocalEndianConvertor.h"


PlatformDependencies::Unique_ptr<Endian::IEndianConvertor> Endian::EndianConvertorFactory::getIEndianConvertor(Endian::EndianType aType) {

    PlatformDependencies::Unique_ptr<Endian::IEndianConvertor> lResult(new LocalEndianConvertor);

    do
    {
        if(this->_localEndianType == aType)
            break;

        switch(aType)
        {
            case EndianType::LITTLE:
            lResult.reset(new LittleEndianConvertor);
            break;

            case EndianType::BIG:
            lResult.reset(new BigEndianConvertor);
            break;
        }

    }
    while(false);

    return lResult;
}

Endian::EndianType Endian::EndianConvertorFactory::getLocalEndianType()
{
    return this->_localEndianType;
}

Endian::EndianConvertorFactory::EndianConvertorFactory()
{    
    const ROADUInt16 lx = 1;

    this->_localEndianType = *((PtrROADByte)&lx) == 1? Endian::EndianType::LITTLE : Endian::EndianType::BIG;
}

Endian::EndianConvertorFactory& Endian::EndianConvertorFactory::getInstance()
{
    static EndianConvertorFactory sInstance;

    return sInstance;
}

Endian::EndianConvertorFactory::~EndianConvertorFactory()
{

}
