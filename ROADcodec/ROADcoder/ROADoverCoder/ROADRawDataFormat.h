#ifndef __ROADcoder__ROADoverCoder__ROADRawDataFormat_h__
#define __ROADcoder__ROADoverCoder__ROADRawDataFormat_h__

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		enum ROADRawDataFormat
		{
            U8 = 8, S8 = -8, U16 = -16, S16 = 16, U24 = -24, S24 = 24, U32 = -32, S32 = 32, U64 = -64, S64 = 64,
            UF32 = 0xBA, SF32 = 0x46, UD64 = 0xBC, SD64 = 0x44
		};
	}
}

#endif
