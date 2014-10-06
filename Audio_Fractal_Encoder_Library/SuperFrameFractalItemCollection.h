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

namespace FractalEncoding
{
	class FrameFractalItemCollection;
	class FractalDataContainer;
	class IFrameFractalItemCollection;
	class IFractalDataContainer;
	class SuperFrameFractalItemCollection;
}

namespace FractalEncoding
{
	class SuperFrameFractalItemCollection
	{
		private: unsigned int _size;
		public: std::vector<FractalEncoding::FrameFractalItemCollection*> _frameFractalItemCollections;
		public: FractalEncoding::FractalDataContainer* _fractalDataContainer;

		public: SuperFrameFractalItemCollection(unsigned int aFrameFractalItemCollectionSize, unsigned int aSize);

        public: virtual ~SuperFrameFractalItemCollection();

		public: FractalEncoding::IFrameFractalItemCollection* getIFrameFractalItemCollection(unsigned int aIndex);

		public: FractalEncoding::IFractalDataContainer* getIFractalDataContainer();

		public: unsigned int getSize();
	};
}

#endif
