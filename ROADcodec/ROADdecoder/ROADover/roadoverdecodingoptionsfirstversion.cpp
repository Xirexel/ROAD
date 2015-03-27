#include "ROADoverDecodingOptionsFirstVersion.h"


using namespace PlatformDependencies;

ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::ROADoverDecodingOptionsFirstVersion(std::list<ROADRawMetaDataContainer> aListROADRawMetaDataContainer)
{
    auto lIter = aListROADRawMetaDataContainer.begin();

    auto lEndIter = aListROADRawMetaDataContainer.end();

    for(; lIter != lEndIter; ++lIter)
    {
        auto lBlockHead = (*lIter).getHead();

        auto lBlockLength = (*lIter).getDataLength();

        auto lData = (*lIter).getData();
    }
}

ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::~ROADoverDecodingOptionsFirstVersion()
{

}


ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getROADFormatMode()
{

}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getFrameSampleLength()
{

}

ROADUInt8 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getMaxSuperFrameLength()
{

}

ROADUInt8 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getRangSampleLengthPowerOfTwoScale()
{

}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getOriginalSamplesPerRang()
{

}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getInitRangSampleLength()
{
    return 4;
}

ROADUInt8 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getAmountRangLevels()
{

}

ROADByte ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getDomainShift()
{

}

ROADByte ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getMixingChannelsMode()
{

}

ROADUInt16 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getAmountOfChannels()
{

}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getEncriptionFormat()
{

}

ROADdecoder::ROADover::ROADRawDataFormat ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getBitsPerSampleCode()
{

}

ROADUInt16 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getSelectedPreListeningChannel()
{

}

ROADUInt8 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getEndianType()
{

}

ROADInt8 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getConstantScale()
{

}

ROADUInt32 ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::getOriginalFrequency()
{

}

void ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::setFrequencyScale(ROADUInt32 aValue)
{

}

void ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::readROADINFO(ROADdecoder::Driver::IDataReadDriver *aIDataWriteDriver)
{

}

void ROADdecoder::ROADover::ROADoverDecodingOptionsFirstVersion::readDATAINFO(ROADdecoder::Driver::IDataReadDriver *aIDataWriteDriver)
{

}
