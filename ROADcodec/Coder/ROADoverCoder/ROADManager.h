#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADManager_h__
#define __ROADManager_h__

#include "ROAD_Encoder.h"
#include "ROADDataCollection.h"
#include "ROADoverEncodingOptions.h"
// #include "IROADDataCollection.h"
// #include "IRawDataBuffer.h"

namespace ROADEncoding
{
	class ROAD_Encoder;
}
namespace ROADoverEncoding
{
	class ROADDataCollection;
	class ROADoverEncodingOptions;
	class IROADDataCollection;
	class IRawDataBuffer;
	class ROADManager;
}

namespace ROADoverEncoding
{
	class ROADManager
	{
        private: ROADoverEncoding::ROADDataCollection _roadDataCollection;
		private: std::vector<ROADEncoding::ROAD_Encoder*> _channelEncoders;

		public: ROADManager(ROADoverEncoding::ROADoverEncodingOptions aOptions);

        public: virtual ~ROADManager();

		public: ROADoverEncoding::IROADDataCollection* doEncoding(ROADoverEncoding::IRawDataBuffer* aBuffer);
	};
}

#endif
