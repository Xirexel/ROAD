#include "LittleEndianConvertor.h"


unsigned int Endian::LittleEndianConvertor::convertToUINT32(unsigned char* aData) {

    unsigned int lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 24;

    return lresult;
}

int Endian::LittleEndianConvertor::convertToINT32(unsigned char* aData) {

    int lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    lresult |= (*aData++) << 16;

    lresult |= (*aData++) << 24;

    return lresult;
}

unsigned short Endian::LittleEndianConvertor::convertToUINT16(unsigned char* aData) {

    unsigned short lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    return lresult;
}

short Endian::LittleEndianConvertor::convertToINT16(unsigned char* aData) {

    short lresult = 0;

    lresult |= (*aData++);

    lresult |= (*aData++) << 8;

    return lresult;
}

int Endian::LittleEndianConvertor::convertToBytes(unsigned int aValue,unsigned char* aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 24;

    return sizeof(aValue);
}

int Endian::LittleEndianConvertor::convertToBytes(int aValue,unsigned char *aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    *aData++ = aValue >> 16;

    *aData++ = aValue >> 24;

    return sizeof(aValue);
}

int Endian::LittleEndianConvertor::convertToBytes(unsigned short aValue, unsigned char *aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    return sizeof(aValue);
}

int Endian::LittleEndianConvertor::convertToBytes(short aValue, unsigned char *aData) {

    *aData++ = aValue;

    *aData++ = aValue >> 8;

    return sizeof(aValue);
}

