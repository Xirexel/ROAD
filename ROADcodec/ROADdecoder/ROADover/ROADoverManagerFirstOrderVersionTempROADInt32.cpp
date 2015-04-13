#include "ROADoverManagerFirstOrderVersionTempROADInt32.h"
#include "BytesToROADInt32.h"
#include "ROADoverDecodingOptionsFirstOrderVersion.h"
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

ROADdecoder::ROADover::ROADoverManagerFirstOrderVersionTempROADInt32::ROADoverManagerFirstOrderVersionTempROADInt32(ROADover *aRoadOver,
                                                                                                                    ROADoverDecodingOptionsFirstOrderVersion *aOptions,
                                                                                                                    Endian::EndianType aEndianType)
    :ROADoverManagerFirstOrderVersion(aRoadOver,
                                      aOptions)
{

    switch(aOptions->getBitsPerSampleCode())
    {
        case ROADRawDataFormat::U8:
            _convertorPrelistening.reset(new BytesToROADInt32<ROADUInt8>(aEndianType));

        break;
        case ROADRawDataFormat::S16:
            _convertorPrelistening.reset(new BytesToROADInt32<ROADInt16>(aEndianType));

        break;

    default:
        throw std::exception();
        break;
    }

}

ROADdecoder::ROADover::Result ROADdecoder::ROADover::ROADoverManagerFirstOrderVersionTempROADInt32::decode()
{
    Result result = Result::ERROR;

    this->_roadOver->lockResource();

//    auto lreadROADdataLength = this->_roadOver->readROADdata(this->_bufferROADdata.get());

//    switch(lreadROADdataLength)
//    {
//    case -1:

//        result = Result::FINISHFILE;

//        break;

//    default:

//        result = Result::DONE;

//        {
//            ROADUInt32 lFrameLengthLength = _options->getMaxFrameRangLength() * _options->getMinSamplesPerRang();

//            ROADInt32 lreadResult = -1;

//            do
//            {

//                ROADUInt8 lEndingCode = this->_options->getEndianType();

//                auto lIDataReadDriver = ROADdecoder::Driver::DataDriver::getIDataReadDriver(this->_bufferROADdata,
//                                                                  lreadROADdataLength,
//                                                                  Endian::EndianType(lEndingCode));


//                ROADUInt8 lHead = 0;

//                // check prelistening CRC32 Block
//                lIDataReadDriver->operator >>(lHead);

//                if((lHead&127) !=  1)
//                    break;

//                ROADUInt32 lCRC32;

//                lIDataReadDriver->operator >>(lCRC32);


//                auto lreadPreListeningLength = this->_roadOver->readPreListening(_preListeningData.get(), lCRC32);

//                if(lreadPreListeningLength == 0)
//                    break;

//                this->_roadOver->convertByteArrayIntoDoubleArray(_preListeningData.get(), lreadPreListeningLength, _preListeningDoubleData.get());


//                do
//                {

//                    lIDataReadDriver->operator >>(lHead);

//                    if((lHead&127) == 2)
//                    {

//                        // Обработка буфера ROADdata для выделения длинн рангов.

//                        lreadResult = readIndekcesDataStream(lIDataReadDriver.get(), lFrameLengthLength);

//                        // Обработка буфера предпрослушивания

//                        ROADReal *lptrPreListeningDoubleData = _preListeningDoubleData.get();

//                        lreadResult = readPrelisteningDataStream(lptrPreListeningDoubleData);
//                    }

//                    if(lIDataReadDriver->eod())
//                        break;


//                    lIDataReadDriver->operator >>(lHead);

//                    if((lHead&127) == 3)
//                    {

//                        // Обработка буфера ROADdata для выделения усреднённой составляющей.

//                        lreadResult = readAverageAudioDataStream(lIDataReadDriver.get(), lFrameLengthLength);
//                    }

//                    if(lIDataReadDriver->eod())
//                        break;



//                    lIDataReadDriver->operator >>(lHead);

//                    if((lHead&127) == 4)
//                    {

//                        // Обработка буфера ROADdata для выделения номеров доменнов.
//                        // Обработка буфера ROADdata для выделения коэфициентов масштабирования.

//                        lreadResult = readDomainsAndScalesDataStream(lIDataReadDriver.get(), lFrameLengthLength);
//                    }

//                    if(lIDataReadDriver->eod())
//                        break;

//                }
//                while(false);

//            }
//            while(false);

//// Выполнение постороения фракталов для декодирования
//            {
//                for(decltype(_options->getAmountOfChannels()) lChannel = 0;
//                    lChannel < _options->getAmountOfChannels();
//                    ++lChannel)
//                {

//                    FractalFirstOrderItemSuperFrameContainer* lptrFractalFirstOrderItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

//                    ROADReal* lptrDoubleData = _channelsDataBuffer.getIDoubleDataContainer(lChannel)->getData();

//                    for( decltype(_options->getMaxSuperFrameLength()) lframeIndex = 0;
//                         lframeIndex < _options->getMaxSuperFrameLength();
//                         ++lframeIndex)
//                    {
//                        _fractalBuilder->build(lptrDoubleData + (lframeIndex * lFrameLengthLength),
//                                                       lptrFractalFirstOrderItemsSuperFrameContainer->getFractalFirstOrderItemContainer(lframeIndex));
//                    }
//                }

//                this->_channelsMixing->compute(&_channelsDataBuffer);

//                this->_roadOver->writeRawData(&_channelsDataBuffer);

//            }
//        }

//        break;
//    }

    this->_roadOver->unlockResource();

    return result;
}

