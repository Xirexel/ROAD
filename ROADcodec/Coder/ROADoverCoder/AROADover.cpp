#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "AROADover.h"
#include "IMixingChannels.h"
#include "CRCProcessor.h"
#include "EntropyCompression.h"
#include "ROADManager.h"
#include "RawDataBuffer.h"
#include "CharDataContainer.h"
#include "Result.h"
#include "IRawDataBuffer.h"
#include "ROADoverEncodingOptions.h"
#include "LplusRMixingChannels.h"
#include "LminusRMixingChannels.h"
#include "NoneMixingChannels.h"
#include "IDoubleDataContainer.h"
#include "IUCharDataContainer.h"





ROADoverEncoding::Result ROADoverEncoding::AROADover::doOneStepEncoding()
{
    Result result = this->readRawData(&_buffer);

    _mixingChannels->compute(&_buffer);

    IROADDataCollection* lptrIROADDataCollection = _manager->doEncoding(&_buffer);

    char * lptrChar = _rawCharDataContainer.getData();

    unsigned int lCharArrayLength = 0;

    for(decltype(lptrIROADDataCollection->getCount()) lIndex = 0;
        lIndex < lptrIROADDataCollection->getCount();
        ++lIndex)
    {
        ROADEncoding::IUCharDataContainer* lptrIUCharDataContainer = lptrIROADDataCollection->getIROADDataContainer(lIndex)->getIndex();

        memcpy(lptrChar + lCharArrayLength, lptrIUCharDataContainer->getData(), lptrIUCharDataContainer->getCount());

        lCharArrayLength += lptrIUCharDataContainer->getCount();
    }


    for(decltype(lptrIROADDataCollection->getCount()) lIndex = 1;
        lIndex < lptrIROADDataCollection->getCount();
        ++lIndex)
    {
        ROADEncoding::IDoubleDataContainer* lptrIDoubleDataContainer = lptrIROADDataCollection->getIROADDataContainer(lIndex)->getAver();

        lCharArrayLength += convertDoubleArrayToByteArray(lptrIDoubleDataContainer->getData(),
                                                             lptrIDoubleDataContainer->getCount(),
                                                             lptrChar + lCharArrayLength);

    }



    for(decltype(lptrIROADDataCollection->getCount()) lIndex = 0;
        lIndex < lptrIROADDataCollection->getCount();
        ++lIndex)
    {
        ROADEncoding::IUCharDataContainer* lptrIUCharDataContainer = lptrIROADDataCollection->getIROADDataContainer(lIndex)->getDomain();

        memcpy(lptrChar + lCharArrayLength, lptrIUCharDataContainer->getData(), lptrIUCharDataContainer->getCount());

        lCharArrayLength += lptrIUCharDataContainer->getCount();
    }



    for(decltype(lptrIROADDataCollection->getCount()) lIndex = 0;
        lIndex < lptrIROADDataCollection->getCount();
        ++lIndex)
    {
        ROADEncoding::IUCharDataContainer* lptrIUCharDataContainer = lptrIROADDataCollection->getIROADDataContainer(lIndex)->getScale();

        memcpy(lptrChar + lCharArrayLength, lptrIUCharDataContainer->getData(), lptrIUCharDataContainer->getCount());

        lCharArrayLength += lptrIUCharDataContainer->getCount();
    }



    ROADEncoding::IROADDataContainer* lptrAverChannelFractalDataConatainer = lptrIROADDataCollection->getIROADDataContainer(0);

    ROADEncoding::IDoubleDataContainer *lptrAver = lptrAverChannelFractalDataConatainer->getExtendAver();

    writePrelistening(lptrAver->getData(), lptrAver->getCount());

    writeROADdata(lptrChar, lCharArrayLength, 0, 0);

    return result;
}

ROADoverEncoding::AROADover::AROADover(ROADoverEncoding::ROADoverEncodingOptions aOptions)
    : _manager(new ROADManager(aOptions)),
      _buffer(RawDataBuffer(aOptions.getChannels(), aOptions.getFrameSampleLength() * aOptions.getSuperframeLength())),
      _rawCharDataContainer(CharDataContainer(aOptions.getFrameSampleLength() *
                                              aOptions.getSuperframeLength() *
                                              (aOptions.getBitsPerSample() >> 3))),
      _formatContainer(FormatContainer(aOptions.getFormat(),
                                       aOptions.getSuperframeLength(),
                                       aOptions.getFrameSampleLength()/aOptions.getShortestRangSampleLength(),
                                       aOptions.getDomainShift(),
                                       aOptions.getChannels(),
                                       aOptions.getMixingChannelsMode(),
                                       aOptions.getEncryptionFromat()))
{
    switch(aOptions.getMixingChannelsMode())
    {
    case LplusR:
        _mixingChannels = new LplusRMixingChannels;
        break;

    case LminusR:
        _mixingChannels = new LminusRMixingChannels;
        break;

    case NONE:
    default:
        _mixingChannels = new NoneMixingChannels;
        break;
    }

}

ROADoverEncoding::AROADover::~AROADover()
{
    delete _mixingChannels;

    delete _manager;
}

ROADoverEncoding::ICharDataContainer* ROADoverEncoding::AROADover::getFormatICharDataContainer()
{
    return _formatContainer.getFormatICharDataContainer();
}
