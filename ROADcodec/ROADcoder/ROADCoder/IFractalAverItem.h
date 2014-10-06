#ifndef __ROADcoder__ROADCoder__IFractalAverItem_h__
#define __ROADcoder__ROADCoder__IFractalAverItem_h__

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IFractalAverItem;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IFractalAverItem
		{

			public: virtual void setAver(double aValue) = 0;

			public: virtual void setLength(unsigned int aValue) = 0;

            public: virtual void setIndex(unsigned int aValue) = 0;

            public: virtual ~IFractalAverItem(){}
		};
	}
}

#endif
