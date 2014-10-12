#include "modeloptions.h"

 ModelOptions::ModelOptions()
     :  _localROADoverCoderOptions(ROADoverCoderOptions(ROADoverCoderOptions::EXPEREMENTAL,
                                                        2048,
                                                        10,
                                                        32,
                                                        4,
                                                        1,
                                                        ROADoverCoderOptions::L_PLUS_R))
 {

 }

ModelOptions::ModelOptions(ROADoverCoderOptions typeROADFormat,
                           quint32 superFrameLength,
                           quint32 minSampleLengthRang,
                           quint32 relativeDomainShift,
                           ROADoverCoderOptions typeMixingChannelsMode)

    : _localROADoverCoderOptions(ROADoverCoderOptions(typeROADFormat,
                                                        2048,
                                                        superFrameLength,
                                                        32,
                                                        minSampleLengthRang,
                                                        relativeDomainShift,
                                                        typeMixingChannelsMode))
{
}

ROADoverCoderOptions ModelOptions::getROADoverCoderOptions()
{
    return this->_localROADoverCoderOptions;
}
