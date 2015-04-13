#ifndef ROADOVERMANAGERFIRSTORDERVERSIONTEMPROADINT32_H
#define ROADOVERMANAGERFIRSTORDERVERSIONTEMPROADINT32_H

#include <memory>


#include "ROADoverManagerFirstOrderVersion.h"
#include "IBytesToROADInt32.h"
#include "EndianType.h"

namespace ROADdecoder
{
    namespace ROADover
    {
        class ROADoverManagerFirstOrderVersionTempROADInt32 : public ROADoverManagerFirstOrderVersion
        {
            private: std::unique_ptr<IBytesToROADInt32> _convertorPrelistening;

            private: std::unique_ptr<IBytesToROADInt32> _convertorAudioStream;

            private: std::unique_ptr<ROADInt32> _preListeningInt32Data;

            public: ROADoverManagerFirstOrderVersionTempROADInt32(ROADover* aRoadOver,
                                                                  ROADoverDecodingOptionsFirstOrderVersion* aOptions,
                                                                  Endian::EndianType aEndianType);

            public: ROADdecoder::ROADover::Result decode();
        };
    }
}

#endif // ROADOVERMANAGERFIRSTORDERVERSIONTEMPROADINT32_H
