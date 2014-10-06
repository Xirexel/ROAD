#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __ROADdecoder__ROADover__FractalItem_h__
#define __ROADdecoder__ROADover__FractalItem_h__

 #include "../ROAD/IFractalFirstOrderItem.h"

namespace ROADdecoder
{
	namespace ROAD
	{
		class IFractalItem;
	}
	namespace ROADover
	{
        class FractalFirstOrderItem;
	}
}

namespace ROADdecoder
{
	namespace ROADover
	{
        class FractalFirstOrderItem: public ROADdecoder::ROAD::IFractalFirstOrderItem
		{
			private: double _aver;
			private: unsigned int _length;
			private: bool _inversDirection;
			private: unsigned int _domainOffset;
			private: double _scale;
			private: unsigned int _position;

            public: FractalFirstOrderItem();

			public: double getAver();

			public: unsigned int getLength();

			public: bool isInversDirection();

			public: unsigned int getDomainOffset();

			public: double getScale();

			public: unsigned int getPosition();

			public: void setAver(double aAver);

			public: void setLength(unsigned int aLength);

			public: void setInversDirection(bool aInversDirection);

			public: void setDomainOffset(unsigned int aDomainOffset);

			public: void setScale(double aScale);

			public: void setPosition(unsigned int aPosition);
		};
	}
}

#endif
