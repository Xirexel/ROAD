#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __SuperFrameFractalItemCollection_h__
#define __SuperFrameFractalItemCollection_h__

#include "FrameFractalItemCollection.h"
// #include "FractalDataContainer.h"
// #include "IFrameFractalItemCollection.h"
// #include "IFractalDataContainer.h"

namespace ROADEncoding
{
	class FrameFractalItemCollection;
	class FractalDataContainer;
	class IFrameFractalItemCollection;
	class IROADDataContainer;
	class SuperFrameFractalItemCollection;
}

namespace ROADEncoding
{
	class SuperFrameFractalItemCollection
	{
		private: unsigned int _size;
        public: std::vector<ROADEncoding::FrameFractalItemCollection*> _frameFractalItemCollections;
        public: ROADEncoding::FractalDataContainer* _fractalDataContainer;

		public: SuperFrameFractalItemCollection(unsigned int aFrameFractalItemCollectionSize, unsigned int aSize);

        public: virtual ~SuperFrameFractalItemCollection();

        public: ROADEncoding::IFrameFractalItemCollection* getIFrameFractalItemCollection(unsigned int aIndex);

        public: ROADEncoding::IROADDataContainer* getIFractalDataContainer();

		public: unsigned int getSize();
	};
}

#endif
