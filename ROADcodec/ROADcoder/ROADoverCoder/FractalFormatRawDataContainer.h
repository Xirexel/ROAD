#ifndef __ROADcoder__ROADoverCoder__FractalFormatRawDataContainer_h__
#define __ROADcoder__ROADoverCoder__FractalFormatRawDataContainer_h__


#include <memory>


#include "platformdependencies.h"

namespace ROADcoder
{
	namespace ROADoverCoder
	{
    using namespace PlatformDependencies;

		class FractalFormatRawDataContainer
		{
            private: SharedMassive_ptr<ROADByte> _data;
            private: ROADUInt32 _length;

        public: FractalFormatRawDataContainer(SharedMassive_ptr<ROADByte> &aData, ROADUInt32 aLength);

            public: PtrROADByte getData() const;

            public: ROADUInt32 getLength() const;

		};
	}
}

#endif
