#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "LittleEndianConvertor.h"
void ROADoverEncoding::LittleEndianConvertor::intBigToLittle(unsigned int aParameter, char* aData)
{
    IntToBytes lIntToBytes;

    lIntToBytes.Int = aParameter;

    memcpy(aData, &lIntToBytes.Chars, 4);

}

