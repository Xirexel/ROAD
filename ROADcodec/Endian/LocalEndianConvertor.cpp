#include <string.h>


#include "LocalEndianConvertor.h"

unsigned int Endian::LocalEndianConvertor::convertToUINT32(unsigned char* aData) {
    unsigned int lresult = *(unsigned int*)(aData);

    return lresult;
}

int Endian::LocalEndianConvertor::convertToINT32(unsigned char* aData) {
    int lresult = *(int*)(aData);

    return lresult;
}

unsigned short Endian::LocalEndianConvertor::convertToUINT16(unsigned char* aData) {
    unsigned short lresult = *(unsigned short*)(aData);

    return lresult;
}

short Endian::LocalEndianConvertor::convertToINT16(unsigned char* aData) {
    short lresult = *(short*)(aData);

    return lresult;
}

int Endian::LocalEndianConvertor::convertToBytes(unsigned int aValue, unsigned char* aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

int Endian::LocalEndianConvertor::convertToBytes(int aValue, unsigned char* aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

int Endian::LocalEndianConvertor::convertToBytes(unsigned short aValue, unsigned char* aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

int Endian::LocalEndianConvertor::convertToBytes(short aValue, unsigned char* aData) {

    memcpy(aData, &aValue, sizeof(aValue));

    return sizeof(aValue);
}

