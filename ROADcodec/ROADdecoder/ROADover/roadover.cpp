#include "ROADover.h"
#include "IROADoverDecodingOptions.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "ROADoverManagerExperemental.h"
#include "ROADoverManagerFirstOrderVersion.h"
#include "IROADoverDecodingOptionsMainVersion.h"
#include "ROADoverManagerFirstOrderVersionTempROADInt32.h"
#include "ROADRawDataFormat.h"
#include "ROADoverManagerFirstOrder.h"


ROADdecoder::ROADover::ROADover::ROADover(ROADdecoder::ROADover::IROADoverDecodingOptions* aOptions,
                                          Endian::EndianType aLowFormatEndianType)
{
    class ROADoverException : public std::exception
    {
    private: std::string _message;

    public:
      ROADoverException(const char* aMessage) _GLIBCXX_USE_NOEXCEPT:_message(aMessage) { }

      // This declaration is not useless:
      // http://gcc.gnu.org/onlinedocs/gcc-3.0.2/gcc_6.html#SEC118
      virtual ~ROADoverException() _GLIBCXX_USE_NOEXCEPT{}

      // See comment in eh_exception.cc.
      virtual const char* what() const _GLIBCXX_USE_NOEXCEPT
      {
          return _message.c_str();
      }
    };

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
                        throw ROADoverException("Format is not First Order.");

                    switch(ROADConvertor::getByteLength(lmainOptions->getBitsPerSampleCode()))
                    {
                    case 1:
                    case 2:
                    case 3:
                        switch (lmainOptions->getBitsPerSampleCode())
                        {
                        case ROADRawDataFormat::S16:
                            _manager.reset(new ROADoverManagerFirstOrder<ROADRawDataFormat::S16, ROADInt32>(this,
                                                                                                            lROADoverDecodingOptions,
                                                                                                            aLowFormatEndianType));

                            break;
                        default:
                            throw ROADoverException("Bits per sample is not supported in First Order.");
                            break;
                        }
                        break;

                    default:
                        throw ROADoverException("Decoding of such ROADRawDataFormat is not supported by First Order.");
                    }

                }

            default:

                throw ROADoverException("Format is not recognized.");

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
