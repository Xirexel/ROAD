#ifndef ROADSEEKPOINT_H
#define ROADSEEKPOINT_H


#include "platformdependencies.h"


#include "roadovercoder_global.h"

namespace ROADcoder
{
    namespace ROADoverCoder
    {
        class ROADOVERCODERSHARED_EXPORT ROADSeekPoint
        {
            private: PlatformDependencies::ROADByte _superFrameSize;

            public: ROADSeekPoint(PlatformDependencies::ROADByte aSuperFrameSize)
                :_superFrameSize(aSuperFrameSize){}

            public: PlatformDependencies::ROADByte getSuperFrameSize()
            {
                return this->_superFrameSize;
            }
        };
    }
}

#endif // ROADSEEKPOINT_H
