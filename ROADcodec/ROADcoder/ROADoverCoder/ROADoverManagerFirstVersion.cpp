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



        std::unique_ptr<ROADByte> lpackDomainsBuffer(new ROADByte[llength]);

        PtrROADByte lpackDomainsBufferData = lpackDomainsBuffer.get();

        ROADUInt32 lpackDomainsBufferLength = 0;



        std::unique_ptr<ROADByte> lpackScalesBuffer(new ROADByte[llength]);

        PtrROADByte lpackScalesBufferData = lpackScalesBuffer.get();

        ROADUInt32 lpackScalesBufferLength = 0;

        // Обработка буфера ROADdata для записи индексов.


        PtrROADByte lptrbufferROADdata = this->_bufferROADdata.get();

        ROADUInt32 lbufferROADdataLength = 0;


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

                        if(ltempScale < 0.0)
                        {
                            lindekcestemp |= 8;

                            ltempScale = -ltempScale;
                        }

                        ROADByte lScale = static_cast<ROADByte> (ltempScale * 255.0);

                        *lpackScalesBufferData = lScale;


                        ++lCountFractalFirstOrderItem;


                        ++lpackDomainsBufferData;

                        ++lpackDomainsBufferLength;


                        ++lpackScalesBufferData;

                        ++lpackScalesBufferLength;
                    }

                    *lptrbufferROADdata = lindekcestemp;

                    ++lptrbufferROADdata;

                    ++lbufferROADdataLength;

                    ++lCountFractalItems;

                }
            }
        }


        std::unique_ptr<ROADReal> ldoubleBuffer(new ROADReal[_options->getMaxSuperFrameLength() * _options->getFrameSampleLength() * _options->getAmountOfChannels()]);

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

//                if(lframeIndex == (_options->getSuperFrameLength() - 1) && lItemIndex >= lptrFractalItemContainer->getFractalAverItemCount() - 3)
//                {
//                    std::cerr << laver << std::endl;

//                }

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

        this->_roadOver->writePreListening(ldoubleBuffer.get(), ldoubleBufferLength);

        ldoubleBufferLength = 0;

        lptrDoubleData = ldoubleBuffer.get();

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


        ROADUInt32 lConvertLength = this->_roadOver->convertDoubleArrayIntoByteArray(ldoubleBuffer.get(), ldoubleBufferLength, lptrbufferROADdata);

        lptrbufferROADdata += lConvertLength;

        lbufferROADdataLength += lConvertLength;



        memcpy(lptrbufferROADdata, lpackDomainsBuffer.get(), lbufferROADdataLength);

        lptrbufferROADdata += lpackDomainsBufferLength;

        lbufferROADdataLength += lpackDomainsBufferLength;





        memcpy(lptrbufferROADdata, lpackScalesBuffer.get(), lbufferROADdataLength);

        lptrbufferROADdata += lpackScalesBufferLength;

        lbufferROADdataLength += lpackScalesBufferLength;





        this->_roadOver->writeROADdata(this->_bufferROADdata.get(), lbufferROADdataLength);


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
        throw new CreateAnalyzerException;

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
