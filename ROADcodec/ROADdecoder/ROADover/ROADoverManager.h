#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__ROADoverManager_h__
#define __ROADdecoder__ROADover__ROADoverManager_h__

#include "../ROAD/IROADFractalBuilder.h"
#include "RawDataBuffer.h"
#include "FractalItemContainer.h"
#include "IROADoverManager.h"


namespace ROADdecoder
{
	namespace ROAD
	{
		class IROADFractalBuilder;
	}
	namespace ROADover
	{
		class ROADover;
		class RawDataBuffer;
		class FractalItemContainer;
		class IROADoverManager;
		class ROADoverManager;
        class IROADoverDecodingOptions;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
		class ROADoverManager: public ROADdecoder::ROADover::IROADoverManager
		{
			protected: ROADdecoder::ROADover::ROADover* _roadOver;
            protected: ROADdecoder::ROADover::RawDataBuffer _channelsDataBuffer;
            protected: unsigned char* _bufferROADdata;

			public: std::vector<ROADdecoder::ROAD::IROADFractalBuilder*> _fractalBuilderCollection;
			public: std::vector<ROADdecoder::ROADover::FractalItemContainer*> _fractalItemContainerCollection;

            public: ROADoverManager(ROADdecoder::ROADover::ROADover* aRoadOver, unsigned int aCount, unsigned int aSampleLength, unsigned int aSuperFrameLength);

            public: virtual ~ROADoverManager();
		};
	}
}

#endif
