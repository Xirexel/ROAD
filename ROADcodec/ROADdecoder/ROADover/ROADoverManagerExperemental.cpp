#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverManagerExperemental.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "../ROAD/ROADFractalFirstOrderBuilderFactory.h"
#include "../ROAD/ROADFractalOrderFactory.h"
#include "FractalFirstOrderItem.h"
#include "FractalAverItem.h"
#include "FractalFirstOrderItemContainer.h"
#include "FractalFirstOrderItemSuperFrameContainer.h"
#include "IDoubleDataContainer.h"
#include "MIDChannelsMixing.h"
#include "SIDEChannelsMixing.h"

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
      _preListeningData(new unsigned char[4 * aOptions->getSamplesPerRang() *
                        aOptions->getFrameRangLength() *
                        aOptions->getSuperframeLength()]),
      _preListeningDoubleData(new double[aOptions->getSamplesPerRang() *
                                        aOptions->getFrameRangLength() *
                                        aOptions->getSuperframeLength()])
{
    switch(this->_options->getChannelsMixingMode())
    {
    case MID:
        this->_channelsMixing.reset(new MIDChannelsMixing);
    break;
    case SIDE:
        this->_channelsMixing.reset(new SIDEChannelsMixing);
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

    _fractalBuilder.reset(lptrROADFractalFirstOrderBuilderFactory->getIROADFractalFirstOrderBuilder(0, _superFrameSamplesLength));

    this->_frequencyScale = _options->getSamplesPerRang() / _options->getOriginalSamplesPerRang();

    for(decltype(aOptions->getAmountOfChannels()) index = 0;
        index < aOptions->getAmountOfChannels();
        ++index)
    {
        _fractalItemSuperFrameContainer.push_back(new FractalFirstOrderItemSuperFrameContainer(aOptions->getSuperframeLength(), aOptions->getFrameRangLength()));
    }
}

ROADdecoder::ROADover::Result ROADdecoder::ROADover::ROADoverManagerExperemental::decode() {
    Result result = Result::ERROR;

    this->_roadOver->lockResource();

    int lreadROADdataLength = this->_roadOver->readROADdata(this->_bufferROADdata.get());

    switch(lreadROADdataLength)
    {
    case -1:

        result = Result::FINISHFILE;

        break;

    default:

        result = Result::DONE;

        {
            unsigned int lFrameLengthLength = _options->getFrameRangLength() * _options->getSamplesPerRang();

            do
            {
                int lreadPreListeningLength = this->_roadOver->readPreListening(_preListeningData.get());

                this->_roadOver->convertByteArrayIntoDoubleArray(_preListeningData.get(), lreadPreListeningLength, _preListeningDoubleData.get());


// Обработка буфера ROADdata для выделения длинн рангов.


                const unsigned char* lptrData = this->_bufferROADdata.get();


                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {

                    FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                         lframeIndex < _options->getSuperframeLength();
                         ++lframeIndex)
                    {

                        unsigned int lFractalAverItemCount = 0;

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                        int lLength = lFrameLengthLength;

                        unsigned char luctemp = 0;

                        unsigned int lcurrentPosition = 0;

                        while(lLength > 0)
                        {
                            luctemp = *lptrData;

                            ++lptrData;

                            --lreadROADdataLength;

                            unsigned int lrangeLength;

                            auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalAverItem(lFractalAverItemCount);

                            if((luctemp & 128) == 128)
                            {
                                lrangeLength = (1 << (luctemp & 127)) * _options->getSamplesPerRang();
                            }
                            else
                            {
                                lrangeLength = (1 << (luctemp >> 5)) * _options->getSamplesPerRang();
                            }

                            lptrFractalAverItem->setLength(lrangeLength);

                            lptrFractalAverItem->setFractalItemIndex(luctemp);

                            lptrFractalAverItem->setPosition(lcurrentPosition);

                            lLength -= lrangeLength;

                            lcurrentPosition+=lrangeLength;

                            ++lFractalAverItemCount;
                        }

                        lptrFractalFirstOrderItemContainer->setFractalAverItemCount(lFractalAverItemCount);

                    }
                }

// Обработка буфера предпрослушивания

                double *lptrPreListeningDoubleData = _preListeningDoubleData.get();

                FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(0);

                for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                     lframeIndex < _options->getSuperframeLength();
                     ++lframeIndex)
                {


                    FractalFirstOrderItemContainer *lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                    auto lFractalAverItemCount = lptrFractalFirstOrderItemContainer->getIFractalAverItemCount();


                    unsigned int count = 0;

                    unsigned int lrabgeLength = 0;

                    while(count < lFractalAverItemCount)
                    {
                        double lptrAver = *lptrPreListeningDoubleData;

                        FractalAverItem *lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalAverItem(count);

                        lrabgeLength = lptrFractalAverItem->getLength();

                        lptrFractalAverItem->setAver(lptrAver);

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
                    FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                         lframeIndex < _options->getSuperframeLength();
                         ++lframeIndex)
                    {

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                        auto lFractalAverItemCount = lptrFractalFirstOrderItemContainer->getIFractalAverItemCount();

                        unsigned int lLengthByteArray = lFractalAverItemCount * (_options->getOriginalBitsPerSample() >> 3);

                        unique_ptr<double> lptrAver(new double[lFractalAverItemCount]);



                        this->_roadOver->convertByteArrayIntoDoubleArray(lptrData, lLengthByteArray, lptrAver.get());

                        lptrData+=lLengthByteArray;

                        for(decltype(lFractalAverItemCount) lItemIndex = 0;
                            lItemIndex < lFractalAverItemCount;
                            ++lItemIndex)
                        {

                            auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalAverItem(lItemIndex);

                            lptrFractalAverItem->setAver(lptrAver.get()[lItemIndex]);

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

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                        auto lFractalAverItemCount = lptrFractalFirstOrderItemContainer->getIFractalAverItemCount();


                        unsigned char ldomainIndex;

                        decltype(lFractalAverItemCount) itemCount = 0;

                        unsigned int countDomainIndeces = 0;

                        while(itemCount < lFractalAverItemCount)
                        {
                            auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalAverItem(itemCount);

                            unsigned char itemIndex = lptrFractalAverItem->getFractalItemIndex();


                            if((itemIndex & 128) == 0)
                            {

                                ldomainIndex = *lptrData;

                                ++lptrData;


                                unsigned int lDomainOffset = (itemIndex & 7) << 8;

                                lDomainOffset |= ldomainIndex;

                                lDomainOffset = lDomainOffset * this->_frequencyScale;


                                auto lptrFractalFirstOrderItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItem(countDomainIndeces);

                                lptrFractalFirstOrderItem->setAver(lptrFractalAverItem->getAver());

                                lptrFractalFirstOrderItem->setDomainOffset(lDomainOffset);

                                lptrFractalFirstOrderItem->setInversDirection((itemIndex & 16) == 16);

                                lptrFractalFirstOrderItem->setLength(lptrFractalAverItem->getLength());

                                lptrFractalFirstOrderItem->setPosition(lptrFractalAverItem->getPosition());

                                double lScale = 1.0;

                                if((itemIndex & 8) == 8)
                                    lScale = -lScale;

                                lptrFractalFirstOrderItem->setScale(lScale);

                                ++countDomainIndeces;
                            }

                            ++itemCount;
                        }

                        lptrFractalFirstOrderItemContainer->setFractalFirstOrderItemCount(countDomainIndeces);

                    }

                }


//  Обработка буфера ROADdata для выделения коэфициентов масштабирования.

                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                         lframeIndex < _options->getSuperframeLength();
                         ++lframeIndex)
                    {
                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                        auto lFractalItemCount = lptrFractalFirstOrderItemContainer->getIFractalFirstOrderItemCount();

                        decltype(lFractalItemCount) itemCount = 0;

                        while(itemCount < lFractalItemCount)
                        {
                            auto lptrFractalFirstOrderItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItem(itemCount);

                            unsigned char ldecimScale = *lptrData;

                            ++lptrData;

                            double lScale = static_cast<double> (ldecimScale) / 255.0;

                            lptrFractalFirstOrderItem->setScale(lptrFractalFirstOrderItem->getScale() * lScale);

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

                    FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    double* lptrDoubleData = _channelsDataBuffer.getIDoubleDataContainer(lChannel)->getData();

                    for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                         lframeIndex < _options->getSuperframeLength();
                         ++lframeIndex)
                    {
                        _fractalBuilder->build(lptrDoubleData + (lframeIndex * lFrameLengthLength),
                                                       lptrFractalFirstOrderItemsSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex));
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
    for(FractalFirstOrderItemSuperFrameContainer* item : _fractalItemSuperFrameContainer)
        delete item;

    _fractalItemSuperFrameContainer.clear();

    delete _options;
}