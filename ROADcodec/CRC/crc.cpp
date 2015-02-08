#include "crc.h"

unsigned char CRCSupport::CRC::CRC8(unsigned char *pcBlock, unsigned int len)
{
    unsigned char lresult = 0xFF;
    unsigned int i;

    while (len--)
    {
        lresult ^= *pcBlock++;

        for (i = 0; i < 8; i++)
            lresult = lresult & 0x80 ? (lresult << 1) ^ 0x31 : lresult << 1;
    }

    return lresult;
}

unsigned short CRCSupport::CRC::CRC16(unsigned char *pcBlock, unsigned int len)
{
    unsigned short lresult = 0;

    return lresult;
}

unsigned int CRCSupport::CRC::CRC32(unsigned char *pcBlock, unsigned int len)
{
    unsigned int lresult = 0;

    return lresult;
}
