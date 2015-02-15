#include "LittleEndianConvertor.h"


PlatformDependencies::ROADUInt32 Endian::LittleEndianConvertor::convertToUINT32(PtrROADByte aData) {

    ROADUInt32 lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 24;

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToINT32(PtrROADByte aData) {

    ROADInt32 lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 24;

    return lresult;
}

PlatformDependencies::ROADUInt16 Endian::LittleEndianConvertor::convertToUINT16(PtrROADByte aData) {

    ROADUInt16 lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    return lresult;
}

PlatformDependencies::ROADInt16 Endian::LittleEndianConvertor::convertToINT16(PtrROADByte aData) {

    ROADInt16 lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    return lresult;
}

PlatformDependencies::ROADUInt8 Endian::LittleEndianConvertor::convertToUINT8(PtrROADByte aData) {

    ROADUInt8 lresult = 0;

    lresult |= (*aData);

    return lresult;
}

PlatformDependencies::ROADInt8 Endian::LittleEndianConvertor::convertToINT8(PtrROADByte aData) {

    ROADInt8 lresult = 0;

    lresult |= (*aData);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADUInt32 aValue,PtrROADByte aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 24;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADInt32 aValue,PtrROADByte aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 24;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADUInt16 aValue, PtrROADByte aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADInt16 aValue, PtrROADByte aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADUInt8 aValue, PtrROADByte aData) {

    *aData = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADInt8 aValue, PtrROADByte aData) {

    *aData = aValue;

    return sizeof(aValue);
}

