#ifndef __ROADcoder__ROADCoder__Domain_h__
#define __ROADcoder__ROADCoder__Domain_h__

namespace ROADcoder
{
	namespace ROADCoder
	{
		class Domain;
	}
}

namespace ROADcoder
{
	namespace ROADCoder
	{
		class Domain
		{
            private: double* _dataForwardDirection;
            private: double* _dataBackDirection;
			private: double _aver;
			private: double _sum;
			private: double _beta;
			private: unsigned int _length;
            private: double _tempValue;

			public: Domain(unsigned int aLength);

			public: void populate(double* aData, unsigned int aDoubleLength);

            public: virtual ~Domain();

            public: const double* getForwardDirectionData();

            public: const double* getBackDirectionData();

			public: double getAver();

			public: double getSum();

			public: double getBeta();

			public: unsigned int getLength();
		};
	}
}

#endif
