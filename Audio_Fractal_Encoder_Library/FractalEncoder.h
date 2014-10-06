#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FractalEncoder_h__
#define __FractalEncoder_h__

#include "FractalEncodingOptions.h"
#include "SuperFrameFractalItemCollection.h"
#include "DomainPool.h"
// #include "IFractalDataContainer.h"
// #include "IFrameFractalItemCollection.h"

namespace FractalEncoding
{
	class FractalEncodingOptions;
	class SuperFrameFractalItemCollection;
	class DomainPool;
	class IFractalDataContainer;
	class IFrameFractalItemCollection;
	class FractalEncoder;
}

namespace FractalEncoding
{
	class FractalEncoder
	{
		private: FractalEncoding::FractalEncodingOptions _options;
		public: std::vector<FractalEncoding::SuperFrameFractalItemCollection*> _superFrameFractalItemCollections;
		public: std::vector<FractalEncoding::DomainPool*> _domainPools;

		public: FractalEncoding::IFractalDataContainer* encode(double* aData);

		private: void silenceMatch(double* aData, unsigned int aSilenceSampleLength, FractalEncoding::IFrameFractalItemCollection* aPtrFrameFractalItemCollection);

		private: void rangeMatch(double* aData, unsigned int aRangeLength, unsigned int aDeepthIndex, FractalEncoding::IFrameFractalItemCollection* aPtrFrameFractalItemCollection);

        private: double computeSumValue(double* aData, unsigned int aLength);

		private: double computeDeviationValue(double* aData, unsigned int aLength, double aAverValue);

		private: void populateDomainPools(double* aData);

		public: FractalEncoder(FractalEncoding::FractalEncodingOptions aOptions);

        public: virtual ~FractalEncoder();

        private: double computeAlpha(const double *aDataRang, const double* aDataDomain, unsigned int aLength, double aSumRang, double aSumDomain);
	};
}

#endif
