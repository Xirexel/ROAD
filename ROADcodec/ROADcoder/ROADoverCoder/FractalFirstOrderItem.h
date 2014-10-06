#ifndef __ROADcoder__ROADoverCoder__FractalFirstOrderItem_h__
#define __ROADcoder__ROADoverCoder__FractalFirstOrderItem_h__

#include "../ROADCoder/IFractalFirstOrderItem.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
		class IFractalFirstOrderItem;
	}
	namespace ROADoverCoder
	{
		class FractalFirstOrderItem;
	}
}

namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class FractalFirstOrderItem: public ROADcoder::ROADCoder::IFractalFirstOrderItem
		{
			private: double _aver;
			private: bool _isInversDirection;
			private: unsigned int _length;
			private: unsigned int _domainOffset;
			private: double _scale;
			private: unsigned int _position;

			public: void setAver(double aValue);

			public: void setIsInversDirection(bool aValue);

			public: void setLength(unsigned int aValue);

			public: void setDomainOffset(unsigned int aValue);

			public: void setScale(double aValue);

			public: void setPosition(unsigned int aValue);

			public: double getAver();

			public: bool isIsInversDirection();

			public: unsigned int getLength();

			public: unsigned int getDomainOffset();

			public: double getScale();

			public: unsigned int getPosition();
		};
	}
}

#endif
