#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __LittleEndianConvertor_h__
#define __LittleEndianConvertor_h__

namespace ROADoverEncoding
{
	class LittleEndianConvertor;
}

namespace ROADoverEncoding
{
	class LittleEndianConvertor
	{
        public: static void intBigToLittle(unsigned int aParameter, char* aData);

        private: union IntToBytes
        {
            unsigned int Int;
            char Chars[4];
        };
	};
}

#endif
