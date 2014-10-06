#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "LocalEndianConvertor.h"

#define UNUSED(expr) do { (void)(expr); } while (0)

unsigned int Endian::LocalEndianConvertor::convertToUINT32(unsigned char* aData) {
    return *((unsigned int *)(aData));
}

int Endian::LocalEndianConvertor::convertToINT32(unsigned char* aData) {
    UNUSED(aData);
	throw "Not yet implemented";
}

unsigned short Endian::LocalEndianConvertor::convertToUINT16(unsigned char* aData) {
    UNUSED(aData);
	throw "Not yet implemented";
}

short Endian::LocalEndianConvertor::convertToINT16(unsigned char* aData) {
    UNUSED(aData);
	throw "Not yet implemented";
}

