#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "EndianConvertor.h"
#include "IConvertor.h"
#include "BigEndianConvertor.h"
#include "LittleEndianConvertor.h"


Endian::EndianConvertor::EndianConvertor()
{
    unsigned short x = 1;

    *((unsigned char *) &x) == 0 ? _convertor = new BigEndianConvertor: _convertor = new LittleEndianConvertor; // "big-endian" : "little-endian";

}

Endian::EndianConvertor& Endian::EndianConvertor::getInstance()
{
    static EndianConvertor instance;

    return instance;
}

unsigned int Endian::EndianConvertor::convertToUINT32(unsigned char* aData) {
    return _convertor->convertToUINT32(aData);
}

int Endian::EndianConvertor::convertToINT32(unsigned char* aData) {
    return _convertor->convertToINT32(aData);
}

unsigned short Endian::EndianConvertor::convertToUINT16(unsigned char* aData) {
    return _convertor->convertToUINT16(aData);
}

short Endian::EndianConvertor::convertToINT16(unsigned char* aData) {
    return _convertor->convertToINT16(aData);
}

Endian::EndianConvertor::~EndianConvertor() {
    delete _convertor;
}

