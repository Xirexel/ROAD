#include "BigEndianConvertor.h"

PlatformDependencies::ROADUInt32 Endian::BigEndianConvertor::convertToUINT32(ROADPtrByte aData) {

    ROADUInt32 lresult = 0;

    lresult |= (*aData++) << 24;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToINT32(ROADPtrByte aData) {

    ROADInt32 lresult = 0;

    lresult |= (*aData++) << 24;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADUInt16 Endian::BigEndianConvertor::convertToUINT16(ROADPtrByte aData) {

    ROADUInt16 lresult = 0;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADInt16 Endian::BigEndianConvertor::convertToINT16(ROADPtrByte aData) {

    ROADInt16 lresult = 0;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADUInt32 aValue,ROADPtrByte aData) {

    *aData++ = aValue >> 24;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADInt32 aValue,ROADPtrByte aData) {

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADUInt16 aValue,ROADPtrByte aData) {

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADInt16 aValue, ROADPtrByte aData) {

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

