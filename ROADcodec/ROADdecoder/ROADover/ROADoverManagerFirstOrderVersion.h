#ifndef ROADOVERMANAGERFIRSTORDER_H
#define ROADOVERMANAGERFIRSTORDER_H



#include <vector>
#include <memory>
// #include "ROADdecoder/ROADover/ROADover.h"
// #include "ROADdecoder/ROADover/ROADoverDecodingOptionsExperemental.h"
#include "../ROAD/IROADFractalFirstOrderBuilder.h"
#include "Result.h"
#include "ROADoverManager.h"

namespace ROADdecoder
{
    namespace ROADover
    {
        class ROADover;
        class ROADoverDecodingOptionsFirstOrderVersion;
        class FractalFirstOrderItemSuperFrameContainer;
    }

    namespace Driver
    {
        class IDataReadDriver;
    }
}

namespace ROADdecoder
{
    namespace ROADover
    {

        class ROADoverManagerFirstOrderVersion: public ROADdecoder::ROADover::ROADoverManager
        {
            private: std::unique_ptr<ROADdecoder::ROAD::IROADFractalFirstOrderBuilder> _fractalBuilder;
            private: std::vector<ROADdecoder::ROADover::FractalFirstOrderItemSuperFrameContainer*> _fractalItemSuperFrameContainer;

            protected: ROADdecoder::ROADover::ROADoverDecodingOptionsFirstOrderVersion* _options;

            private: std::unique_ptr<ROADByte> _preListeningData;

            private: std::unique_ptr<ROADReal> _preListeningDoubleData;

            public: ROADoverManagerFirstOrderVersion(ROADdecoder::ROADover::ROADover* aRoadOver, ROADdecoder::ROADover::ROADoverDecodingOptionsFirstOrderVersion* aOptions);

            public: ROADdecoder::ROADover::Result decode();

            public: virtual ~ROADoverManagerFirstOrderVersion();

            private: ROADBool readIndekcesPack(ROADdecoder::Driver::IDataReadDriver *aIDataReadDriver);
        };
    }
}

#endif // ROADOVERMANAGERFIRSTORDER_H
