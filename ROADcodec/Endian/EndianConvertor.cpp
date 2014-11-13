#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "EndianConvertor.h"
#include "IConvertor.h"
#include "BigEndianConvertor.h"
#include "LittleEndianConvertor.h"

namespace Endian {

template<typename B = BigEndianConvertor, typename L = LittleEndianConvertor>
constexpr auto checkEndian()
{
    unsigned short x = 1;

    return (*((unsigned char *) &x) == 0 ? B: L); // "big-endian" : "little-endian";
}

}

Endian::EndianConvertor::EndianConvertor()
{

}

Endian::EndianConvertor& Endian::EndianConvertor::getInstance()
{
    static EndianConvertor instance;

    return instance;
}

unsigned int Endian::EndianConvertor::convertToUINT32(unsigned char* aData) {
	throw "Not yet implemented";
}

int Endian::EndianConvertor::convertToINT32(unsigned char* aData) {
	throw "Not yet implemented";
}

unsigned short Endian::EndianConvertor::convertToUINT16(unsigned char* aData) {
	throw "Not yet implemented";
}

short Endian::EndianConvertor::convertToINT16(unsigned char* aData) {
	throw "Not yet implemented";
}

Endian::EndianConvertor::~EndianConvertor() {
	throw "Not yet implemented";
}

