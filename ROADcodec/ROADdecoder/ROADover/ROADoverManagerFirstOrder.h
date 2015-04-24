#ifndef ROADOVERMANAGERFIRSTORDER_H
#define ROADOVERMANAGERFIRSTORDER_H

#include <vector>
#include <memory>
#include "../ROAD/IROADFractalFirstOrderBuilder.h"
#include "Result.h"
#include "ROADoverManager.h"
#include "ROADoverCommon.h"
#include "ROADoverDecodingOptionsFirstOrderVersion.h"

//namespace ROADdecoder
//{
//    namespace ROADover
//    {
//        class ROADover;
//        class ROADoverDecodingOptionsFirstOrderVersion;
//        class FractalFirstOrderItemSuperFrameContainer;
//    }

//    namespace Driver
//    {
//        class IDataReadDriver;
//    }
//}

namespace ROADdecoder
{
    namespace ROADover
    {
        template<ROADInt32 ROADRawDataFormatCode, typename ROADDecodingSampleType>
        class ROADoverManagerFirstOrder: public ROADdecoder::ROADover::ROADoverManager
        {
            private: typedef ROADDecodingSampleType DecodingSampleType;
            private: typedef DecodingSampleType* PtrDecodingSampleType;

            private: std::unique_ptr<ROADdecoder::ROAD::IROADFractalFirstOrderBuilder> _fractalBuilder;
            protected: std::vector<ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer*> _fractalItemSuperFrameContainer;

            protected: ROADdecoder::ROADover::ROADoverDecodingOptionsFirstOrderVersion* _options;

            protected: std::shared_ptr<ROADByte> _preListeningRawData;

            private: std::unique_ptr<DecodingSampleType> _preListeningDecodingSampleTypeData;

            public: ROADoverManagerFirstOrder(ROADdecoder::ROADover::ROADover* aRoadOver,
                                              ROADdecoder::ROADover::ROADoverDecodingOptionsFirstOrderVersion* aOptions,
                                              Endian::EndianType aEndianType)
                :ROADoverManager(aRoadOver,
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
                  _preListeningDecodingSampleTypeData(new DecodingSampleType[
                                          aOptions->getMinSamplesPerRang() *
                                          aOptions->getMaxFrameRangLength() *
                                          aOptions->getMaxSuperFrameLength()])
            {

            }

            public: ROADdecoder::ROADover::Result decode()
            {

            }

            public: virtual ~ROADoverManagerFirstOrder()
            {

            }

            protected: ROADInt32 readIndekcesDataStream(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver, ROADUInt32 aFrameLengthLength)
            {

            }

            protected: ROADInt32 readPrelisteningDataStream(ROADReal *aPtrPreListeningDoubleData)
            {

            }

            protected: ROADInt32 readAverageAudioDataStream(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver, ROADUInt32 aFrameLengthLength)
            {

            }

            protected: ROADInt32 readDomainsAndScalesDataStream(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver, ROADUInt32 aFrameLengthLength)
            {

            }
        };
    }
}

#endif // ROADOVERMANAGERFIRSTORDER_H
