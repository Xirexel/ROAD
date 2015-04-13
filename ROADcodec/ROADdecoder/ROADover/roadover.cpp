#include "ROADover.h"
#include "IROADoverDecodingOptions.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "ROADoverManagerExperemental.h"
#include "ROADoverManagerFirstOrderVersion.h"
#include "IROADoverDecodingOptionsMainVersion.h"
#include "ROADoverManagerFirstOrderVersionTempROADInt32.h"
#include "ROADRawDataFormat.h"


ROADdecoder::ROADover::ROADover::ROADover(ROADdecoder::ROADover::IROADoverDecodingOptions* aOptions,
                                          Endian::EndianType aLowFormatEndianType)
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

            _manager.reset(new ROADoverManagerExperemental(this, lexperementalOptions));

        }
        break;

        case MAIN:
        {
            auto lmainOptions = dynamic_cast<IROADoverDecodingOptionsMainVersion*>(aOptions);

            if(lmainOptions == nullptr)
                break;

            this->_amountOfChannels = lmainOptions->getAmountOfChannels();

            this->_superframeLength = lmainOptions->getMaxSuperFrameLength();

            this->_frameRangLength = lmainOptions->getMaxFrameRangLength();

            this->_samplesPerRang = lmainOptions->getMinSamplesPerRang();


            switch(lmainOptions->getOrder())
            {
                case 1:
                {

                    auto lROADoverDecodingOptions = (ROADoverDecodingOptionsFirstOrderVersion*)(lmainOptions);

                    if(lROADoverDecodingOptions == nullptr)
                        throw std::exception();

                    switch(ROADConvertor::getByteLength(lmainOptions->getBitsPerSampleCode()))
                    {
                    case 2:
                    case 1:
                        _manager.reset(new ROADoverManagerFirstOrderVersionTempROADInt32(this,
                                                                                         lROADoverDecodingOptions,
                                                                                         aLowFormatEndianType));
                        break;

                    default:

                        throw std::exception();
                    }


//                    _manager.reset(new ROADoverManagerFirstOrderVersion(this, lROADoverDecodingOptions));
                }

                break;
            }
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
