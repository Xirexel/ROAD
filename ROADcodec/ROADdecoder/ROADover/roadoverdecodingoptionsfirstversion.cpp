#include "ROADoverDecodingOptionsFirstVersion.h"
#include "DataDriver.h"


using namespace PlatformDependencies;

ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::ROADoverDecodingOptionsFirstVersion(std::list<ROADRawMetaDataContainer> &aListROADRawMetaDataContainer)
{
    auto lIter = aListROADRawMetaDataContainer.begin();

    auto lEndIter = aListROADRawMetaDataContainer.end();

    for(; lIter != lEndIter; ++lIter)
    {
        auto lBlockHead = (*lIter).getHead();

        auto lBlockLength = (*lIter).getDataLength();

        auto lData = (*lIter).getData();

        Endian::EndianType lEndianType = Endian::EndianType::LITTLE;

        if((lBlockHead & 128) == 0)
            lEndianType = Endian::EndianType::BIG;

        auto lptrIDataReadDriver = ROADdecoder::Driver::DataDriver::getIDataReadDriver(
                    lData,
                    lBlockLength + sizeof(lBlockLength) + sizeof(lBlockHead),
                    lEndianType);

        ROADByte lBlockType = lBlockHead & 127;

        switch(lBlockType)
        {
        case 0:
            readROADINFO(lptrIDataReadDriver.get());
            break;

        case 127:
            readDATAINFO(lptrIDataReadDriver.get());
            break;

        default:
            break;
        }
    }
}

ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::~ROADoverDecodingOptionsFirstVersion()
{

}


ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getROADFormatMode()
{
    return 1;
}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getFrameSampleLength()
{
    return 2048;
}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getMaxSuperFrameLength()
{
    return (ROADUInt32)this->_maxSuperFrameLength + 1;
}

ROADUInt8 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getRangSampleLengthPowerOfTwoScale()
{
    return this->_rangSampleLengthPowerOfTwoScale;
}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getOriginalSamplesPerRang()
{
    return getInitRangSampleLength() << getRangSampleLengthPowerOfTwoScale();
}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getInitRangSampleLength()
{
    return 4;
}

ROADUInt8 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getAmountRangLevels()
{
    return this->_amountRangLevels;
}

ROADByte ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getDomainShift()
{
    return this->_domainShift;
}

ROADByte ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getMixingChannelsMode()
{
    return this->_mixingChannelsMode;
}

ROADUInt16 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getAmountOfChannels()
{
    return this->_amountOfChannels;
}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getEncryptionFormat()
{
    return this->_encryptionFormat;
}

ROADdecoder::ROADover::ROADRawDataFormat ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getBitsPerSampleCode()
{
    return this->_bitsPerSampleCode;
}

ROADUInt16 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getSelectedPreListeningChannel()
{
    return this->_selectedPreListeningChannel;
}

ROADUInt8 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getEndianType()
{
    return this->_endianType;
}

ROADInt8 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getConstantScale()
{
    return this->_constantScale;
}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getOriginalFrequency()
{
    return this->_originalFrequency;
}

void ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::setFrequencyScale(ROADUInt32 aValue)
{

}

void ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::readROADINFO(ROADdecoder::Driver::IDataReadDriver* aIDataReadDriver)
{
    class CRCCheckingROADINFOException: public std::exception
    {
    public:

        CRCCheckingROADINFOException() _GLIBCXX_USE_NOEXCEPT
        {

        }

        virtual const char* what() const _GLIBCXX_USE_NOEXCEPT
        {
            return "CRC checking error of ROADINFO analyzer!!!";
        }

        ~CRCCheckingROADINFOException() _GLIBCXX_USE_NOEXCEPT
        {

        }
    };

    ROADBool lOk = false;

    aIDataReadDriver->computeAndCheckCRC16(28, lOk);

    if(!lOk)
        throw CRCCheckingROADINFOException();

    ROADUInt8 lHead;

    ROADUInt64 lLength;

    aIDataReadDriver->operator >>(lHead)  // 1 byte: 7 bit - Endian flag, 6 to 0 bits - code of block: ROADINFO - 0
                               >> lLength // 8 bytes: length of block
                               >> this->_amountOfChannels // 2 bytes: original amount of channels
                               >> this->_bitsPerSampleCodeValue // 1 byte: code of bits per sample:
                                          /* U8 = 0x08 - unsigned integer 8 bits,
                                           * S8 = 0xF8 - signed integer 8 bits,
                                           * U12 = 0xF4 - unsigned integer 12 bits,
                                           * S12 = 0x0C - signed integer 12 bits,
                                           * U16 = 0xF0 - unsigned integer 16 bits,
                                           * S16 = 0x10 - signed integer 16 bits,
                                           * U20 = 0xEC - unsigned integer 20 bits,
                                           * S20 = 0x14 - signed integer 20 bits,
                                           * U24 = 0xE8 - unsigned integer 24 bits,
                                           * S24 = 0x18 - signed integer 24 bits,
                                           * U32 = 0xE0 - unsigned integer 32 bits,
                                           * S32 = 0x20 - signed integer 32 bits,
                                           * U64 = 0xC0 - unsigned integer 64 bits,
                                           * S64 = 0x40 - signed integer 64 bits,
                                           * F32 = 0x46 - float 32 bits,
                                           * D64 = 0x44 - double 64 bits*/
                               >> this->_originalFrequency // 4 bytes: original frequency of samples.
                               >> this->_mixingChannelsMode // 1 byte: code of mixing channels - 0(NONE), 1(MID - prelistening channel is averade of sterio), 2(SIDE - prelistening channel is diff of sterio), 3(CUSTOMIZE - select one channel for prelistening)
                               >> this->_selectedPreListeningChannel // 2 bytes: selected channel for prelistening.
                               >> this->_maxSuperFrameLength // 1 byte: maximum amount of frames in one super frame - from 1 to 256 (0 to 255).
                               >> this->_amountRangLevels // 1 byte:  Depth of bintree of the fractal analyse (0 - 3)
                               >> this->_rangSampleLengthPowerOfTwoScale // 1 byte: ths scale of initial range length 4 samples - 4 * 2^n (0 to 11)
                               >> this->_constantScale // 1 byte: value of constant scale - if equal 0 than scale is read from data stream.
                               >> this->_domainShift // 1 byte: shifting between two neighbour domains by 2^n
                               >> this->_encryptionFormat; // 4 bytes: unique code of encription.

    this->_endianType = Endian::EndianType::LITTLE;

    if((lHead & 128) == 0)
        this->_endianType = Endian::EndianType::BIG;

    checkBitsPerSampleCode();

}

void ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::checkBitsPerSampleCode()
{
    switch(this->_bitsPerSampleCodeValue)
    {
    case ROADRawDataFormat::U8:
        this->_bitsPerSampleCode = ROADRawDataFormat::U8;
        break;

    case ROADRawDataFormat::S8:
        this->_bitsPerSampleCode = ROADRawDataFormat::S8;
        break;

    case ROADRawDataFormat::D64:
        this->_bitsPerSampleCode = ROADRawDataFormat::D64;
        break;

    case ROADRawDataFormat::F32:
        this->_bitsPerSampleCode = ROADRawDataFormat::F32;
        break;

    case ROADRawDataFormat::S12:
        this->_bitsPerSampleCode = ROADRawDataFormat::S12;
        break;

    case ROADRawDataFormat::S16:
        this->_bitsPerSampleCode = ROADRawDataFormat::S16;
        break;

    case ROADRawDataFormat::S20:
        this->_bitsPerSampleCode = ROADRawDataFormat::S20;
        break;

    case ROADRawDataFormat::S24:
        this->_bitsPerSampleCode = ROADRawDataFormat::S24;
        break;

    case ROADRawDataFormat::S32:
        this->_bitsPerSampleCode = ROADRawDataFormat::S32;
        break;

    case ROADRawDataFormat::S64:
        this->_bitsPerSampleCode = ROADRawDataFormat::S64;
        break;

    case ROADRawDataFormat::U12:
        this->_bitsPerSampleCode = ROADRawDataFormat::U12;
        break;

    case ROADRawDataFormat::U16:
        this->_bitsPerSampleCode = ROADRawDataFormat::U16;
        break;

    case ROADRawDataFormat::U20:
        this->_bitsPerSampleCode = ROADRawDataFormat::U20;
        break;

    case ROADRawDataFormat::U24:
        this->_bitsPerSampleCode = ROADRawDataFormat::U24;
        break;

    case ROADRawDataFormat::U32:
        this->_bitsPerSampleCode = ROADRawDataFormat::U32;
        break;

    case ROADRawDataFormat::U64:
        this->_bitsPerSampleCode = ROADRawDataFormat::U64;
        break;

    default:
        this->_bitsPerSampleCode = ROADRawDataFormat::UNKNOWNDataFormat;
        break;

    }


}

void ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::readDATAINFO(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver)
{
    class CRCCheckingDATAINFOException: public std::exception
    {
    public:

        CRCCheckingDATAINFOException() _GLIBCXX_USE_NOEXCEPT
        {

        }

        virtual const char* what() const _GLIBCXX_USE_NOEXCEPT
        {
            return "CRC checking error of DATAINFO analyzer!!!";
        }

        ~CRCCheckingDATAINFOException() _GLIBCXX_USE_NOEXCEPT
        {

        }
    };

    ROADBool lOk = false;

    aIDataReadDriver->computeAndCheckCRC16(17, lOk);

    if(!lOk)
        throw CRCCheckingDATAINFOException();

    ROADUInt8 lHead;

    ROADUInt64 lLength;

    aIDataReadDriver->operator>>(lHead) // 1 byte: 7 bit - Endian flag, 6 to 0 bits - code of block: DATAINFO - 127
                              >> lLength // 8 bytes: length of block
                              >> _amountOfSamples;  // 8 bytes: amount of samples

}
