#include <string.h>


#include "LocalEndianConvertor.h"

PlatformDependencies::ROADUInt64 Endian::LocalEndianConvertor::convertToType(ROADUInt64, PtrROADByte aData) {
    ROADUInt64 lresult = *(PtrROADUInt64)(aData);

    return lresult;
}

PlatformDependencies::ROADInt64 Endian::LocalEndianConvertor::convertToType(ROADInt64, PtrROADByte aData) {
    ROADInt64 lresult = *(PtrROADInt64)(aData);

    return lresult;
}

PlatformDependencies::ROADUInt32 Endian::LocalEndianConvertor::convertToType(ROADUInt32, PtrROADByte aData) {
    ROADUInt32 lresult = *(PtrROADUInt32)(aData);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToType(ROADInt32, PtrROADByte aData) {
    ROADInt32 lresult = *(PtrROADInt32)(aData);

    return lresult;
}

PlatformDependencies::ROADUInt16 Endian::LocalEndianConvertor::convertToType(ROADUInt16, PtrROADByte aData) {
    ROADUInt16 lresult = *(PtrROADUInt16)(aData);

    return lresult;
}

PlatformDependencies::ROADInt16 Endian::LocalEndianConvertor::convertToType(ROADInt16, PtrROADByte aData) {
    ROADInt16 lresult = *(PtrROADInt16)(aData);

    return lresult;
}

PlatformDependencies::ROADUInt8 Endian::LocalEndianConvertor::convertToType(ROADUInt8, PtrROADByte aData) {
    ROADUInt8 lresult = *(PtrROADUInt8)(aData);

    return lresult;
}

PlatformDependencies::ROADInt8 Endian::LocalEndianConvertor::convertToType(ROADInt8, PtrROADByte aData) {
    ROADInt8 lresult = *(PtrROADInt8)(aData);

    return lresult;
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADUInt64 aValue, PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADInt64 aValue,PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADUInt32 aValue, PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADInt32 aValue,PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADUInt16 aValue, PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADInt16 aValue,PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADUInt8 aValue, PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

PlatformDependencies::ROADInt32 Endian::LocalEndianConvertor::convertToBytes(ROADInt8 aValue,PtrROADByte aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

