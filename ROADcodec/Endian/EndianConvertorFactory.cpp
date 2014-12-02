#include <string>
#include <vector>
#include <exception>
#include <memory>
using namespace std;

#include "EndianConvertorFactory.h"
#include "BigEndianConvertor.h"
#include "LittleEndianConvertor.h"
#include "LocalEndianConvertor.h"


#include "endian_global.h"


std::unique_ptr<Endian::IEndianConvertor> Endian::EndianConvertorFactory::getIEndianConvertor(Endian::EndianType aType) {


    unsigned short x = 1;

    unique_ptr<Endian::IEndianConvertor> result(new LocalEndianConvertor);

    Endian::EndianType llocalType = *((unsigned char*)&x) == 1? LITTLE : BIG;

    do
    {
        if(llocalType == aType)
            break;

        switch(aType)
        {
            case LITTLE:
            result.reset(new LittleEndianConvertor);
            break;

            case BIG:
            result.reset(new BigEndianConvertor);
            break;
        }

    }
    while(false);

    return result;
}

