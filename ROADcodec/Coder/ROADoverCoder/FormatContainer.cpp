#include <string>
#include <string.h> // for memcpy definition
#include <vector>
#include <exception>
using namespace std;

#include "FormatContainer.h"
#include "ROADFormat.h"
#include "MixingChannelsMode.h"
#include "CharDataContainer.h"
#include "ICharDataContainer.h"

ROADoverEncoding::ICharDataContainer* ROADoverEncoding::FormatContainer::getFormatICharDataContainer()
{
    return &_formalCharDataContainer;
}

ROADoverEncoding::FormatContainer::FormatContainer(ROADoverEncoding::ROADFormat aFormat,
                                                   unsigned int aSuperFrameLength,
                                                   unsigned int aFrameRangLength,
                                                   unsigned int aDomainShift,
                                                   unsigned int aOrginalAmountOfChannels,
                                                   ROADoverEncoding::MixingChannelsMode aMixingChannelsMode,
                                                   unsigned int aEncryptionCode)
    : _formalCharDataContainer(ROADoverEncoding::CharDataContainer(8*4))
{
    unsigned short x = 1; /* 0x0001 */

    char * lptrChar =_formalCharDataContainer.getData();

    unsigned int lFormatValue = aFormat;

//    switch(aFormat)
//    {
//    case EXPEREMENTAL:
//        lFormatValue = 0;
//        break;
//    }

    unsigned int lMixingChannelsModeValue = aMixingChannelsMode;

//    switch(aMixingChannelsMode)
//    {
//    case NONE:
//        lMixingChannelsModeValue = 0;
//        break;
//    case LplusR:
//        lMixingChannelsModeValue = 1;
//        break;
//    case LminusR:
//        lMixingChannelsModeValue = 2;
//        break;
//    }

    unsigned int aDomainShiftScale = 2048/aFrameRangLength;

    if(*((unsigned char *) &x) == 0)
    {
        memcpy(lptrChar, &lFormatValue, 4);

        lptrChar+=4;

        memcpy(lptrChar, &aSuperFrameLength, 4);

        lptrChar+=4;

        memcpy(lptrChar, &aFrameRangLength, 4);

        lptrChar+=4;

        memcpy(lptrChar, &aDomainShift, 4);

        lptrChar+=4;

        memcpy(lptrChar, &aDomainShiftScale, 4);

        lptrChar+=4;

        memcpy(lptrChar, &aOrginalAmountOfChannels, 4);

        lptrChar+=4;

        memcpy(lptrChar, &lMixingChannelsModeValue, 4);

        lptrChar+=4;

        memcpy(lptrChar, &aEncryptionCode, 4);
    }
    else
    {

    }

}

