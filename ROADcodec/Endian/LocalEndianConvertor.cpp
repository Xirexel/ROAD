#include <string.h>


#include "LocalEndianConvertor.h"

PlatformDependencies::ROADUInt32 Endian::LocalEndianConvertor::convertToUINT32(ROADPtrByte aData) {
    ROADUInt32 lresult = *(ROADUInt32*)(aData);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToINT32(ROADPtrByte aData) {
    ROADInt32 lresult = *(ROADPtrInt32)(aData);

    return lresult;
}

PlatformDependencies::ROADUInt16 Endian::LocalEndianConvertor::convertToUINT16(ROADPtrByte aData) {
    ROADUInt16 lresult = *(ROADPtrUInt16)(aData);

    return lresult;
}

PlatformDependencies::ROADInt16 Endian::LocalEndianConvertor::convertToINT16(ROADPtrByte aData) {
    ROADInt16 lresult = *(ROADPtrInt16)(aData);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADUInt32 aValue,ROADPtrByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADInt32 aValue,ROADPtrByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADUInt16 aValue,ROADPtrByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADInt16 aValue,ROADPtrByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

