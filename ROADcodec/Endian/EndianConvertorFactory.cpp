#include "EndianConvertorFactory.h"
#include "BigEndianConvertor.h"
#include "LittleEndianConvertor.h"
#include "LocalEndianConvertor.h"


std::unique_ptr<Endian::IEndianConvertor> Endian::EndianConvertorFactory::getIEndianConvertor(Endian::EndianType aType) {

    using namespace std;

    unique_ptr<Endian::IEndianConvertor> lResult(new LocalEndianConvertor);


    do
    {
        if(this->_localEndianType == aType)
            break;

        switch(aType)
        {
            case LITTLE:
            lResult.reset(new LittleEndianConvertor);
            break;

            case BIG:
            lResult.reset(new BigEndianConvertor);
            break;
        }

    }
    while(false);

    return lResult;
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
