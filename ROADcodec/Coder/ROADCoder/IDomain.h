#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __IDomain_h__
#define __IDomain_h__

namespace ROADEncoding
{
	class IDomain;
}

namespace ROADEncoding
{
	class IDomain
	{

        public: virtual const double* getForwardDirectionData() = 0;

        public: virtual const double* getBackDirectionData() = 0;

        public: virtual ~IDomain(){}

		public: virtual double getAver() = 0;

		public: virtual double getSum() = 0;

		public: virtual double getBeta() = 0;
	};
}

#endif
