#ifndef __ROADcoder__ROADoverCoder__FractalFirstOrderItem_h__
#define __ROADcoder__ROADoverCoder__FractalFirstOrderItem_h__

#include "../ROADCoder/IFractalFirstOrderItem.h"


namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;

        // First order Fractal data
		class FractalFirstOrderItem: public ROADcoder::ROADCoder::IFractalFirstOrderItem
		{
            private: ROADReal _aver;
            private: ROADBool _isInversDirection;
            private: ROADUInt32 _length;
            private: ROADUInt32 _domainOffset;
            private: ROADReal _scale;
            private: ROADUInt32 _position;

            public: void setAver(ROADReal aValue);

            public: void setIsInversDirection(ROADBool aValue);

            public: void setLength(ROADUInt32 aValue);

            public: void setDomainOffset(ROADUInt32 aValue);

            public: void setScale(ROADReal aValue);

            public: void setPosition(ROADUInt32 aValue);

            public: ROADReal getAver();

            public: ROADBool isIsInversDirection();

            public: ROADUInt32 getLength();

            public: ROADUInt32 getDomainOffset();

            public: ROADReal getScale();

            public: ROADUInt32 getPosition();
		};
	}
}

#endif
