#include "ROADoverManagerFirstVersion.h"
#include "IDoubleDataContainer.h"
#include "FractalFirstOrderItemContainer.h"
#include "ROADFractalFirstOrderAnalyzerFactory.h"
#include "IROADFractalFirstOrderAnalyzer.h"
#include "FractalAverItem.h"
#include "FractalFirstOrderItem.h"
#include "ROADover.h"
#include "MIDChannelsMixing.h"
#include "SIDEChannelsMixing.h"
#include "NoneChannelsMixing.h"
#include "FractalEncodingOptions.h"
#include "DataDriver.h"
#include "ByteConvertor.h"
#include "DecodedSampleTypeToRawDataSampleType.h"
#include "ROADoverCoderCommon.h"


ROADcoder::ROADoverCoder::Result ROADcoder::ROADoverCoder::ROADoverManagerFirstVersion::encode() {

    ROADcoder::ROADoverCoder::Result lresult = ROADcoder::ROADoverCoder::ERROR;

    do
    {
        lresult = this->_roadOver->readRawData(_channelsDataBuffer);

        if(lresult != ROADcoder::ROADoverCoder::DONE)
            break;

        _channelsMixing->compute(&_channelsDataBuffer);

        auto lchannelCount = _channelsDataBuffer.getCount();

        auto lframeSampleLength = this->_options->getFrameSampleLength();


        for(decltype(lchannelCount) lindexChannel = 0;
            lindexChannel < lchannelCount;
            ++lindexChannel)
        {

            PtrROADReal lptrData = _channelsDataBuffer.getIDoubleDataContainer(lindexChannel)->getData();

            auto lptrItemContainer = _fractalItemSuperFrameContainer.at(lindexChannel);

            auto lframeCount = lptrItemContainer->getCount();

            for(decltype(lframeCount) lframeIndex = 0;
                lframeIndex < lframeCount;
                ++lframeIndex)
            {
                auto lptrFractalItemContainer = lptrItemContainer->getFractalItemContainer(lframeIndex);

                lptrFractalItemContainer->resetCounts();

                _analyzer->analyze(lptrData + lframeSampleLength * lframeIndex,
                                   lptrFractalItemContainer);
            }

        }



        auto llength = this->_superFrameSamplesLength * this->_options->getAmountOfChannels() * (ROADConvertor::getByteLength(this->_options->getBitsPerSampleCode()));

        ROADUInt8 lEndingCode = this->_options->getEndianType();

        // Pointer on Common buffer.

        auto lIDataWriteDriver = ROADcoder::Driver::DataDriver::getIDataWriteDriver(this->_bufferROADdata,
                                                          llength,
                                                          Endian::EndianType(lEndingCode));



        std::unique_ptr<ROADByte> lpackDomainsBuffer(new ROADByte[llength]);

        PtrROADByte lpackDomainsBufferData = lpackDomainsBuffer.get();

        ROADUInt64 lpackDomainsBufferLength = 0;


        // Buffer of Scales data.

        std::unique_ptr<ROADInt8> lpackScalesBuffer(new ROADInt8[llength]);

        PtrROADInt8 lpackScalesBufferData = lpackScalesBuffer.get();

        ROADUInt64 lpackScalesBufferLength = 0;

        // Обработка буфера ROADdata для записи индексов.

        std::unique_ptr<ROADByte> lpackIndekcesBuffer(new ROADByte[llength]);

        PtrROADByte lpackIndekcesBufferData = lpackIndekcesBuffer.get();

        ROADUInt64 lpackIndekcesBufferLength = 0;



        for(decltype(_options->getAmountOfChannels()) lChannel = 0;
            lChannel < _options->getAmountOfChannels();
            ++lChannel)
        {

            FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

            for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                 lframeIndex < _options->getMaxSuperFrameLength();
                 ++lframeIndex)
            {

                auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFractalItemContainer(lframeIndex);

                ROADByte lindekcestemp = 0;

                ROADByte ldomainIndex = 0;

                ROADReal ltempScale = 0.0;

                auto lfractalAverItemCount = lptrFractalFirstOrderItemContainer->getFractalAverItemCount();

                auto lfractalFirstOrderItemCount = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemCount();

                decltype(lfractalAverItemCount) lCountFractalItems = 0;

                decltype(lfractalFirstOrderItemCount) lCountFractalFirstOrderItem = 0;

                while(lCountFractalItems < lfractalAverItemCount)
                {
                    auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalAverItem(lCountFractalItems);

                    lindekcestemp = lptrFractalAverItem->getIndex();

                    if((lindekcestemp & 128) == 0)
                    {
                        // Обработка буфера ROADdata для записи номеров доменнов.

                        auto lptrFractalFirstOrderItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItem(lCountFractalFirstOrderItem);

                        ROADUInt32 ldomainOffset = lptrFractalFirstOrderItem->getDomainOffset();

                        ldomainIndex = ldomainOffset & 255;

                        *lpackDomainsBufferData = ldomainIndex;

                        lindekcestemp <<= 5;

                        lindekcestemp |= ldomainOffset >> 8;

                        if(lptrFractalFirstOrderItem->isIsInversDirection())
                            lindekcestemp |= 16;

                        ltempScale = lptrFractalFirstOrderItem->getScale();

                        ROADInt8 lScale = (ROADInt8)(ltempScale * 128.0);

                        *lpackScalesBufferData = lScale;


                        ++lCountFractalFirstOrderItem;


                        ++lpackDomainsBufferData;

                        ++lpackDomainsBufferLength;


                        ++lpackScalesBufferData;

                        ++lpackScalesBufferLength;
                    }

                    *lpackIndekcesBufferData = lindekcestemp;

                    ++lpackIndekcesBufferData;

                    ++lpackIndekcesBufferLength;

                    ++lCountFractalItems;

                }
            }
        }


        // Fill prelistening buffer.
        std::shared_ptr<ROADReal> ldoubleBuffer(new ROADReal[_options->getMaxSuperFrameLength() * _options->getFrameSampleLength() * _options->getAmountOfChannels()]);

        ROADUInt32 ldoubleBufferLength = 0;

        PtrROADReal lptrDoubleData = ldoubleBuffer.get();

        FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(0);

        for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
             lframeIndex < _options->getMaxSuperFrameLength();
             ++lframeIndex)
        {
            auto lptrFractalItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFractalItemContainer(lframeIndex);

            for(decltype(lptrFractalItemContainer->getFractalAverItemCount()) lItemIndex = 0;
                lItemIndex < lptrFractalItemContainer->getFractalAverItemCount();
                ++lItemIndex)
            {
                auto lptrFractalAverItem = lptrFractalItemContainer->getFractalAverItem(lItemIndex);

                double laver = lptrFractalAverItem->getAver();


                ROADUInt32 lLength = lptrFractalAverItem->getLength();

                for(ROADUInt32 lpos = 0;
                    lpos < lLength;
                    ++lpos)
                {
                    *lptrDoubleData = laver;

                    ++lptrDoubleData;

                    ++ldoubleBufferLength;
                }

            }

        }



        auto lCRC32PreListening = this->_roadOver->writePreListening(ldoubleBuffer.get(), ldoubleBufferLength);

        // Write Head and CRC data for prelistening.

        lIDataWriteDriver->operator
                << ((ROADUInt8)(lEndingCode + 1)) // Add the Head of prelistening stream - code '0x01'.
                << lCRC32PreListening;


        ldoubleBufferLength = 0;

        lptrDoubleData = ldoubleBuffer.get();

        // Reading Average Audio stream.

        for(decltype(_options->getAmountOfChannels()) lChannel = 1;
            lChannel < _options->getAmountOfChannels();
            ++lChannel)
        {

            FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

            for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                 lframeIndex < _options->getMaxSuperFrameLength();
                 ++lframeIndex)
            {
                auto lptrFractalItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFractalItemContainer(lframeIndex);

                for(decltype(lptrFractalItemContainer->getFractalAverItemCount()) lItemIndex = 0;
                    lItemIndex < lptrFractalItemContainer->getFractalAverItemCount();
                    ++lItemIndex)
                {
                    auto lptrFractalAverItem = lptrFractalItemContainer->getFractalAverItem(lItemIndex);

                    auto laver = lptrFractalAverItem->getAver();


                    *lptrDoubleData = laver;

                    ++lptrDoubleData;

                    ++ldoubleBufferLength;

                }

            }

        }



        //Writing the locals buffers into the common ROAD data buffer.


        // Writing indekces buffer        

        lIDataWriteDriver->operator
                << ((ROADUInt8)(lEndingCode + 2)) // Add the Head of Indekces stream - code '0x02'.
                << (lpackIndekcesBufferLength + 4)
                << std::make_tuple(lpackIndekcesBuffer.get(), lpackIndekcesBufferLength);

        lIDataWriteDriver->computeAndAppendCRC32(lpackIndekcesBufferLength + 9);


        ROADUInt64 lConvertLength = ldoubleBufferLength * ROADConvertor::getByteLength(_options->getBitsPerSampleCode());

        lIDataWriteDriver->operator
                << ((ROADUInt8)(lEndingCode + 3)) // Add the Head of Average Audio stream - code '0x03'.
                << (lConvertLength + 4);

        _convertor->writeRawData(lIDataWriteDriver.get(), ldoubleBuffer.get(), ldoubleBufferLength);

        lIDataWriteDriver->computeAndAppendCRC32(lConvertLength + 9);



        lIDataWriteDriver->operator
                << ((ROADUInt8)(lEndingCode + 4)) // Add the Head of Domain low byte and First Order Scale stream - code '0x04'.
                << (lpackDomainsBufferLength + lpackScalesBufferLength + 4)
                << std::make_tuple(lpackDomainsBuffer.get(), lpackDomainsBufferLength)
                << std::make_tuple((PtrROADByte)lpackScalesBuffer.get(), lpackScalesBufferLength);

        lIDataWriteDriver->computeAndAppendCRC32(lpackDomainsBufferLength + lpackScalesBufferLength + 9);


        this->_roadOver->writeROADdata(this->_bufferROADdata.get(), lIDataWriteDriver->getPosition());


    }while(false);

    return lresult;
}

std::tuple<PlatformDependencies::PtrROADByte, PlatformDependencies::ROADUInt32> ROADcoder::ROADoverCoder::ROADoverManagerFirstVersion::getFractalFormatRawData()
{
    auto lptrRawData = this->_options->getFractalFormatRawDataContainer();

    _fractalFormatRawDataContainer.reset(lptrRawData.release());

    std::tuple<PtrROADByte, ROADUInt32> result(this->_fractalFormatRawDataContainer->getData(),
                                          this->_fractalFormatRawDataContainer->getLength());
    return result;
}

ROADcoder::ROADoverCoder::ROADoverManagerFirstVersion::ROADoverManagerFirstVersion(ROADcoder::ROADoverCoder::ROADover* aRoadOver,
                                                                                   ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion* aOptions)
    : ROADoverManager(aRoadOver, aOptions->getAmountOfChannels(), aOptions->getMaxSuperFrameLength(), 0, aOptions->getFrameSampleLength() * aOptions->getMaxSuperFrameLength()),
      _options(aOptions)
{
    switch (aOptions->getBitsPerSampleCode())
    {
    case ROADRawDataFormat::S16:

        _convertor.reset(new DecodedSampleTypeToRawDataSampleType<SampleTypeCodeToSampleType<ROADcoder::ROADoverCoder::ROADRawDataFormat::S16>::DecodedSampleType>());

        break;
    default:

        throw std::exception();

        break;
    }

    this->_bitsPerSample = ROADConvertor::getBitLength(aOptions->getBitsPerSampleCode());

    this->_rangSampleLength = aOptions->getRangSampleLength();

    switch (_options->getMixingChannelsMode()) {
    case MID:
        _channelsMixing.reset(new MIDChannelsMixing());
        break;
    case SIDE:
        _channelsMixing.reset(new SIDEChannelsMixing());
        break;
    case NONE:
    default:
        _channelsMixing.reset(new NoneChannelsMixing());
        break;
    }

    ROADUInt32 lMaxFrameRangLength = _options->getFrameSampleLength() / _options->getRangSampleLength();

    auto lcountOfChannels = _options->getAmountOfChannels();

    while(lcountOfChannels > 0)
    {

        _fractalItemSuperFrameContainer.push_back(new FractalFirstOrderItemSuperFrameContainer(_options->getMaxSuperFrameLength(),
                                                                                               lMaxFrameRangLength));

        --lcountOfChannels;
    }

    std::unique_ptr<FractalEncodingOptions> loptions(new FractalEncodingOptions(_options->getFrameSampleLength(),
                                                                                _options->getRangSampleLength() << _options->getAmountRangLevels(),
                                                                                _options->getAmountRangLevels(),
                                                                                _options->getDomainShift(),
                                                                                _options->getSilenceThreshold(),
                                                                                _options->getRangThreshold()
                                                                                ));

    class CreateAnalyzerException: public std::exception
    {
    public:

        CreateAnalyzerException() _GLIBCXX_USE_NOEXCEPT
        {

        }

        virtual const char* what() const _GLIBCXX_USE_NOEXCEPT
        {
            return "Error of creating of fractal analyzer!!!";
        }

        ~CreateAnalyzerException() _GLIBCXX_USE_NOEXCEPT
        {

        }
    };

    _analyzer.reset(ROADcoder::ROADCoder::ROADFractalFirstOrderAnalyzerFactory::getIROADFractalFirstOrderAnalyzer(loptions.get() , 0));

    if(!_analyzer)
        throw CreateAnalyzerException();

    ROADUInt32 llength = this->_superFrameSamplesLength * this->_options->getAmountOfChannels() * (ROADConvertor::getByteLength(this->_options->getBitsPerSampleCode()));

    _bufferROADdata.reset(new ROADByte[llength]);
}

ROADcoder::ROADoverCoder::ROADoverManagerFirstVersion::~ROADoverManagerFirstVersion()
{
    for(auto item: this->_fractalItemSuperFrameContainer)
    {
        delete item;
    }
}
