#ifndef __ROADdecoder__ROADover__FractalAverItem_h__
#define __ROADdecoder__ROADover__FractalAverItem_h__

#include "../ROAD/IFractalAverItem.h"


namespace ROADdecoder
{
	namespace ROADover
	{

    using namespace PlatformDependencies;
		class FractalAverItem: public ROADdecoder::ROAD::IFractalAverItem
		{
            private: ROADReal _aver;
            private: ROADUInt32 _length;
            private: ROADUInt8 _fractalItemIndex;
            private: ROADUInt32 _position;

            public: ROADReal getAver();

            public: ROADUInt32 getLength();

            public: ROADUInt32 getPosition();

            public: void setAver(ROADReal aAver);

            public: void setLength(ROADUInt32 aLength);

            public: void setFractalItemIndex(ROADUInt8 aFractalItemIndex);

            public: ROADUInt8 getFractalItemIndex();

            public: void setPosition(ROADUInt32 aPosition);
		};
	}
}

#endif
