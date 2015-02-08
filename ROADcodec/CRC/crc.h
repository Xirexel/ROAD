#ifndef CRC_H
#define CRC_H


namespace CRCSupport
{

    class CRC
    {

    public:

        static unsigned char CRC8(unsigned char *pcBlock, unsigned int len);

        static unsigned short CRC16(unsigned char *pcBlock, unsigned int len);

        static unsigned int CRC32(unsigned char *pcBlock, unsigned int len);

    private:

        CRC() = delete;

        CRC(const CRC&) = delete;

        CRC& operator=(const CRC&) = delete;

    };

}

#endif // CRC_H
