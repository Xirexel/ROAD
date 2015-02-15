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

    using namespace PlatformDependencies;
        class FractalFirstOrderItem: public ROADdecoder::ROAD::IFractalFirstOrderItem
		{
            private: ROADReal _aver;
            private: ROADUInt32 _length;
            private: ROADBool _inversDirection;
            private: ROADUInt32 _domainOffset;
            private: ROADReal _scale;
            private: ROADUInt32 _position;

            public: FractalFirstOrderItem();

            public: ROADReal getAver();

            public: ROADUInt32 getLength();

            public: ROADBool isInversDirection();

            public: ROADUInt32 getDomainOffset();

            public: ROADReal getScale();

            public: ROADUInt32 getPosition();

            public: void setAver(ROADReal aAver);

            public: void setLength(ROADUInt32 aLength);

            public: void setInversDirection(ROADBool aInversDirection);

            public: void setDomainOffset(ROADUInt32 aDomainOffset);

            public: void setScale(ROADReal aScale);

            public: void setPosition(ROADUInt32 aPosition);
		};
	}
}

#endif
