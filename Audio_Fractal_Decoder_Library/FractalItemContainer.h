#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FractalItemContainer_h__
#define __FractalItemContainer_h__

#include "FractalItem.h"
// #include "IFractalItem.h"
 #include "IFractalItemContainer.h"

namespace FractalDecoding
{
	class FractalItem;
	class IFractalItem;
	class IFractalItemContainer;
	class FractalItemContainer;
}

namespace FractalDecoding
{
	class FractalItemContainer: public FractalDecoding::IFractalItemContainer
	{
		private: unsigned int _count;
		public: std::vector<FractalDecoding::FractalItem*> _fractalItemCollecrion;

		public: FractalDecoding::IFractalItem* getIFractalItem(unsigned int aIndex);

		public: unsigned int getCount();

		public: void reset();

		public: FractalDecoding::FractalItem* getNextFractalItem();

        public: FractalItemContainer(unsigned int aLength);

        public: virtual ~FractalItemContainer();
	};
}

#endif
