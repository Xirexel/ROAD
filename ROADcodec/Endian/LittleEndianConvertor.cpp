#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "LittleEndianConvertor.h"

unsigned int Endian::LittleEndianConvertor::convertToUINT32(unsigned char* aData) {
    return this->_ui32(aData);
}

int Endian::LittleEndianConvertor::convertToINT32(unsigned char* aData) {
    return this->_i32(aData);
}

unsigned short Endian::LittleEndianConvertor::convertToUINT16(unsigned char* aData) {
    return this->_ui16(aData);
}

short Endian::LittleEndianConvertor::convertToINT16(unsigned char* aData) {
    return this->_i16(aData);
}

