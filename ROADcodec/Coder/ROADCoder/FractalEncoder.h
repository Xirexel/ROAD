#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __FractalEncoder_h__
#define __FractalEncoder_h__

#include "ROADEncodingOptions.h"
#include "SuperFrameFractalItemCollection.h"
#include "DomainPool.h"
// #include "IFractalDataContainer.h"
// #include "IFrameFractalItemCollection.h"

namespace ROADEncoding
{
    class ROADEncodingOptions;
	class SuperFrameFractalItemCollection;
	class DomainPool;
	class IFractalDataContainer;
	class IFrameFractalItemCollection;
	class FractalEncoder;
}

namespace ROADEncoding
{
	class FractalEncoder
	{
        private: ROADEncoding::ROADEncodingOptions _options;
        public: std::vector<ROADEncoding::SuperFrameFractalItemCollection*> _superFrameFractalItemCollections;
        public: std::vector<ROADEncoding::DomainPool*> _domainPools;

        public: ROADEncoding::IFractalDataContainer* encode(double* aData);

        private: void silenceMatch(double* aData, unsigned int aSilenceSampleLength, ROADEncoding::IFrameFractalItemCollection* aPtrFrameFractalItemCollection);

        private: void rangeMatch(double* aData, unsigned int aRangeLength, unsigned int aDeepthIndex, ROADEncoding::IFrameFractalItemCollection* aPtrFrameFractalItemCollection);

        private: double computeSumValue(double* aData, unsigned int aLength);

		private: double computeDeviationValue(double* aData, unsigned int aLength, double aAverValue);

		private: void populateDomainPools(double* aData);

        public: FractalEncoder(ROADEncoding::ROADEncodingOptions aOptions);

        public: virtual ~FractalEncoder();

        private: double computeAlpha(const double *aDataRang, const double* aDataDomain, unsigned int aLength, double aSumRang, double aSumDomain);
	};
}

#endif
