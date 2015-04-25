#ifndef ROADOVERMANAGERFIRSTORDERVERSIONTEMPROADINT32_H
#define ROADOVERMANAGERFIRSTORDERVERSIONTEMPROADINT32_H

#include <memory>


#include "ROADoverManagerFirstOrderVersion.h"
#include "EndianType.h"

namespace ROADdecoder
{
    namespace ROADover
    {
        class ROADoverManagerFirstOrderVersionTempROADInt32 : public ROADoverManagerFirstOrderVersion
        {

            private: std::unique_ptr<ROADInt32> _preListeningInt32Data;

            public: ROADoverManagerFirstOrderVersionTempROADInt32(ROADover* aRoadOver,
                                                                  ROADoverDecodingOptionsFirstOrderVersion* aOptions,
                                                                  Endian::EndianType aEndianType);

            public: ROADdecoder::ROADover::Result decode();

            protected: PlatformDependencies::ROADInt32 readPrelisteningDataStream(PtrROADInt32 aPtrPreListeningDoubleData);
        };
    }
}

#endif // ROADOVERMANAGERFIRSTORDERVERSIONTEMPROADINT32_H
