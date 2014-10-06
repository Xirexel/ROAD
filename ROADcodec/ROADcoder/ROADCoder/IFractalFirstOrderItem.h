#ifndef __ROADcoder__ROADCoder__IFractalItem_h__
#define __ROADcoder__ROADCoder__IFractalItem_h__

namespace ROADcoder
{
	namespace ROADCoder
	{
        class IFractalFirstOrderItem;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
        class IFractalFirstOrderItem
		{

			public: virtual void setAver(double aValue) = 0;

			public: virtual void setLength(unsigned int aValue) = 0;

			public: virtual void setIsInversDirection(bool aValue) = 0;

			public: virtual void setDomainOffset(unsigned int aValue) = 0;

			public: virtual void setScale(double aValue) = 0;

            public: virtual void setPosition(unsigned int aValue) = 0;

            public: virtual ~IFractalFirstOrderItem(){}
		};
	}
}

#endif
