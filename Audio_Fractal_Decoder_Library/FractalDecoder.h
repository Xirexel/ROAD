#include <string>
#include <vector>
#include <list>
#include <exception>
using namespace std;

#ifndef __FractalDecoder_h__
#define __FractalDecoder_h__

#include "FractalDecodingOptions.h"
#include "SuperFrameFractaItemCollection.h"
#include "DomainProcessor.h"
// #include "IFractalDataContainer.h"
// #include "IFractalItemContainer.h"

namespace FractalDecoding
{
	class FractalDecodingOptions;
	class SuperFrameFractaItemCollection;
	class DomainProcessor;
	class IFractalDataContainer;
	class IFractalItemContainer;
	class FractalDecoder;
}

namespace FractalDecoding
{
	class FractalDecoder
	{
		public: FractalDecoding::FractalDecodingOptions _options;
		public: FractalDecoding::SuperFrameFractaItemCollection _superFrameFractalItemCollection;
		public: FractalDecoding::DomainProcessor _domainProcessor;
        private: std::list<unsigned int> _listRN;

		public: FractalDecoder(FractalDecoding::FractalDecodingOptions aOptions);

        public: virtual ~FractalDecoder();

		public: void decode(double* aData, FractalDecoding::IFractalDataContainer* aFractalDataContainer);

		private: void decodeFrame(double* aData, FractalDecoding::IFractalItemContainer* aFractalItemContainer);

		private: int getRNumber();

		private: void setRangeOfRNG(unsigned int aLowBoder, unsigned int aTopBorder);


	};
}

#endif
