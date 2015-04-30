#include "ROADoverManagerExperemental.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "../ROAD/ROADFractalFirstOrderBuilderFactory.h"
#include "../ROAD/ROADFractalOrderFactory.h"
#include "MIDChannelsMixing.h"
#include "SIDEChannelsMixing.h"
#include "ROADRawDataFormat.h"


ROADdecoder::ROADover::ROADoverManagerExperemental::ROADoverManagerExperemental(ROADdecoder::ROADover::ROADover* aRoadOver,
                                                                                ROADdecoder::ROADover::ROADoverDecodingOptionsExperemental* aOptions)
    :ROADoverManager(aRoadOver,
                     aOptions->getAmountOfChannels(),
                     4,
                     aOptions->getSuperframeLength(),
                     aOptions->getFrameRangLength(),
                     aOptions->getSamplesPerRang() *
                     aOptions->getFrameRangLength() *
                     aOptions->getSuperframeLength()),
      _options(aOptions),
      _preListeningData(new ROADByte[4 * aOptions->getSamplesPerRang() *
                        aOptions->getFrameRangLength() *
                        aOptions->getSuperframeLength()]),
      _preListeningDoubleData(new ROADReal[aOptions->getSamplesPerRang() *
                                        aOptions->getFrameRangLength() *
                                        aOptions->getSuperframeLength()])
{
    switch(this->_options->getChannelsMixingMode())
    {
    case MID:
        this->_channelsMixing.reset(new MIDChannelsMixing<ROADReal>());
    break;
    case SIDE:
        this->_channelsMixing.reset(new SIDEChannelsMixing<ROADReal>());
    break;
    case NONE:
    default:
    break;
    }

    using namespace ROADdecoder::ROAD;


    std::unique_ptr<IROADFractalBuilderFactory> lptrIROADFractalBuilderFactory(ROADdecoder::ROAD::ROADFractalOrderFactory::getIROADFractalBuilderFactory(1));

    if(!lptrIROADFractalBuilderFactory || lptrIROADFractalBuilderFactory->getOrder() != 1)
    {
        throw "Format Experemental is not supported!!!";
    }

    std::unique_ptr<ROADFractalFirstOrderBuilderFactory> lptrROADFractalFirstOrderBuilderFactory(dynamic_cast<ROADFractalFirstOrderBuilderFactory*>(lptrIROADFractalBuilderFactory.release()));

    if(!lptrROADFractalFirstOrderBuilderFactory)
    {
        throw "Format Experemental is not supported!!!";
    }



    this->_frequencyScale = _options->getSamplesPerRang() / _options->getOriginalMinSamplesPerRang();

    _fractalBuilder.reset(lptrROADFractalFirstOrderBuilderFactory->getIROADFractalFirstOrderBuilder(ROADRawDataFormat::D64,
                                                                                                    _options->getSamplesPerRang() * _options->getFrameRangLength(), 4));

    for(decltype(aOptions->getAmountOfChannels()) index = 0;
        index < aOptions->getAmountOfChannels();
        ++index)
    {
        auto lContainer = new ROADFractalFirstOrderItemsSuperFrameDataContainer<ROADReal>(aOptions->getSuperframeLength(),
                                                                                          aOptions->getFrameRangLength(),
                                                                                          aOptions->getSamplesPerRang());

        _fractalItemSuperFrameContainer.push_back(lContainer);
    }
}

ROADdecoder::ROADover::Result ROADdecoder::ROADover::ROADoverManagerExperemental::decode() {
    Result result = Result::ERROR;

    this->_roadOver->lockResource();

    auto lreadROADdataLength = this->_roadOver->readROADdata(this->_bufferROADdata.get());

    switch(lreadROADdataLength)
    {
    case -1:

        result = Result::FINISHFILE;

        break;

    default:

        result = Result::DONE;

        {
            ROADUInt32 lFrameLengthLength = _options->getFrameRangLength() * _options->getSamplesPerRang();

            do
            {
                auto lreadPreListeningLength = this->_roadOver->readPreListening(_preListeningData.get(), 0);

                this->_roadOver->convertByteArrayIntoDoubleArray(_preListeningData.get(), lreadPreListeningLength, _preListeningDoubleData.get());


// Обработка буфера ROADdata для выделения длинн рангов.


                auto lptrData = this->_bufferROADdata.get();


                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {

                    auto lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                         lframeIndex < _options->getSuperframeLength();
                         ++lframeIndex)
                    {

                         ROADUInt32 lFractalAverItemCount = 0;

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFrameDataContainer(lframeIndex);

                        lptrFractalFirstOrderItemContainer->resetFractalFirstOrderItemCount();


                        auto lLength = lFrameLengthLength;

                        ROADUInt8 luctemp = 0;

                        ROADUInt32 lcurrentPosition = 0;

                        while(lLength > 0)
                        {
                            luctemp = *lptrData;

                            ++lptrData;

                            --lreadROADdataLength;

                             ROADUInt32 lrangeLength;

                            auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(lFractalAverItemCount);

                            if((luctemp & 128) == 128)
                            {
                                lrangeLength = (1 << (luctemp & 127)) * _options->getSamplesPerRang();
                            }
                            else
                            {
                                lrangeLength = (1 << (luctemp >> 5)) * _options->getSamplesPerRang();
                            }

                            lptrFractalAverItem->setIndexInfo(lcurrentPosition,
                                                              lrangeLength,
                                                              luctemp);

                            lLength -= lrangeLength;

                            lcurrentPosition+=lrangeLength;

                            ++lFractalAverItemCount;
                        }

                        lptrFractalFirstOrderItemContainer->setFractalFirstOrderItemCount(lFractalAverItemCount);

                    }
                }

// Обработка буфера предпрослушивания

                ROADReal *lptrPreListeningDoubleData = _preListeningDoubleData.get();

                auto lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(0);

                for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                     lframeIndex < _options->getSuperframeLength();
                     ++lframeIndex)
                {


                    auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFrameDataContainer(lframeIndex);

                    auto lFractalAverItemCount = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemCount();


                    ROADUInt32 count = 0;

                    ROADUInt32 lrabgeLength = 0;

                    while(count < lFractalAverItemCount)
                    {
                        ROADReal lptrAver = *lptrPreListeningDoubleData;

                        auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(count);

                        lrabgeLength = lptrFractalAverItem->getLength();

                        lptrFractalAverItem->setAverage(&lptrAver);

                        lrabgeLength /= _options->getSamplesPerRang();

                        lptrPreListeningDoubleData += lrabgeLength;

                        ++count;
                    }

                }

                if(lreadROADdataLength <= 0)
                    break;

// Обработка буфера ROADdata для выделения усреднённой составляющей.

                for(decltype(_options->getAmountOfChannels()) lChannel = 1;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    auto lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                         lframeIndex < _options->getSuperframeLength();
                         ++lframeIndex)
                    {

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFrameDataContainer(lframeIndex);

                        auto lFractalAverItemCount = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemCount();

                        ROADUInt32 lLengthByteArray = lFractalAverItemCount * (_options->getOriginalBitsPerSample() >> 3);

                        std::unique_ptr<double> lptrAver(new ROADReal[lFractalAverItemCount]);



                        this->_roadOver->convertByteArrayIntoDoubleArray(lptrData, lLengthByteArray, lptrAver.get());

                        lptrData+=lLengthByteArray;

                        for(decltype(lFractalAverItemCount) lItemIndex = 0;
                            lItemIndex < lFractalAverItemCount;
                            ++lItemIndex)
                        {

                            auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(lItemIndex);

                            lptrFractalAverItem->setAverage(lptrAver.get()+ lItemIndex);

                        }
                    }
                }
// Обработка буфера ROADdata для выделения номеров доменнов.


                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    auto lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                         lframeIndex < _options->getSuperframeLength();
                         ++lframeIndex)
                    {

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFrameDataContainer(lframeIndex);

                        auto lFractalAverItemCount = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemCount();


                        ROADUInt8 ldomainIndex;

                        decltype(lFractalAverItemCount) itemCount = 0;

                        ROADUInt32 countDomainIndeces = 0;

                        while(itemCount < lFractalAverItemCount)
                        {
                            auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(itemCount);

                            ROADUInt8 itemIndex = lptrFractalAverItem->getFractalItemIndex();


                            if((itemIndex & 128) == 0)
                            {

                                ldomainIndex = *lptrData;

                                ++lptrData;


                                 ROADUInt32 lDomainOffset = (itemIndex & 7) << 8;

                                lDomainOffset |= ldomainIndex;

                                lDomainOffset = lDomainOffset * this->_frequencyScale;


                                ROADReal lScale = 1.0;

                                if((itemIndex & 8) == 8)
                                    lScale = -lScale;

                                lptrFractalAverItem->setRangTransform((itemIndex & 16) == 16, lDomainOffset, lScale);

                                ++countDomainIndeces;
                            }
                            else
                                lptrFractalAverItem->setRangTransform(false, 0, 0.0);


                            ++itemCount;
                        }

                    }

                }


//  Обработка буфера ROADdata для выделения коэфициентов масштабирования.

                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    auto lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                         lframeIndex < _options->getSuperframeLength();
                         ++lframeIndex)
                    {
                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFrameDataContainer(lframeIndex);

                        auto lFractalItemCount = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemCount();

                        decltype(lFractalItemCount) itemCount = 0;

                        while(itemCount < lFractalItemCount)
                        {
                            auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(itemCount);

                            ROADUInt8 itemIndex = lptrFractalAverItem->getFractalItemIndex();


                            if((itemIndex & 128) == 0)
                            {

                            ROADUInt8 ldecimScale = *lptrData;

                            ++lptrData;

                            ROADReal lScale = static_cast<ROADReal> (ldecimScale);// / 255.0;

                            lptrFractalAverItem->setScale(lptrFractalAverItem->getScale() * lScale);

                            }


                            ++itemCount;
                        }
                    }

                }

            }
            while(false);

// Выполнение постороения фракталов для декодирования
            {
                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    auto lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    ROADReal* lptrDoubleData = _channelsDataBuffer.getPtrDecodedDataContainer(lChannel)->getData();

                    for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                         lframeIndex < _options->getSuperframeLength();
                         ++lframeIndex)
                    {
                        _fractalBuilder->build(lptrDoubleData + (lframeIndex * lFrameLengthLength),
                                                       lptrFractalFirstOrderItemsSuperFrameContainer->getFrameDataContainer(lframeIndex));
                    }
                }

                this->_channelsMixing->compute(&_channelsDataBuffer);

                this->_roadOver->writeRawData(&_channelsDataBuffer);

            }
        }

        break;
    }

    this->_roadOver->unlockResource();

    return result;
}

ROADdecoder::ROADover::ROADoverManagerExperemental::~ROADoverManagerExperemental()
{
    for(auto item : _fractalItemSuperFrameContainer)
        delete item;

    _fractalItemSuperFrameContainer.clear();

    delete _options;
}
