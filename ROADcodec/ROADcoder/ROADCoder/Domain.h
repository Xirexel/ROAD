#ifndef __ROADcoder__ROADCoder__Domain_h__
#define __ROADcoder__ROADCoder__Domain_h__

#include "platformdependencies.h"
#include "memorydefine.h"

namespace ROADcoder
{
	namespace ROADCoder
	{
    using namespace PlatformDependencies;

        // class for storing one domain subsection.
		class Domain
		{
            private: UniqueMassive_ptr<ROADReal> _dataForwardDirection;
            private: UniqueMassive_ptr<ROADReal> _dataBackDirection;
            private: ROADReal _aver;
            private: ROADReal _sum;
            private: ROADReal _beta;
            private: ROADSize _length;
            private: ROADReal _tempValue;

            public: Domain(ROADSize aLength);

            public: void populate(PtrROADReal aData, ROADSize aDoubleLength);

            public: virtual ~Domain();

            public: PtrROADReal getForwardDirectionData();

            public: PtrROADReal getBackDirectionData();

            public: ROADReal getAver();

            public: ROADReal getSum();

            public: ROADReal getBeta();

            public: ROADSize getLength();
		};
	}
}

#endif
