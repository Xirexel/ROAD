#ifndef __ROADdecoder__ROADover__NoneChannelsMixing_h__
#define __ROADdecoder__ROADover__NoneChannelsMixing_h__

#include "IChannelsMixing.h"

//namespace ROADdecoder
//{
//	namespace ROADover
//	{
//        class IRawDataBuffer;
//	}
//}

namespace ROADdecoder
{
	namespace ROADover
	{
        template<typename ROADDecodedSampleType>
        class NoneChannelsMixing: public ROADdecoder::ROADover::IChannelsMixing<ROADDecodedSampleType>
        {
            private: typedef ROADDecodedSampleType DecodedSampleType;

            private: DecodedSampleType tempValueL, tempValueR;

            public: void compute(ROADdecoder::ROADover::RawDataBuffer<DecodedSampleType>*)
            {}
		};
	}
}

#endif
