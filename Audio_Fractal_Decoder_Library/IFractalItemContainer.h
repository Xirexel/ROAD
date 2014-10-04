#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IFractalItemContainer_h__
#define __IFractalItemContainer_h__

// #include "IFractalItem.h"

namespace FractalDecoding
{
	class IFractalItem;
	class IFractalItemContainer;
}

namespace FractalDecoding
{
	class IFractalItemContainer
	{

		public: virtual FractalDecoding::IFractalItem* getIFractalItem(unsigned int aIndex) = 0;

		public: virtual unsigned int getCount() = 0;

        public: virtual ~IFractalItemContainer(){}
	};
}

#endif
