#ifndef ROADOVERMANAGERFIRSTORDER_H
#define ROADOVERMANAGERFIRSTORDER_H

#include <vector>
#include <memory>
#include "../ROAD/IROADFractalFirstOrderBuilder.h"
#include "../ROAD/ROADFractalFirstOrderBuilderFactory.h"
#include "../ROAD/ROADFractalOrderFactory.h"
#include "Result.h"
#include "ROADoverManager.h"
#include "ROADoverCommon.h"
#include "ROADoverDecodingOptionsFirstOrderVersion.h"
#include "ROADFractalFirstOrderItemsSuperFrameDataContainer.h"
#include "MIDChannelsMixing.h"
#include "SIDEChannelsMixing.h"
#include "ROADover.h"
#include "DataDriver.h"
#include "ROADoverCommon.h"


#include <iostream>

namespace ROADdecoder
{
    namespace ROADover
    {
        template<typename ROADRawDataSampleType, typename ROADDecodedSampleType>
        class ROADoverManagerFirstOrder: public ROADdecoder::ROADover::ROADoverManager<ROADDecodedSampleType>
        {
            private: typedef ROADDecodedSampleType DecodedSampleType;
            private: typedef DecodedSampleType* PtrDecodedSampleType;
            private: typedef ROADRawDataSampleType RawDataSampleType;

            private: std::unique_ptr<ROADdecoder::ROAD::IROADFractalFirstOrderBuilder> _fractalBuilder;
            protected: std::vector<ROADFractalFirstOrderItemsSuperFrameDataContainer<DecodedSampleType>*> _fractalItemSuperFrameContainer;

            protected: ROADdecoder::ROADover::ROADoverDecodingOptionsFirstOrderVersion* _options;

            protected: std::shared_ptr<ROADByte> _preListeningRawData;

            private: std::unique_ptr<DecodedSampleType> _preListeningDecodingSampleTypeData;

            private: Endian::EndianType _lowFormatEndianType;

            private: RawDataSampleType _rawDataSample;

            private: DecodedSampleType _decodingSample;

            public: ROADoverManagerFirstOrder(ROADdecoder::ROADover::ROADover* aRoadOver,
                                              ROADdecoder::ROADover::ROADoverDecodingOptionsFirstOrderVersion* aOptions,
                                              Endian::EndianType aLowFormatEndianType)
                :ROADoverManager<ROADDecodedSampleType>(aRoadOver,
                                 aOptions->getAmountOfChannels(),
                                 ROADConvertor::getByteLength(aOptions->getBitsPerSampleCode()),
                                 aOptions->getMaxSuperFrameLength(),
                                 aOptions->getFrameSampleLength(),
                                 aOptions->getFrameSampleLength() *
                                 aOptions->getMaxSuperFrameLength()),
                  _options(aOptions),
                  _preListeningRawData(new ROADByte[
                                    ROADConvertor::getByteLength(aOptions->getBitsPerSampleCode()) *
                                    aOptions->getMaxFrameRangLength() *
                                    aOptions->getMaxSuperFrameLength()]),
                  _preListeningDecodingSampleTypeData(new DecodedSampleType[
                                          aOptions->getMinSamplesPerRang() *
                                          aOptions->getMaxFrameRangLength() *
                                          aOptions->getMaxSuperFrameLength()]),
                  _lowFormatEndianType(aLowFormatEndianType)
            {
                class Excepion: public std::exception
                {
                private:
                    std::string _message;

                public:
                  Excepion(const char* aMessage) _GLIBCXX_USE_NOEXCEPT:_message(aMessage) { }

                  virtual ~Excepion() _GLIBCXX_USE_NOEXCEPT{}

                  virtual const char* what() const _GLIBCXX_USE_NOEXCEPT
                  {
                      return _message.c_str();
                  }

                };

                switch(this->_options->getMixingChannelsMode())
                {
                case MID:
                    this->_channelsMixing.reset(new MIDChannelsMixing<DecodedSampleType>);
                break;
                case SIDE:
                    this->_channelsMixing.reset(new SIDEChannelsMixing<DecodedSampleType>);
                break;
                case NONE:
                default:
                break;
                }

                using namespace ROADdecoder::ROAD;



                std::unique_ptr<IROADFractalBuilderFactory> lptrIROADFractalBuilderFactory(ROADdecoder::ROAD::ROADFractalOrderFactory::getIROADFractalBuilderFactory(1));

                if(!lptrIROADFractalBuilderFactory || lptrIROADFractalBuilderFactory->getOrder() != 1)
                {
                    throw Excepion("Format Experemental is not supported!!!");
                }

                std::unique_ptr<ROADFractalFirstOrderBuilderFactory> lptrROADFractalFirstOrderBuilderFactory(dynamic_cast<ROADFractalFirstOrderBuilderFactory*>(lptrIROADFractalBuilderFactory.release()));

                if(!lptrROADFractalFirstOrderBuilderFactory)
                {
                    throw Excepion("Format Experemental is not supported!!!");
                }


                this->_frequencyScale = _options->getMinSamplesPerRang() / _options->getOriginalMinSamplesPerRang();

                _fractalBuilder.reset(lptrROADFractalFirstOrderBuilderFactory->getIROADFractalFirstOrderBuilder(DecodedSampleTypeToROADRawDataFormat<DecodedSampleType>::_code,
                                                                                                                _options->getFrameSampleLength(),
                                                                                                                _options->getAmountRangLevels()));
                if(!_fractalBuilder)
                {
                    throw Excepion("DecodedSampleType is not supported!!!");
                }

                for(decltype(aOptions->getAmountOfChannels()) index = 0;
                    index < aOptions->getAmountOfChannels();
                    ++index)
                {
                    auto lContainer = new ROADFractalFirstOrderItemsSuperFrameDataContainer<DecodedSampleType>(aOptions->getMaxSuperFrameLength(),
                                                                                                                aOptions->getMaxFrameRangLength(),
                                                                                                                aOptions->getMinSamplesPerRang());

                    _fractalItemSuperFrameContainer.push_back(lContainer);
                }
            }

            public: ROADdecoder::ROADover::Result decode()
            {
                Result result = Result::ERROR;

                this->_roadOver->lockResource();

                auto lreadROADdataLength = this->_roadOver->readROADdata(this->_bufferROADdata.get());

                switch(lreadROADdataLength)
                {
                case -1:

                    result = Result::FINISHFILE;

                    break;

                default:
                {
                    result = Result::DONE;

                    ROADUInt32 lFrameLengthLength = _options->getMaxFrameRangLength() * _options->getMinSamplesPerRang();

                    ROADInt32 lreadResult = -1;

                    do
                    {

                        ROADUInt8 lEndingCode = this->_options->getEndianType();

                        auto lIDataReadDriver = ROADdecoder::Driver::DataDriver::getIDataReadDriver(this->_bufferROADdata,
                                                                          lreadROADdataLength,
                                                                          Endian::EndianType(lEndingCode));


                        ROADUInt8 lHead = 0;

                        // check prelistening CRC32 Block
                        lIDataReadDriver->operator >>(lHead);

                        if((lHead&127) !=  1)
                            break;

                        ROADUInt32 lCRC32;

                        lIDataReadDriver->operator >>(lCRC32);


                        auto lreadPreListeningLength = this->_roadOver->readPreListening(_preListeningRawData.get(), lCRC32);

                        if(lreadPreListeningLength == 0)
                            break;

                        auto lIDataReadDriverPreListeningRawData = ROADdecoder::Driver::DataDriver::getIDataReadDriver(this->_preListeningRawData,
                                                                                                                       lreadPreListeningLength,
                                                                                                                       this->_lowFormatEndianType);

                        auto lptrPreListeningDecodingSampleTypeData = _preListeningDecodingSampleTypeData.get();

                        while (!lIDataReadDriverPreListeningRawData->eod())
                        {
                            lIDataReadDriverPreListeningRawData->operator >>(_rawDataSample);

                            *lptrPreListeningDecodingSampleTypeData++ = _rawDataSample;
                        }



                        do
                        {

                            lIDataReadDriver->operator >>(lHead);

                            if((lHead&127) == 2)
                            {

                                // Обработка буфера ROADdata для выделения длинн рангов.

                                lreadResult = readIndekcesDataStream(lIDataReadDriver.get(), lFrameLengthLength);

                                // Обработка буфера предпрослушивания

                                auto lptrPreListeningDecodingSampleMassive = _preListeningDecodingSampleTypeData.get();

                                lreadResult = readPrelisteningDataStream(lptrPreListeningDecodingSampleMassive);
                            }

                            if(lIDataReadDriver->eod())
                                break;


                            lIDataReadDriver->operator >>(lHead);

                            if((lHead&127) == 3)
                            {

                                // Обработка буфера ROADdata для выделения усреднённой составляющей.

                                lreadResult = readAverageAudioDataStream(lIDataReadDriver.get(), lFrameLengthLength);
                            }

                            if(lIDataReadDriver->eod())
                                break;



                            lIDataReadDriver->operator >>(lHead);

                            if((lHead&127) == 4)
                            {

                                // Обработка буфера ROADdata для выделения номеров доменнов.
                                // Обработка буфера ROADdata для выделения коэфициентов масштабирования.

                                lreadResult = readDomainsAndScalesDataStream(lIDataReadDriver.get(), lFrameLengthLength);
                            }

                            if(lIDataReadDriver->eod())
                                break;

                        }
                        while(false);

                    }
                    while(false);

        // Выполнение постороения фракталов для декодирования
                    {
                        for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                            lChannel < _options->getAmountOfChannels();
                            ++lChannel)
                        {

                            auto lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                            PtrDecodedSampleType lptrDoubleData = (this->_channelsDataBuffer).getPtrDecodedDataContainer(lChannel)->getData();

                            for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                                 lframeIndex < _options->getMaxSuperFrameLength();
                                 ++lframeIndex)
                            {
                                _fractalBuilder->build(lptrDoubleData + (lframeIndex * lFrameLengthLength),
                                                               lptrFractalFirstOrderItemsSuperFrameContainer->getFrameDataContainer(lframeIndex));
                            }
                        }

                        this->_channelsMixing->compute(& (this->_channelsDataBuffer));

                        this->_roadOver->writeRawData(& (this->_channelsDataBuffer));

                    }

                }

                    break;
                }

                this->_roadOver->unlockResource();

                return result;
            }

            public: virtual ~ROADoverManagerFirstOrder()
            {
                for(auto item : _fractalItemSuperFrameContainer)
                    delete item;

                _fractalItemSuperFrameContainer.clear();

            }

            protected: ROADInt32 readIndekcesDataStream(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver, ROADUInt32 aFrameLengthLength)
            {
                using namespace PlatformDependencies;

                ROADInt32 lresult = -1;

                ROADUInt64 lLength;

                aIDataReadDriver->operator >>(lLength);

                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {

                    auto lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                         lframeIndex < _options->getMaxSuperFrameLength();
                         ++lframeIndex)
                    {

                         ROADUInt32 lFractalAverItemCount = 0;

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFrameDataContainer(lframeIndex);

                        auto lLength = aFrameLengthLength;

                        ROADUInt8 luctemp = 0;

                        ROADUInt32 lcurrentPosition = 0;

                        while(lLength > 0)
                        {

                            aIDataReadDriver->operator >>(luctemp);

                            ROADUInt32 lrangeLength;

                            auto lptrFractalFirstOrderItemTransform = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(lFractalAverItemCount);

                            if((luctemp & 128) == 128)
                            {
                                lrangeLength = (1 << (luctemp & 127)) * _options->getMinSamplesPerRang();
                            }
                            else
                            {
                                lrangeLength = (1 << (luctemp >> 5)) * _options->getMinSamplesPerRang();
                            }

                            lptrFractalFirstOrderItemTransform->setIndexInfo(lcurrentPosition,
                                                                             lrangeLength,
                                                                             luctemp);

                            lLength -= lrangeLength;

                            lcurrentPosition+=lrangeLength;

                            ++lFractalAverItemCount;
                        }

                        lptrFractalFirstOrderItemContainer->setFractalFirstOrderItemCount(lFractalAverItemCount);

                    }
                }

                aIDataReadDriver->seek(4);

                return lresult;
            }

            protected: ROADInt32 readPrelisteningDataStream(PtrDecodedSampleType aPtrDecodingSampleMassive)
            {
                using namespace PlatformDependencies;

                ROADInt32 lresult = -1;

                auto lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(0);

                for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                     lframeIndex < _options->getMaxSuperFrameLength();
                     ++lframeIndex)
                {


                    auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFrameDataContainer(lframeIndex);

                    auto lFractalFirstOrderItemCount = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemCount();


                    ROADUInt32 count = 0;

                    ROADUInt32 lrabgeLength = 0;

                    while(count < lFractalFirstOrderItemCount)
                    {
                        _rawDataSample = *aPtrDecodingSampleMassive;

                        auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(count);

                        lrabgeLength = lptrFractalAverItem->getLength();

                        lptrFractalAverItem->setAverage(&_rawDataSample);

                        lrabgeLength /= _options->getMinSamplesPerRang();

                        aPtrDecodingSampleMassive += lrabgeLength;

                        ++count;
                    }

                }


                return lresult;
            }

            protected: ROADInt32 readAverageAudioDataStream(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver, ROADUInt32 aFrameLengthLength)
            {
                using namespace PlatformDependencies;

                ROADInt32 lresult = -1;

                ROADUInt64 lLength;

                aIDataReadDriver->operator >>(lLength);

                for(decltype(_options->getAmountOfChannels()) lChannel = 1;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    auto lptrFractalFirstOrderItemSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                         lframeIndex < _options->getMaxSuperFrameLength();
                         ++lframeIndex)
                    {

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemSuperFrameContainer->getFrameDataContainer(lframeIndex);

                        auto lFractalFirstOrderItemCount = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemCount();

                        for(decltype(lFractalFirstOrderItemCount) lItemIndex = 0;
                            lItemIndex < lFractalFirstOrderItemCount;
                            ++lItemIndex)
                        {
                            aIDataReadDriver->operator >>(_rawDataSample);

                            _decodingSample = _rawDataSample;

                            auto lptrFractalFirstOrderItemTransform = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(lItemIndex);

                            lptrFractalFirstOrderItemTransform->setAverage(&_decodingSample);
                        }
                    }
                }

                aIDataReadDriver->seek(4);

                return lresult;

            }

            protected: ROADInt32 readDomainsAndScalesDataStream(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver, ROADUInt32 aFrameLengthLength)
            {
                using namespace PlatformDependencies;

                ROADInt32 lresult = -1;


                ROADUInt64 lLength;

                aIDataReadDriver->operator >>(lLength);


                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    auto lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                         lframeIndex < _options->getMaxSuperFrameLength();
                         ++lframeIndex)
                    {

                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFrameDataContainer(lframeIndex);

                        auto lFractalFirstOrderItemCount = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemCount();


                        ROADUInt8 ldomainIndex;

                        decltype(lFractalFirstOrderItemCount) itemCount = 0;

//                        ROADUInt32 countDomainIndeces = 0;

                        while(itemCount < lFractalFirstOrderItemCount)
                        {
                            auto lptrFractalFirstOrderItemTransform = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(itemCount);

                            ROADUInt8 itemIndex = lptrFractalFirstOrderItemTransform->getFractalItemIndex();


                            if((itemIndex & 128) == 0)
                            {

                                aIDataReadDriver->operator >>(ldomainIndex);

            //                                ldomainIndex = *lptrData;

            //                                ++lptrData;


                                 ROADUInt32 lDomainOffset = (itemIndex & 7) << 8;

                                lDomainOffset |= ldomainIndex;

                                lDomainOffset = lDomainOffset * this->_frequencyScale;


//                                auto lptrFractalFirstOrderItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItem(countDomainIndeces);

//                                lptrFractalFirstOrderItem->setAver(lptrFractalFirstOrderItemTransform->getAver());

//                                lptrFractalFirstOrderItem->setDomainOffset(lDomainOffset);

//                                lptrFractalFirstOrderItem->setInversDirection((itemIndex & 16) == 16);

//                                lptrFractalFirstOrderItem->setLength(lptrFractalFirstOrderItemTransform->getLength());

//                                lptrFractalFirstOrderItem->setPosition(lptrFractalFirstOrderItemTransform->getPosition());

                                ROADReal lScale = 1.0;

                                if((itemIndex & 8) == 8)
                                    lScale = -lScale;

                                lptrFractalFirstOrderItemTransform->setRangTransform((itemIndex & 16) == 16, lDomainOffset, lScale);

//                                ++countDomainIndeces;

                            }
                            else
                                lptrFractalFirstOrderItemTransform->setRangTransform(false, 0, 0.0);


                            ++itemCount;
                        }

                    }

                }

                if(lLength == 0)
                    return lresult;


            //  Обработка буфера ROADdata для выделения коэфициентов масштабирования.

                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                    lChannel < _options->getAmountOfChannels();
                    ++lChannel)
                {
                    auto lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                         lframeIndex < _options->getMaxSuperFrameLength();
                         ++lframeIndex)
                    {
                        auto lptrFractalFirstOrderItemContainer = lptrFractalFirstOrderItemsSuperFrameContainer->getFrameDataContainer(lframeIndex);

                        auto lFractalFirstOrderItemCount = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemCount();

                        decltype(lFractalFirstOrderItemCount) itemCount = 0;

                        while(itemCount < lFractalFirstOrderItemCount)
                        {
                            auto lptrFractalFirstOrderItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(itemCount);

                            ROADUInt8 itemIndex = lptrFractalFirstOrderItem->getFractalItemIndex();

                            if((itemIndex & 128) == 0)
                            {
                                ROADUInt8 ldecimScale;

                                aIDataReadDriver->operator >>(ldecimScale);

                                ROADReal lScale = static_cast<ROADReal> (ldecimScale) / 128.0;

                                lptrFractalFirstOrderItem->setScale(lptrFractalFirstOrderItem->getScale() * lScale);
                             //   lptrFractalAverItem->setScale(lptrFractalAverItem->getScale() * lScale);
                            }

                            ++itemCount;
                        }
                    }

                }

                aIDataReadDriver->seek(4);

                return lresult;
            }
        };
    }
}

#endif // ROADOVERMANAGERFIRSTORDER_H
