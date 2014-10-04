#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IFractalItem_h__
#define __IFractalItem_h__

namespace FractalEncoding
{
	class IFractalItem;
}

namespace FractalEncoding
{
	class IFractalItem
	{

		public: virtual void setAver(double aValue) = 0;

		public: virtual void setDomain(unsigned int aValue) = 0;

		public: virtual void setScale(float aValue) = 0;

		public: virtual void setIndex(unsigned int aValue) = 0;

		public: virtual void setDirection(bool aValue) = 0;

		public: virtual void setSilence(bool aValue) = 0;

        public: virtual ~IFractalItem(){}
	};
}

#endif
