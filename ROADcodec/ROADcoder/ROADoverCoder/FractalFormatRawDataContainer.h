#ifndef __ROADcoder__ROADoverCoder__FractalFormatRawDataContainer_h__
#define __ROADcoder__ROADoverCoder__FractalFormatRawDataContainer_h__


#include <memory>


namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class FractalFormatRawDataContainer
		{
            private: std::unique_ptr<char> _data;
			private: unsigned int _length;

			public: void setRawData(char* aData, unsigned int aLength);

			public: FractalFormatRawDataContainer();

			public: char* getData();

			public: unsigned int getLength();
		};
	}
}

#endif
