#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __DataBuffer_h__
#define __DataBuffer_h__

namespace FractalDecoding
{
	class DataBuffer;
}

namespace FractalDecoding
{
	class DataBuffer
	{
		private: double* _firstChannelData;
		private: double* _secondChannelData;
		private: unsigned int _length;

		public: DataBuffer(unsigned int aLength);

        public: virtual ~DataBuffer();

		public: double* getFirstChannelData();

		public: double* getSecondChannelData();

		public: unsigned int getLength();
	};
}

#endif
