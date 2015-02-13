#ifndef __ROADcoder__ROADCoder__Domain_h__
#define __ROADcoder__ROADCoder__Domain_h__

#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
    using namespace PlatformDependencies;

		class Domain
		{
            private: PtrROADReal _dataForwardDirection;
            private: PtrROADReal _dataBackDirection;
            private: ROADReal _aver;
            private: ROADReal _sum;
            private: ROADReal _beta;
            private: ROADUInt32 _length;
            private: ROADReal _tempValue;

            public: Domain(ROADUInt32 aLength);

            public: void populate(PtrROADReal aData, ROADUInt32 aDoubleLength);

            public: virtual ~Domain();

            public: PtrROADReal getForwardDirectionData();

            public: PtrROADReal getBackDirectionData();

            public: ROADReal getAver();

            public: ROADReal getSum();

            public: ROADReal getBeta();

            public: ROADUInt32 getLength();
		};
	}
}

#endif
