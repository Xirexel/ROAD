#include "LittleEndianConvertor.h"


PlatformDependencies::ROADUInt32 Endian::LittleEndianConvertor::convertToUINT32(ROADPtrByte aData) {

    ROADUInt32 lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 24;

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToINT32(ROADPtrByte aData) {

    ROADInt32 lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 24;

    return lresult;
}

PlatformDependencies::ROADUInt16 Endian::LittleEndianConvertor::convertToUINT16(ROADPtrByte aData) {

    ROADUInt16 lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    return lresult;
}

PlatformDependencies::ROADInt16 Endian::LittleEndianConvertor::convertToINT16(ROADPtrByte aData) {

    ROADInt16 lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADUInt32 aValue,ROADPtrByte aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 24;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADInt32 aValue,ROADPtrByte aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 24;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADUInt16 aValue, ROADPtrByte aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LittleEndianConvertor::convertToBytes(ROADInt16 aValue, ROADPtrByte aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    return sizeof(aValue);
}

