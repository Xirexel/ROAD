#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "LittleEndianConvertor.h"

#define UNUSED(expr) do { (void)(expr); } while (0)

unsigned int Endian::LittleEndianConvertor::convertToUINT32(unsigned char* aData) {
    UNUSED(aData);
	throw "Not yet implemented";
}

int Endian::LittleEndianConvertor::convertToINT32(unsigned char* aData) {
    UNUSED(aData);
	throw "Not yet implemented";
}

unsigned short Endian::LittleEndianConvertor::convertToUINT16(unsigned char* aData) {
    UNUSED(aData);
	throw "Not yet implemented";
}

short Endian::LittleEndianConvertor::convertToINT16(unsigned char* aData) {
    UNUSED(aData);
	throw "Not yet implemented";
}
