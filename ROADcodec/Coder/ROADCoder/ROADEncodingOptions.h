#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "roadcoder_global.h"

#ifndef __ROADEncodingOptions_h__
#define __ROADEncodingOptions_h__

namespace ROADEncoding
{
	class ROADEncodingOptions;
}

namespace ROADEncoding
{
    class ROADCODERSHARED_EXPORT ROADEncodingOptions
	{
		private: unsigned int _frameSampleLength;
		private: unsigned int _superFrameLength;
		private: unsigned int _rangeTopSampleLength;
		private: unsigned int _amountRangeLevels;
        private: unsigned int _domainShift;
		private: double _silenceThreshold;
		private: double _rangeThreshold;

		public: void setFrameSampleLength(unsigned int aFrameSampleLength);

		public: unsigned int getFrameSampleLength();

		public: void setSuperFrameLength(unsigned int aSuperFrameLength);

		public: unsigned int getSuperFrameLength();

		public: void setRangeTopSampleLength(unsigned int aRangeTopSampleLength);

		public: unsigned int getRangeTopSampleLength();

		public: void setAmountRangeLevels(unsigned int aAmountRangeLevels);

		public: unsigned int getAmountRangeLevels();

		public: void setDomainShift(unsigned int aDomainShift);

        public: unsigned int getDomainShift();

		public: void setSilenceThreshold(double aSilenceThreshold);

		public: double getSilenceThreshold();

		public: void setRangeThreshold(double aRangeThreshold);

		public: double getRangeThreshold();
	};
}

#endif
