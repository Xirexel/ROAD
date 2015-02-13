#include <string.h>


#include "LocalEndianConvertor.h"

PlatformDependencies::ROADUInt32 Endian::LocalEndianConvertor::convertToUINT32(PtrROADByte aData) {
    ROADUInt32 lresult = *(ROADUInt32*)(aData);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToINT32(PtrROADByte aData) {
    ROADInt32 lresult = *(PtrROADInt32)(aData);

    return lresult;
}

PlatformDependencies::ROADUInt16 Endian::LocalEndianConvertor::convertToUINT16(PtrROADByte aData) {
    ROADUInt16 lresult = *(PtrROADUInt16)(aData);

    return lresult;
}

PlatformDependencies::ROADInt16 Endian::LocalEndianConvertor::convertToINT16(PtrROADByte aData) {
    ROADInt16 lresult = *(PtrROADInt16)(aData);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADUInt32 aValue,PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADInt32 aValue,PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADUInt16 aValue,PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADInt16 aValue,PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

