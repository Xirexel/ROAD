#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FrameFractalItemCollection_h__
#define __FrameFractalItemCollection_h__

#include "FractalItem.h"
// #include "IFractalItem.h"
 #include "IFrameFractalItemCollection.h"

namespace ROADEncoding
{
	class FractalItem;
	class IFractalItem;
	class IFrameFractalItemCollection;
	class FrameFractalItemCollection;
}

namespace ROADEncoding
{
    class FrameFractalItemCollection: public ROADEncoding::IFrameFractalItemCollection
	{
		private: unsigned int _count;
        public: std::vector<ROADEncoding::FractalItem*> _fractalItemCollection;

        public: ROADEncoding::IFractalItem* getNextIFractalItem();

		public: FrameFractalItemCollection(unsigned int aSize);

        public: virtual ~FrameFractalItemCollection();

        public: ROADEncoding::FractalItem* getFractalItem(unsigned int aIndex);

		public: void resetCount();

		public: unsigned int getCount();
	};
}

#endif
