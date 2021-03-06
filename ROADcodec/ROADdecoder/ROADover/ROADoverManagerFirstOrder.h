#ifndef ROADOVERMANAGERFIRSTORDER_H
#define ROADOVERMANAGERFIRSTORDER_H

#include <vector>
#include <memory>
#include <fstream>

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

            private: Endian::EndianType _lowFormatEndianType;

            private: RawDataSampleType _rawDataSample;

            private: DecodedSampleType _decodingSample;

            std::fstream file;

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
                  _lowFormatEndianType(aLowFormatEndianType)
            {

                file.open("C:\\Users\\Evgney\\Documents\\dumpDecoder.txt");

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

                    ROADUInt8 lEndingCode = this->_options->getEndianType();

                    auto lIDataReadDriver = ROADdecoder::Driver::DataDriver::getIDataReadDriver(this->_bufferROADdata,
                                                                      lreadROADdataLength,
                                                                      Endian::EndianType(lEndingCode));



                    do
                    {

                        ROADUInt8 lHead = 0;

                        lIDataReadDriver->operator >>(lHead);

                        if((lHead&127) !=  1)
                            break;

                        ROADUInt32 lCRC32;

                        lIDataReadDriver->operator >>(lCRC32);


                        // read prelistening data and check prelistening CRC32 Block
                        auto lreadPreListeningLength = this->_roadOver->readPreListening(_preListeningRawData.get(), lCRC32);

                        if(lreadPreListeningLength == 0)
                            break;

                        auto lIDataReadDriverPreListeningRawData = ROADdecoder::Driver::DataDriver::getIDataReadDriver(this->_preListeningRawData,
                                                                                                                       lreadPreListeningLength,
                                                                                                                       this->_lowFormatEndianType);

//                        auto lptrPreListeningDecodingSampleTypeData = _preListeningDecodingSampleTypeData;

//                        while (!lIDataReadDriverPreListeningRawData->eod())
//                        {
//                            lIDataReadDriverPreListeningRawData->operator >>(_rawDataSample);

//                            *lptrPreListeningDecodingSampleTypeData++ = _rawDataSample;
//                        }





                        do
                        {

                            lIDataReadDriver->operator >>(lHead);

                            if((lHead&127) == 2)
                            {

                                // Обработка буфера ROADdata для выделения длинн рангов.

                                lreadResult = readIndekcesDataStream(lIDataReadDriver.get(), lFrameLengthLength);

                                // Обработка буфера предпрослушивания

                                lreadResult = readPrelisteningDataStream(lIDataReadDriverPreListeningRawData.get());
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

                            PtrDecodedSampleType lptrPtrDecodedSampleMassive = (this->_channelsDataBuffer).getPtrDecodedDataContainer(lChannel)->getData();

                            for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
                                 lframeIndex < _options->getMaxSuperFrameLength();
                                 ++lframeIndex)
                            {
                                _fractalBuilder->build(lptrPtrDecodedSampleMassive + (lframeIndex * lFrameLengthLength),
                                                               lptrFractalFirstOrderItemsSuperFrameContainer->getFrameDataContainer(lframeIndex));
                            }

                        }

                        ROADUInt64 lLength;

                        ROADInt8 lHead;

                        lIDataReadDriver->operator >>(lHead);

                        lIDataReadDriver->operator >>(lLength);


//                        for(decltype(_options->getAmountOfChannels()) lChannel = 0;
//                            lChannel < 1;
//                            ++lChannel)
//                        {
//                            PtrDecodedSampleType lptrPtrDecodedSampleMassive = (this->_channelsDataBuffer).getPtrDecodedDataContainer(lChannel)->getData();

//                            readAndAddError(lIDataReadDriver.get(), lptrPtrDecodedSampleMassive);
//                        }


                        file << "raw data. aLength: " << lreadROADdataLength << std::endl;

                        for(decltype(lreadROADdataLength)lindex = 0;
                            lindex < lreadROADdataLength;
                            ++lindex)
                        file << "byte: " << (int) this->_bufferROADdata.get()[lindex] << std::endl;

                        for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                            lChannel < _options->getAmountOfChannels();
                            ++lChannel)
                        {



                            PtrDecodedSampleType lptrPtrDecodedSampleMassive = (this->_channelsDataBuffer).getPtrDecodedDataContainer(lChannel)->getData();



                            for( decltype(this->_superFrameSamplesLength) lsampleIndex = 0;
                                 lsampleIndex < this->_superFrameSamplesLength;
                                 ++lsampleIndex)
                            {
                                lIDataReadDriver->operator >>(_rawDataSample);

                                _decodingSample = _rawDataSample;

//                                file << "_decodingSample: " << _rawDataSample << std::endl;

                            //    auto lv = lptrPtrDecodedSampleMassive[lsampleIndex];

                            //    lptrPtrDecodedSampleMassive[lsampleIndex] = lv + _decodingSample;
                            }
                        }

                        this->_channelsMixing->compute(&(this->_channelsDataBuffer));

                        this->_roadOver->writeRawData(&(this->_channelsDataBuffer));

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

//                delete []_preListeningDecodingSampleTypeData;

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

            protected: ROADInt32 readPrelisteningDataStream(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver)
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
                        aIDataReadDriver->operator >>(_rawDataSample);

                        _decodingSample = _rawDataSample;

                        auto lptrFractalAverItem = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(count);

                        lrabgeLength = lptrFractalAverItem->getLength();

                        lptrFractalAverItem->setAverage(&_decodingSample);

                        lrabgeLength /= _options->getMinSamplesPerRang();

                        aIDataReadDriver->seek(lrabgeLength - 1);

//                        aPtrDecodingSampleMassive += lrabgeLength;

                        ++count;
                    }

                }


                return lresult;
            }

            protected: ROADInt32 readAverageAudioDataStream(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver, ROADUInt32)
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

            protected: ROADInt32 readDomainsAndScalesDataStream(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver, ROADUInt32)
            {
                using namespace PlatformDependencies;

                ROADInt32 lresult = -1;


                ROADUInt64 lLength;

                aIDataReadDriver->operator >>(lLength);

                // Обработка буфера ROADdata для выделения номеров доменнов.

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

                        while(itemCount < lFractalFirstOrderItemCount)
                        {
                            auto lptrFractalFirstOrderItemTransform = lptrFractalFirstOrderItemContainer->getFractalFirstOrderItemTransform(itemCount);

                            ROADUInt8 itemIndex = lptrFractalFirstOrderItemTransform->getFractalItemIndex();


                            if((itemIndex & 128) == 0)
                            {

                                aIDataReadDriver->operator >>(ldomainIndex);

                                 ROADUInt32 lDomainOffset = (itemIndex & 7) << 8;

                                lDomainOffset |= ldomainIndex;

                                lDomainOffset = lDomainOffset * this->_frequencyScale;

                                lptrFractalFirstOrderItemTransform->setRangTransform((itemIndex & 16) == 16, lDomainOffset, 0.0);

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
                                ROADInt8 ldecimScale;

                                aIDataReadDriver->operator >>(ldecimScale);

                                _decodingSample = (DecodedSampleType)ldecimScale;

                                lptrFractalFirstOrderItem->setScale(_decodingSample);
                            }

                            ++itemCount;
                        }
                    }

                }

                aIDataReadDriver->seek(4);

                return lresult;
            }

            protected: ROADInt32 readAndAddError(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver, PtrDecodedSampleType aPtrDecodedSampleMassive)
            {
                using namespace PlatformDependencies;

                ROADInt32 lresult = -1;

                for( decltype(this->_superFrameSamplesLength) lsampleIndex = 0;
                     lsampleIndex < this->_superFrameSamplesLength;
                     ++lsampleIndex)
                {
                    aIDataReadDriver->operator >>(_rawDataSample);

                    _decodingSample = _rawDataSample;

                    aPtrDecodedSampleMassive[lsampleIndex] += _decodingSample;
                }

                return lresult;

            }

        };
    }
}

#endif // ROADOVERMANAGERFIRSTORDER_H
