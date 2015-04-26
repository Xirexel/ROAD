#ifndef __ROADdecoder__ROADover__SIDEChannelsMixing_h__
#define __ROADdecoder__ROADover__SIDEChannelsMixing_h__


#include "IChannelsMixing.h"

namespace ROADdecoder
{
	namespace ROADover
	{
        class IRawDataBuffer;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
        template<typename ROADDecodedSampleType>
        class SIDEChannelsMixing: public ROADdecoder::ROADover::IChannelsMixing<ROADDecodedSampleType>
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
                        tempValueL = *lptrMIDDouble + *lptrSIDEDouble;

                        tempValueR = *lptrMIDDouble - *lptrSIDEDouble;


                        *lptrMIDDouble = tempValueR;

                        *lptrSIDEDouble = tempValueL;


                        lptrMIDDouble++;

                        lptrSIDEDouble++;
                    }

                }

            }

		};
	}
}

#endif
