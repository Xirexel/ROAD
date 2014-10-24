#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROAD_Encoder_h__
#define __ROAD_Encoder_h__

#include "FractalEncoder.h"
#include "ROADEncodingOptions.h"

namespace ROADEncoding
{
	class FractalEncoder;
	class ROADEncodingOptions;
    class IROADDataContainer;
	class ROAD_Encoder;
}

namespace ROADEncoding
{
    class ROADCODERSHARED_EXPORT ROAD_Encoder
    {
        public: ROADEncoding::FractalEncoder _fractalEncoder;

        public: ROAD_Encoder(ROADEncoding::ROADEncodingOptions aOptions);

        public: virtual ~ROAD_Encoder();

        public: ROADEncoding::IROADDataContainer* doEncoding(double* aData);
	};
}

#endif
