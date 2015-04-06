#include "ROADoverManagerFirstOrderVersion.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsFirstOrderVersion.h"
#include "../ROAD/ROADFractalFirstOrderBuilderFactory.h"
#include "../ROAD/ROADFractalOrderFactory.h"
#include "FractalFirstOrderItem.h"
#include "FractalAverItem.h"
#include "FractalFirstOrderItemContainer.h"
#include "FractalFirstOrderItemSuperFrameContainer.h"
#include "IDoubleDataContainer.h"
#include "MIDChannelsMixing.h"
#include "SIDEChannelsMixing.h"
#include "DataDriver.h"

ROADdecoder::ROADover::ROADoverManagerFirstOrderVersion::ROADoverManagerFirstOrderVersion(ROADdecoder::ROADover::ROADover* aRoadOver,
                                                                                          ROADdecoder::ROADover::ROADoverDecodingOptionsFirstOrderVersion* aOptions)
    :ROADoverManager(aRoadOver,
                     aOptions->getAmountOfChannels(),
                     ROADConvertor::getByteLength(aOptions->getBitsPerSampleCode()),
                     aOptions->getMaxSuperFrameLength(),
                     aOptions->getFrameSampleLength(),
                     aOptions->getFrameSampleLength() *
                     aOptions->getMaxSuperFrameLength()),
      _options(aOptions),
      _preListeningData(new ROADByte[
                        ROADConvertor::getByteLength(aOptions->getBitsPerSampleCode()) *
                        aOptions->getMaxFrameRangLength() *
                        aOptions->getMaxSuperFrameLength()]),
      _preListeningDoubleData(new ROADReal[
                              aOptions->getMinSamplesPerRang() *
                              aOptions->getMaxFrameRangLength() *
                              aOptions->getMaxSuperFrameLength()])
{
    switch(this->_options->getMixingChannelsMode())
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

    this->_frequencyScale = _options->getMinSamplesPerRang() / _options->getOriginalMinSamplesPerRang();

    for(decltype(aOptions->getAmountOfChannels()) index = 0;
        index < aOptions->getAmountOfChannels();
        ++index)
    {
        _fractalItemSuperFrameContainer.push_back(new FractalFirstOrderItemSuperFrameContainer(aOptions->getMaxSuperFrameLength(), aOptions->getMaxFrameRangLength()));
    }
}

ROADdecoder::ROADover::Result ROADdecoder::ROADover::ROADoverManagerFirstOrderVersion::decode() {
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
            ROADUInt32 lFrameLengthLength = _options->getMaxFrameRangLength() * _options->getMinSamplesPerRang();

            do
            {
                auto lreadPreListeningLength = this->_roadOver->readPreListening(_preListeningData.get());

                this->_roadOver->convertByteArrayIntoDoubleArray(_preListeningData.get(), lreadPreListeningLength, _preListeningDoubleData.get());


// Обработка буфера ROADdata для выделения длинн рангов.


//                auto lptrData = this->_bufferROADdata.get();


                ROADUInt8 lEndingCode = this->_options->getEndianType();

                // Pointer on Common buffer.

        //        PtrROADByte lptrbufferROADdata = this->_bufferROADdata.get();

                auto lIDataReadDriver = ROADdecoder::Driver::DataDriver::getIDataReadDriver(this->_bufferROADdata,
                                                                  lreadROADdataLength,
                                                                  Endian::EndianType(lEndingCode));

                ROADUInt8 lHead = 0;

                ROADBool lOk = false;

                lIDataReadDriver->operator >>(lHead);

                ROADUInt64 lLength;

                lIDataReadDriver->operator >>(lLength);

                lIDataReadDriver->seek(-9);

                lIDataReadDriver->computeAndCheckCRC32(lLength - 4 + 9, lOk);

                lIDataReadDriver->seek(9);


                if(lIDataReadDriver)

                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {

                    FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                         lframeIndex < _options->getMaxSuperFrameLength();
                         ++lframeIndex)
                    {

                         ROADUInt32 lFractalAverItemCount = 0;

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                        auto lLength = lFrameLengthLength;

                        ROADUInt8 luctemp = 0;

                        ROADUInt32 lcurrentPosition = 0;

                        while(lLength > 0)
                        {

                            lIDataReadDriver->operator >>(luctemp);

//                            luctemp = *lptrData;

//                            ++lptrData;

                            --lreadROADdataLength;

                             ROADUInt32 lrangeLength;

                            auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalAverItem(lFractalAverItemCount);

                            if((luctemp & 128) == 128)
                            {
                                lrangeLength = (1 << (luctemp & 127)) * _options->getMinSamplesPerRang();
                            }
                            else
                            {
                                lrangeLength = (1 << (luctemp >> 5)) * _options->getMinSamplesPerRang();
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

                ROADReal *lptrPreListeningDoubleData = _preListeningDoubleData.get();

                FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(0);

                for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                     lframeIndex < _options->getMaxSuperFrameLength();
                     ++lframeIndex)
                {


                    FractalFirstOrderItemContainer *lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                    auto lFractalAverItemCount = lptrFractalFirstOrderItemContainer->getIFractalAverItemCount();


                    ROADUInt32 count = 0;

                    ROADUInt32 lrabgeLength = 0;

                    while(count < lFractalAverItemCount)
                    {
                        ROADReal lptrAver = *lptrPreListeningDoubleData;

                        FractalAverItem *lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalAverItem(count);

                        lrabgeLength = lptrFractalAverItem->getLength();

                        lptrFractalAverItem->setAver(lptrAver);

                        lrabgeLength /= _options->getMinSamplesPerRang();

                        lptrPreListeningDoubleData += lrabgeLength;

                        ++count;
                    }

                }

                if(lreadROADdataLength <= 0)
                    break;

// Обработка буфера ROADdata для выделения усреднённой составляющей.

                lHead = 0;

                lOk = false;

                lIDataReadDriver->seek(4);

                lIDataReadDriver->operator >>(lHead);

                lIDataReadDriver->operator >>(lLength);

                lIDataReadDriver->seek(-9);

                lIDataReadDriver->computeAndCheckCRC32(lLength - 4 + 9, lOk);

                lIDataReadDriver->seek(9);

                for(decltype(_options->getAmountOfChannels()) lChannel = 1;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                         lframeIndex < _options->getMaxSuperFrameLength();
                         ++lframeIndex)
                    {

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                        auto lFractalAverItemCount = lptrFractalFirstOrderItemContainer->getIFractalAverItemCount();

                        ROADUInt32 lLengthByteArray = lFractalAverItemCount * ROADConvertor::getByteLength(_options->getBitsPerSampleCode());

                        std::unique_ptr<double> lptrAver(new ROADReal[lFractalAverItemCount]);

                        std::unique_ptr<ROADByte> lptrDataTemp(new ROADByte[lLengthByteArray]);


                        lIDataReadDriver->operator >>(std::make_tuple(lptrDataTemp.get(), lLengthByteArray));


                        this->_roadOver->convertByteArrayIntoDoubleArray(lptrDataTemp.get(), lLengthByteArray, lptrAver.get());

//                        lptrData+=lLengthByteArray;

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

                lHead = 0;

                lOk = false;

                lIDataReadDriver->seek(4);

                lIDataReadDriver->operator >>(lHead);

                lIDataReadDriver->operator >>(lLength);

                lIDataReadDriver->seek(-9);

                lIDataReadDriver->computeAndCheckCRC32(lLength - 4 + 9, lOk);

                lIDataReadDriver->seek(9);

                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    auto lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                         lframeIndex < _options->getMaxSuperFrameLength();
                         ++lframeIndex)
                    {

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                        auto lFractalAverItemCount = lptrFractalFirstOrderItemContainer->getIFractalAverItemCount();


                        ROADUInt8 ldomainIndex;

                        decltype(lFractalAverItemCount) itemCount = 0;

                        ROADUInt32 countDomainIndeces = 0;

                        while(itemCount < lFractalAverItemCount)
                        {
                            auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalAverItem(itemCount);

                            ROADUInt8 itemIndex = lptrFractalAverItem->getFractalItemIndex();


                            if((itemIndex & 128) == 0)
                            {

                                lIDataReadDriver->operator >>(ldomainIndex);

//                                ldomainIndex = *lptrData;

//                                ++lptrData;


                                 ROADUInt32 lDomainOffset = (itemIndex & 7) << 8;

                                lDomainOffset |= ldomainIndex;

                                lDomainOffset = lDomainOffset * this->_frequencyScale;


                                auto lptrFractalFirstOrderItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItem(countDomainIndeces);

                                lptrFractalFirstOrderItem->setAver(lptrFractalAverItem->getAver());

                                lptrFractalFirstOrderItem->setDomainOffset(lDomainOffset);

                                lptrFractalFirstOrderItem->setInversDirection((itemIndex & 16) == 16);

                                lptrFractalFirstOrderItem->setLength(lptrFractalAverItem->getLength());

                                lptrFractalFirstOrderItem->setPosition(lptrFractalAverItem->getPosition());

                                ROADReal lScale = 1.0;

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

                lHead = 0;

                lOk = false;

                lIDataReadDriver->seek(4);

                lIDataReadDriver->operator >>(lHead);

                lIDataReadDriver->operator >>(lLength);

                lIDataReadDriver->seek(-9);

                lIDataReadDriver->computeAndCheckCRC32(lLength - 4 + 9, lOk);

                lIDataReadDriver->seek(9);

//  Обработка буфера ROADdata для выделения коэфициентов масштабирования.

                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                         lframeIndex < _options->getMaxSuperFrameLength();
                         ++lframeIndex)
                    {
                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex);

                        auto lFractalItemCount = lptrFractalFirstOrderItemContainer->getIFractalFirstOrderItemCount();

                        decltype(lFractalItemCount) itemCount = 0;

                        while(itemCount < lFractalItemCount)
                        {
                            auto lptrFractalFirstOrderItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItem(itemCount);


                            ROADUInt8 ldecimScale;

                            lIDataReadDriver->operator >>(ldecimScale);

//                            ROADUInt8 ldecimScale = *lptrData;

//                            ++lptrData;

                            ROADReal lScale = static_cast<ROADReal> (ldecimScale) / 255.0;

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

                    ROADReal* lptrDoubleData = _channelsDataBuffer.getIDoubleDataContainer(lChannel)->getData();

                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                         lframeIndex < _options->getMaxSuperFrameLength();
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

ROADdecoder::ROADover::ROADoverManagerFirstOrderVersion::~ROADoverManagerFirstOrderVersion()
{
    for(auto item : _fractalItemSuperFrameContainer)
        delete item;

    _fractalItemSuperFrameContainer.clear();

    delete _options;
}
