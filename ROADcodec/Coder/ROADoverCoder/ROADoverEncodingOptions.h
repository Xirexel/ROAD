#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADoverEncodingOptions_h__
#define __ROADoverEncodingOptions_h__

#include "MixingChannelsMode.h"

namespace ROADoverEncoding
{
	// enum MixingChannelsMode;
	class ROADoverEncodingOptions;
}

namespace ROADoverEncoding
{
	class ROADoverEncodingOptions
	{
		private: ROADoverEncoding::MixingChannelsMode _mixingChannelsMode;

		public: void setMixingChannelsMode(ROADoverEncoding::MixingChannelsMode aMixingChannelsMode);

		public: ROADoverEncoding::MixingChannelsMode getMixingChannelsMode();
	};
}

#endif
