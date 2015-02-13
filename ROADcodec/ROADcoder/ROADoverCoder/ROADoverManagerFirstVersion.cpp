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

            double *lptrData = _channelsDataBuffer.getIDoubleDataContainer(lindexChannel)->getData();

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



        unsigned int llength = this->_superFrameSamplesLength * this->_options->getAmountOfChannels() * (this->_options->getBitsPerSample() >> 3);



        std::unique_ptr<unsigned char> lpackDomainsBuffer(new unsigned char[llength]);

        unsigned char* lpackDomainsBufferData = lpackDomainsBuffer.get();

        unsigned int lpackDomainsBufferLength = 0;



        std::unique_ptr<unsigned char> lpackScalesBuffer(new unsigned char[llength]);

        unsigned char* lpackScalesBufferData = lpackScalesBuffer.get();

        unsigned int lpackScalesBufferLength = 0;

        // Обработка буфера ROADdata для записи индексов.


        unsigned char* lptrbufferROADdata = this->_bufferROADdata.get();

        unsigned int lbufferROADdataLength = 0;


        for(decltype(_options->getAmountOfChannels()) lChannel = 0;
            lChannel < _options->getAmountOfChannels();
            ++lChannel)
        {

            FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

            for( decltype(_options->getSuperFrameLength()) lframeIndex = 0;
                 lframeIndex < _options->getSuperFrameLength();
                 ++lframeIndex)
            {

                auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFractalItemContainer(lframeIndex);

                unsigned char lindekcestemp = 0;

                unsigned char ldomainIndex = 0;

                double ltempScale = 0.0;

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

                        unsigned int ldomainOffset = lptrFractalFirstOrderItem->getDomainOffset();

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

                        unsigned char lScale = static_cast<unsigned char> (ltempScale * 255.0);

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


        std::unique_ptr<double> ldoubleBuffer(new double[_options->getSuperFrameLength() * _options->getFrameSampleLength() * _options->getAmountOfChannels()]);

        unsigned int ldoubleBufferLength = 0;

        double* lptrDoubleData = ldoubleBuffer.get();

        FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(0);

        for( decltype(_options->getSuperFrameLength()) lframeIndex = 0;
             lframeIndex < _options->getSuperFrameLength();
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

                unsigned int lLength = lptrFractalAverItem->getLength();

                for(unsigned int lpos = 0;
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

            for( decltype(_options->getSuperFrameLength()) lframeIndex = 0;
                 lframeIndex < _options->getSuperFrameLength();
                 ++lframeIndex)
            {
                auto lptrFractalItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFractalItemContainer(lframeIndex);

                for(decltype(lptrFractalItemContainer->getFractalAverItemCount()) lItemIndex = 0;
                    lItemIndex < lptrFractalItemContainer->getFractalAverItemCount();
                    ++lItemIndex)
                {
                    auto lptrFractalAverItem = lptrFractalItemContainer->getFractalAverItem(lItemIndex);

                    double laver = lptrFractalAverItem->getAver();


                    *lptrDoubleData = laver;

                    ++lptrDoubleData;

                    ++ldoubleBufferLength;

                }

            }

        }


        unsigned int lConvertLength = this->_roadOver->convertDoubleArrayIntoByteArray(ldoubleBuffer.get(), ldoubleBufferLength, lptrbufferROADdata);

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

std::tuple<unsigned char *, unsigned int> ROADcoder::ROADoverCoder::ROADoverManagerFirstVersion::getFractalFormatRawData()
{
    std::tuple<unsigned char *, unsigned int> result(this->_fractalFormatRawDataContainer->getData(),
                                          this->_fractalFormatRawDataContainer->getLength());
    return result;
}

ROADcoder::ROADoverCoder::ROADoverManagerFirstVersion::ROADoverManagerFirstVersion(ROADcoder::ROADoverCoder::ROADover* aRoadOver, ROADcoder::ROADoverCoder::ROADoverEncodingOptionsFirstVersion* aOptions)
    : ROADoverManager(aRoadOver, aOptions->getAmountOfChannels(), aOptions->getSuperFrameLength(), 0, aOptions->getFrameSampleLength() * aOptions->getSuperFrameLength()),
      _options(aOptions)
{
    this->_bitsPerSample = aOptions->getBitsPerSampleCode();

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

    unsigned int lMaxFrameRangLength = _options->getFrameSampleLength();

    auto lcountOfChannels = _options->getAmountOfChannels();

    while(lcountOfChannels > 0)
    {

        _fractalItemSuperFrameContainer.push_back(new FractalFirstOrderItemSuperFrameContainer(_options->getSuperFrameLength(),
                                                                                               lMaxFrameRangLength));

        --lcountOfChannels;
    }

    std::unique_ptr<FractalEncodingOptions> loptions(new FractalEncodingOptions(_options->getFrameSampleLength(),
                                                                                4 << _options->getPowerRangSampleLength(),
                                                                                _options->getAmountRangLevels(),
                                                                                _options->getDomainShift(),
                                                                                _options->getSilenceThreshold(),
                                                                                _options->getRangThreshold()
                                                                                ));



    auto lptrRawData = this->_options->getFractalFormatRawDataContainer();

    _fractalFormatRawDataContainer.reset(lptrRawData.release());

    class CreateAnalyzerException: public exception
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

    unsigned int llength = this->_superFrameSamplesLength * this->_options->getAmountOfChannels() * (this->_options->getBitsPerSample() >> 3);

    _bufferROADdata.reset(new unsigned char[llength]);
}

ROADcoder::ROADoverCoder::ROADoverManagerFirstVersion::~ROADoverManagerFirstVersion()
{
    for(auto item: this->_fractalItemSuperFrameContainer)
    {
        delete item;
    }
}
