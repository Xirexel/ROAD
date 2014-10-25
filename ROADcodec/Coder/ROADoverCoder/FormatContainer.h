#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FormatContainer_h__
#define __FormatContainer_h__

#include "ROADFormat.h"
#include "MixingChannelsMode.h"
#include "CharDataContainer.h"
// #include "ICharDataContainer.h"

namespace ROADoverEncoding
{
	// enum ROADFormat;
	// enum MixingChannelsMode;
	class CharDataContainer;
	class ICharDataContainer;
	class FormatContainer;
}

namespace ROADoverEncoding
{
	class FormatContainer
	{
		private: ROADoverEncoding::ROADFormat _format;
		private: unsigned int _superFrameLength;
		private: unsigned int _frameRangLength;
		private: unsigned int _domainShift;
		private: unsigned int _domainShiftScale;
		private: unsigned int _originalAmountOfChannels;
		private: ROADoverEncoding::MixingChannelsMode _mixingChannelsMode;
		private: unsigned int _encryptionCode;
		private: ROADoverEncoding::CharDataContainer _formalCharDataContainer;

		public: ROADoverEncoding::ICharDataContainer* getFormatICharDataContainer();

        public: FormatContainer(ROADoverEncoding::ROADFormat aFormat, unsigned int aSuperFrameLength, unsigned int aFrameRangLength, unsigned int aDomainShift, unsigned int aOrginalAmountOfChannels, ROADoverEncoding::MixingChannelsMode aMixingChannelsMode, unsigned int aEncryptionCode);
	};
}

#endif
