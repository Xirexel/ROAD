#include "roadovercoderoptions.h"


ROADoverCoderOptions::ROADoverCoderOptions()
    : _typeROADFormat(EXPEREMENTAL),
      _frameSampleLength(2048),
      _superFrameLength(10),
      _maxSampleLengthRang(32),
      _minSampleLengthRang(4),
      _relativeDomainShift(1),
      _typeMixingChannelsMode(L_PLUS_R)
{

}

ROADoverCoderOptions::ROADoverCoderOptions(TypeROADFormat typeROADFormat,
                     quint32 superFrameLength,
                     quint32 minSampleLengthRang,
                     quint32 relativeDomainShift,
                     TypeMixingChannelsMode typeMixingChannelsMode)
    : _typeROADFormat(typeROADFormat),
      _frameSampleLength(2048),
      _superFrameLength(superFrameLength),
      _maxSampleLengthRang(32),
      _minSampleLengthRang(minSampleLengthRang),
      _relativeDomainShift(relativeDomainShift),
      _typeMixingChannelsMode(typeMixingChannelsMode)
{

}


ROADoverCoderOptions::TypeROADFormat ROADoverCoderOptions::getTypeROADFormat()
{
    return this->_typeROADFormat;
}

quint32 ROADoverCoderOptions::getFrameSampleLength()
{
    return this->_frameSampleLength;
}

quint32 ROADoverCoderOptions::getSuperFrameLength()
{
    return this->_superFrameLength;
}

quint32 ROADoverCoderOptions::getMaxSampleLengthRang()
{
    return this->_maxSampleLengthRang;
}

quint32 ROADoverCoderOptions::getMinSampleLengthRang()
{
    return this->_minSampleLengthRang;
}

quint32 ROADoverCoderOptions::getRelativeDomainShift()
{
    return this->_relativeDomainShift;
}

ROADoverCoderOptions::TypeMixingChannelsMode ROADoverCoderOptions::getTypeMixingChannelsMode()
{
    return this->_typeMixingChannelsMode;
}
