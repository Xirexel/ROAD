#ifndef __ROADdecoder__ROADover__MIDChannelsMixing_h__
#define __ROADdecoder__ROADover__MIDChannelsMixing_h__

#include "IChannelsMixing.h"

namespace ROADdecoder
{
	namespace ROADover
	{
        template<typename ROADDecodedSampleType>
        class MIDChannelsMixing: public ROADdecoder::ROADover::IChannelsMixing<ROADDecodedSampleType>
		{
            private: typedef ROADDecodedSampleType DecodedSampleType;

            private: DecodedSampleType tempValueL, tempValueR;

            public: void compute(ROADdecoder::ROADover::RawDataBuffer<DecodedSampleType>* aBuffer)
            {

                auto lchannelsCount = aBuffer->getCount();

                if(lchannelsCount == 1)
                    return;

                if(lchannelsCount == 2)
                {
                    auto lptrMID = aBuffer->getPtrDecodedDataContainer(0);

                    auto lptrSIDE = aBuffer->getPtrDecodedDataContainer(1);

                    auto lsamplesCount = lptrMID->getCount();

                    auto lptrMIDDouble = lptrMID->getData();

                    auto lptrSIDEDouble = lptrSIDE->getData();

                    for(decltype(lsamplesCount) index = 0;
                        index < lsamplesCount;
                        ++index)
                    {
                        auto tempMIDvalue = lptrMIDDouble[index];

                        auto tempSIDEvalue = lptrSIDEDouble[index];

                        tempValueL = tempMIDvalue;

                        tempValueR = tempSIDEvalue;


                        lptrMIDDouble[index] = tempValueL;

                        lptrSIDEDouble[index] = tempValueR;
                    }

                }

            }
		};
	}
}

#endif
