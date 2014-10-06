#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FrameFractalItemCollection_h__
#define __FrameFractalItemCollection_h__

#include "FractalItem.h"
// #include "IFractalItem.h"
 #include "IFrameFractalItemCollection.h"

namespace FractalEncoding
{
	class FractalItem;
	class IFractalItem;
	class IFrameFractalItemCollection;
	class FrameFractalItemCollection;
}

namespace FractalEncoding
{
	class FrameFractalItemCollection: public FractalEncoding::IFrameFractalItemCollection
	{
		private: unsigned int _count;
		public: std::vector<FractalEncoding::FractalItem*> _fractalItemCollection;

		public: FractalEncoding::IFractalItem* getNextIFractalItem();

		public: FrameFractalItemCollection(unsigned int aSize);

        public: virtual ~FrameFractalItemCollection();

		public: FractalEncoding::FractalItem* getFractalItem(unsigned int aIndex);

		public: void resetCount();

		public: unsigned int getCount();
	};
}

#endif
