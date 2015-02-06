#ifndef __ROADcoder__ROADoverCoder__FractalFormatRawDataContainer_h__
#define __ROADcoder__ROADoverCoder__FractalFormatRawDataContainer_h__


#include <memory>


namespace ROADcoder
{
	namespace ROADoverCoder
	{
		class FractalFormatRawDataContainer
		{
            private: std::unique_ptr<unsigned char> _data;
            private: unsigned int _length;

            public: FractalFormatRawDataContainer(std::unique_ptr<unsigned char> &aData, unsigned int aLength);

            public: unsigned char* getData() const;

            public: unsigned int getLength() const;



		};
	}
}

#endif
