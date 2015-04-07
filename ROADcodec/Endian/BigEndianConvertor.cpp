#include "BigEndianConvertor.h"

PlatformDependencies::ROADUInt64 Endian::BigEndianConvertor::convertToUINT64(PtrROADByte aData) {

    ROADUInt64 lresult = 0;

    lresult |= (*aData++) << 56;

    lresult |= (*aData++) << 48;

    lresult |= (*aData++) << 40;

    lresult |= (*aData++) << 32;

    lresult |= (*aData++) << 24;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADInt64 Endian::BigEndianConvertor::convertToINT64(PtrROADByte aData) {

    ROADInt64 lresult = 0;

    lresult |= (*aData++) << 56;

    lresult |= (*aData++) << 48;

    lresult |= (*aData++) << 40;

    lresult |= (*aData++) << 32;

    lresult |= (*aData++) << 24;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADUInt32 Endian::BigEndianConvertor::convertToUINT32(PtrROADByte aData) {

    ROADUInt32 lresult = 0;

    lresult |= (*aData++) << 24;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToINT32(PtrROADByte aData) {

    ROADInt32 lresult = 0;

    lresult |= (*aData++) << 24;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADUInt16 Endian::BigEndianConvertor::convertToUINT16(PtrROADByte aData) {

    ROADUInt16 lresult = 0;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADInt16 Endian::BigEndianConvertor::convertToINT16(PtrROADByte aData) {

    ROADInt16 lresult = 0;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

PlatformDependencies::ROADUInt8 Endian::BigEndianConvertor::convertToUINT8(PtrROADByte aData) {

    ROADUInt8 lresult = 0;

    lresult |= (*aData);

    return lresult;
}

PlatformDependencies::ROADInt8 Endian::BigEndianConvertor::convertToINT8(PtrROADByte aData) {

    ROADInt8 lresult = 0;

    lresult |= (*aData);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADUInt64 aValue,PtrROADByte aData) {

    *aData++ = aValue >> 56;

    *aData++ = aValue >> 48;

    *aData++ = aValue >> 40;

    *aData++ = aValue >> 32;

    *aData++ = aValue >> 24;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADInt64 aValue,PtrROADByte aData) {

    *aData++ = aValue >> 56;

    *aData++ = aValue >> 48;

    *aData++ = aValue >> 40;

    *aData++ = aValue >> 32;

    *aData++ = aValue >> 24;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADUInt32 aValue,PtrROADByte aData) {

    *aData++ = aValue >> 24;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADInt32 aValue,PtrROADByte aData) {

    *aData++ = aValue >> 24;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADUInt16 aValue,PtrROADByte aData) {

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADInt16 aValue, PtrROADByte aData) {

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADUInt8 aValue,PtrROADByte aData) {

    *aData = aValue;

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::BigEndianConvertor::convertToBytes(ROADInt8 aValue, PtrROADByte aData) {

    *aData = aValue;

    return sizeof(aValue);
}

