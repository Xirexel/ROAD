#include <string>
#include <vector>
#include <exception>
using namespace std;

#ifndef __Domain_h__
#define __Domain_h__

 #include "IDomain.h"

namespace ROADEncoding
{
	class IDomain;
	class Domain;
}

namespace ROADEncoding
{
    class Domain: public ROADEncoding::IDomain
	{
		private: double* _dataForwardDirection;
		private: double* _dataBackDirection;
		private: double _aver;
		private: double _sum;
		private: double _beta;
        private: unsigned int _length;


		public: Domain(unsigned int aLength);

        public: virtual ~Domain();

        public: const double* getForwardDirectionData();

        public: const double* getBackDirectionData();

		public: void populate(double* aData, unsigned int aDoubleLength);

		public: double getAver();

		public: double getSum();

		public: double getBeta();
	};
}

#endif
