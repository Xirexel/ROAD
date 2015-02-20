#ifndef __ROADcoder__ROADoverCoder__ROADRawDataFormat_h__
#define __ROADcoder__ROADoverCoder__ROADRawDataFormat_h__

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		enum ROADRawDataFormat
		{
            U8 = 0x08, S8 = 0xF8, U12 = 0xF4, S12 = 0x0C, U16 = 0xF0, S16 = 0x10, U20 = 0xEC, S20=0x14,
            U24 = 0xE8, S24 = 0x18, U32 = 0xE0, S32 = 0x20, U64 = 0xC0, S64 = 0x40,
            UF32 = 0xBA, SF32 = 0x46, UD64 = 0xBC, SD64 = 0x44
		};
	}
}

#endif
