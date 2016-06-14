#ifndef __ROADcoder__ROADoverCoder__FractalAverItem_h__
#define __ROADcoder__ROADoverCoder__FractalAverItem_h__

#include "../ROADCoder/IFractalAverItem.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{    
    using namespace PlatformDependencies;

    // class for storing prelistening data
		class FractalAverItem: public ROADcoder::ROADCoder::IFractalAverItem
		{
            private: ROADReal _aver;
            private: ROADUInt32 _length;
            private: ROADUInt32 _index;

            public: void setAver(ROADReal aValue);

            public: void setLength(ROADUInt32 aValue);

            public: void setIndex(ROADUInt32 aValue);

            public: ROADReal getAver();

            public: ROADUInt32 getLength();

            public: ROADUInt32 getIndex();
		};
	}
}

#endif
