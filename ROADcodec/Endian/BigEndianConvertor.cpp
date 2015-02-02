#include "BigEndianConvertor.h"

unsigned int Endian::BigEndianConvertor::convertToUINT32(unsigned char* aData) {

    unsigned int lresult = 0;

    lresult |= (*aData++) << 24;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

int Endian::BigEndianConvertor::convertToINT32(unsigned char* aData) {

    int lresult = 0;

    lresult |= (*aData++) << 24;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

unsigned short Endian::BigEndianConvertor::convertToUINT16(unsigned char* aData) {

    unsigned short lresult = 0;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

short Endian::BigEndianConvertor::convertToINT16(unsigned char* aData) {

    short lresult = 0;

    lresult |= (*aData++) << 8;

    lresult |= (*aData++);

    return lresult;
}

int Endian::BigEndianConvertor::convertToBytes(unsigned int aValue, unsigned char* aData) {

    *aData++ = aValue >> 24;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

int Endian::BigEndianConvertor::convertToBytes(int aValue, unsigned char* aData) {

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

int Endian::BigEndianConvertor::convertToBytes(unsigned short aValue, unsigned char* aData) {

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

int Endian::BigEndianConvertor::convertToBytes(short aValue, unsigned char* aData) {

    *aData++ = aValue >> 8;

    *aData++ = aValue;

    return sizeof(aValue);
}

