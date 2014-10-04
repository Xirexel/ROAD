#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __SuperFrameFractaItemCollection_h__
#define __SuperFrameFractaItemCollection_h__

#include "FractalItemContainer.h"
// #include "IFractalDataContainer.h"
// #include "IFractalItemContainer.h"

namespace FractalDecoding
{
	class FractalItemContainer;
	class IFractalDataContainer;
	class IFractalItemContainer;
	class SuperFrameFractaItemCollection;
}

namespace FractalDecoding
{
	class SuperFrameFractaItemCollection
	{
		private: unsigned int _length;
		public: std::vector<FractalDecoding::FractalItemContainer*> _fractalItemCollections;

        public: SuperFrameFractaItemCollection(unsigned int aSuperFrameLength, unsigned int aMaxFrameLength, unsigned int aFrameSampleLength);

		public: void populate(FractalDecoding::IFractalDataContainer* aFractalDataContainer);

        public: virtual ~SuperFrameFractaItemCollection();

		public: FractalDecoding::IFractalItemContainer* getIFractalItemContainer(unsigned int aIndex);
	};
}

#endif
