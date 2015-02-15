#include "ROADover.h"
#include "IROADoverDecodingOptions.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "ROADoverManagerExperemental.h"


ROADdecoder::ROADover::ROADover::ROADover(ROADdecoder::ROADover::IROADoverDecodingOptions* aOptions)
{
    switch(aOptions->getROADFormatMode())
    {
        case ROADdecoder::ROADover::EXPEREMENTAL:
        {        
            auto lexperementalOptions = dynamic_cast<ROADoverDecodingOptionsExperemental*>(aOptions);

            this->_amountOfChannels = lexperementalOptions->getAmountOfChannels();

            this->_superframeLength = lexperementalOptions->getSuperframeLength();

            this->_frameRangLength = lexperementalOptions->getFrameRangLength();

            this->_samplesPerRang = lexperementalOptions->getSamplesPerRang();

            _manager = new ROADoverManagerExperemental(this, lexperementalOptions);

        }
        break;

        case ROADdecoder::ROADover::UNKNOWN:
        default:

        break;
    }
}

ROADdecoder::ROADover::Result ROADdecoder::ROADover::ROADover::decode() {
    Result result = Result::ERROR;

    result = _manager->decode();

    return result;
}

ROADdecoder::ROADover::ROADover::~ROADover()
{
    delete this->_manager;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADover::getAmountOfChannels()
{
    return this->_amountOfChannels;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADover::getSuperframeLength()
{
    return this->_superframeLength;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADover::getFrameRangLength()
{
    return this->_frameRangLength;
}

PlatformDependencies::ROADUInt32 ROADdecoder::ROADover::ROADover::getSamplesPerRang()
{
    return this->_samplesPerRang;
}
