#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADoverManagerExperemental.h"
#include "ROADover.h"
#include "ROADoverDecodingOptionsExperemental.h"
#include "FractalItem.h"
#include "FractalAverItem.h"
#include "FractalItemSuperFrameContainer.h"
#include "FractalItemContainer.h"
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

    this->_frequencyScale = _options->getSamplesPerRang() / _options->getOriginalSamplesPerRang();


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
            int lreadPreListeningLength = this->_roadOver->readPreListening(_preListeningData.get());

            this->_roadOver->convertByteArrayIntoDoubleArray(_preListeningData.get(), lreadPreListeningLength, _preListeningDoubleData.get());


            // Обработка буфера ROADdata для выделения длинн рангов.
            unsigned int lFrameLengthLength = _options->getFrameRangLength() * _options->getSamplesPerRang();

            const unsigned char* lptrData = this->_bufferROADdata.get();

            for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                lChannel < _options->getAmountOfChannels();
                ++lChannel)
            {

                FractalItemSuperFrameContainer* lptrFractalItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                     lframeIndex < _options->getSuperframeLength();
                     ++lframeIndex)
                {

                    unsigned int lFractalAverItemCount = 0;

                    auto lptrFractalItemContainer = lptrFractalItemsSuperFrameContainer->getFractalItemContainer(lframeIndex);

                    int lLength = lFrameLengthLength;

                    unsigned char luctemp = 0;

                    unsigned int lcurrentPosition = 0;

                    while(lLength > 0)
                    {
                        luctemp = *lptrData;

                        ++lptrData;

                        unsigned int lrangeLength;

                        auto lptrFractalAverItem = lptrFractalItemContainer->getFractalAverItem(lFractalAverItemCount);

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

                    lptrFractalItemContainer->setFractalAverItemCount(lFractalAverItemCount);

                }
            }

// Обработка буфера предпрослушивания

            double *lptrPreListeningDoubleData = _preListeningDoubleData.get();

            FractalItemSuperFrameContainer* lptrFractalItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(0);

            for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                 lframeIndex < _options->getSuperframeLength();
                 ++lframeIndex)
            {


                FractalItemContainer *lptrFractalItemContainer = lptrFractalItemsSuperFrameContainer->getFractalItemContainer(lframeIndex);

                auto lFractalAverItemCount = lptrFractalItemContainer->getIFractalAverItemCount();


                unsigned int count = 0;

                unsigned int lrabgeLength = 0;

                while(count < lFractalAverItemCount)
                {
                    double lptrAver = *lptrPreListeningDoubleData;

                    FractalAverItem *lptrFractalAverItem = lptrFractalItemContainer->getFractalAverItem(count);

                    lrabgeLength = lptrFractalAverItem->getLength();

                    lptrFractalAverItem->setAver(lptrAver);

                    lrabgeLength /= _options->getSamplesPerRang();

                    lptrPreListeningDoubleData += lrabgeLength;

                    ++count;
                }

            }

// Обработка буфера ROADdata для выделения усреднённой составляющей.

            for(decltype(_options->getAmountOfChannels()) lChannel = 1;
                lChannel < _options->getAmountOfChannels();
                ++lChannel)
            {
                FractalItemSuperFrameContainer* lptrFractalItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                     lframeIndex < _options->getSuperframeLength();
                     ++lframeIndex)
                {

                    auto lptrFractalItemContainer = lptrFractalItemsSuperFrameContainer->getFractalItemContainer(lframeIndex);

                    auto lFractalAverItemCount = lptrFractalItemContainer->getIFractalAverItemCount();

                    unsigned int lLengthByteArray = lFractalAverItemCount * (_options->getOriginalBitsPerSample() >> 3);

                    unique_ptr<double> lptrAver(new double[lFractalAverItemCount]);



                    this->_roadOver->convertByteArrayIntoDoubleArray(lptrData, lLengthByteArray, lptrAver.get());

                    lptrData+=lLengthByteArray;

                    for(decltype(lFractalAverItemCount) lItemIndex = 0;
                        lItemIndex < lFractalAverItemCount;
                        ++lItemIndex)
                    {

                        auto lptrFractalAverItem = lptrFractalItemContainer->getFractalAverItem(lItemIndex);

                        lptrFractalAverItem->setAver(lptrAver.get()[lItemIndex]);

                    }
                }
            }
// Обработка буфера ROADdata для выделения номеров доменнов.


            for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                lChannel < _options->getAmountOfChannels();
                ++lChannel)
            {
                auto lptrFractalItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                     lframeIndex < _options->getSuperframeLength();
                     ++lframeIndex)
                {

                    auto lptrFractalItemContainer = lptrFractalItemsSuperFrameContainer->getFractalItemContainer(lframeIndex);

                    auto lFractalAverItemCount = lptrFractalItemContainer->getIFractalAverItemCount();


                    unsigned char ldomainIndex;

                    decltype(lFractalAverItemCount) itemCount = 0;

                    unsigned int countDomainIndeces = 0;

                    while(itemCount < lFractalAverItemCount)
                    {
                        auto lptrFractalAverItem = lptrFractalItemContainer->getFractalAverItem(itemCount);

                        unsigned char itemIndex = lptrFractalAverItem->getFractalItemIndex();


                        if((itemIndex & 128) == 0)
                        {

                            ldomainIndex = *lptrData;

                            ++lptrData;


                            unsigned int lDomainOffset = (itemIndex & 7) << 8;

                            lDomainOffset |= ldomainIndex;

                            lDomainOffset = lDomainOffset * this->_frequencyScale;


                            auto lptrFractalItem = lptrFractalItemContainer->getFractalItem(countDomainIndeces);

                            lptrFractalItem->setAver(lptrFractalAverItem->getAver());

                            lptrFractalItem->setDomainOffset(lDomainOffset);

                            lptrFractalItem->setInversDirection((itemIndex & 16) == 16);

                            lptrFractalItem->setLength(lptrFractalAverItem->getLength());

                            lptrFractalItem->setPosition(lptrFractalAverItem->getPosition());

                            double lScale = 1.0;

                            if((itemIndex & 8) == 8)
                                lScale = -lScale;

                            lptrFractalItem->setScale(lScale);

                            ++countDomainIndeces;
                        }

                        ++itemCount;
                    }

                    lptrFractalItemContainer->setFractalItemCount(countDomainIndeces);

                }



        //        qDebug(QString("countDomainIndeces: %1").arg(countDomainIndeces).toStdString().c_str());

            }


//  Обработка буфера ROADdata для выделения коэфициентов масштабирования.

            for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                lChannel < _options->getAmountOfChannels();
                ++lChannel)
            {
                FractalItemSuperFrameContainer* lptrFractalItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                     lframeIndex < _options->getSuperframeLength();
                     ++lframeIndex)
                {
                    auto lptrFractalItemContainer = lptrFractalItemsSuperFrameContainer->getFractalItemContainer(lframeIndex);

                    auto lFractalItemCount = lptrFractalItemContainer->getIFractalItemCount();

                    decltype(lFractalItemCount) itemCount = 0;

                    while(itemCount < lFractalItemCount)
                    {
                        auto lptrFractalItem = lptrFractalItemContainer->getFractalItem(itemCount);

                        unsigned char ldecimScale = *lptrData;

                        ++lptrData;

                        double lScale = static_cast<double> (ldecimScale) / 255.0;

                        lptrFractalItem->setScale(lptrFractalItem->getScale() * lScale);

                        ++itemCount;
                    }
                }

            }


// Выполнение постороения фракталов для декодирования

            for(decltype(_options->getAmountOfChannels()) lChannel = 0;
                lChannel < _options->getAmountOfChannels();
                ++lChannel)
            {

                FractalItemSuperFrameContainer* lptrFractalItemsSuperFrameContainer = _fractalItemSuperFrameContainer.at(lChannel);

                double* lptrDoubleData = _channelsDataBuffer.getIDoubleDataContainer(lChannel)->getData();

                for( decltype(_options->getSuperframeLength()) lframeIndex = 0;
                     lframeIndex < _options->getSuperframeLength();
                     ++lframeIndex)
                {
                    _fractalBuilder->build(lptrDoubleData + (lframeIndex * lFrameLengthLength),
                                                   lptrFractalItemsSuperFrameContainer->getFractalItemContainer(lframeIndex));
                }
            }

            this->_channelsMixing->compute(&_channelsDataBuffer);

            this->_roadOver->writeRawData(&_channelsDataBuffer);

        }

        break;
    }

    this->_roadOver->unlockResource();

    return result;
}

ROADdecoder::ROADover::ROADoverManagerExperemental::~ROADoverManagerExperemental()
{
    delete _options;
}
