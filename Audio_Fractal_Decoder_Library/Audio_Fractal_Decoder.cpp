#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "Audio_Fractal_Decoder.h"
#include "IMixing.h"
#include "IRawDataReader.h"
#include "IRawDataWriter.h"
#include "DataBuffer.h"
#include "FractalDecoder.h"
#include "FractalDataContainer.h"
#include "ReadResult.h"
#include "FractalDecodingOptions.h"
#include "LPlusRMixing.h"
#include "LMinusRMixing.h"
#include "NoneMixing.h"

FractalDecoding::ReadResult FractalDecoding::Audio_Fractal_Decoder::doDecoding() {
    FractalDecoding::ReadResult result = FractalDecoding::ERROR;

    result = _reader->readData(&_firstChannelFractalDataCollection, &_secondChannelFractalDataCollection);

    if(result == FractalDecoding::DONE)
    {
        _firstChannelFractalDecoder.decode(_dataBuffer.getFirstChannelData(), &_firstChannelFractalDataCollection);

        _secondChannelFractalDecoder.decode(_dataBuffer.getSecondChannelData(), &_secondChannelFractalDataCollection);

        this->_mixingChannels->compute(_dataBuffer.getFirstChannelData(), _dataBuffer.getSecondChannelData(), _dataBuffer.getLength());
    }

    _writer->writeData(_dataBuffer.getFirstChannelData(), _dataBuffer.getSecondChannelData(), _dataBuffer.getLength());

    return result;
}

FractalDecoding::Audio_Fractal_Decoder::Audio_Fractal_Decoder(FractalDecoding::IRawDataReader* aReader,
                                                              FractalDecoding::IRawDataWriter* aWriter,
                                                              FractalDecoding::FractalDecodingOptions aOptions)
    : _mixingChannels(nullptr),
      _reader(aReader),
      _writer(aWriter),
      _dataBuffer(FractalDecoding::DataBuffer(aOptions.getSuperFrameLength() *
                                              aOptions.getFrameLength() *
                                              aOptions.getSamplesPerRang())),

      _firstChannelFractalDecoder(FractalDecoding::FractalDecoder(aOptions)),
      _secondChannelFractalDecoder(FractalDecoding::FractalDecoder(aOptions)),
      _firstChannelFractalDataCollection(FractalDecoding::FractalDataContainer(aOptions.getSuperFrameLength() * aOptions.getFrameLength())),
      _secondChannelFractalDataCollection(FractalDecoding::FractalDataContainer(aOptions.getSuperFrameLength() * aOptions.getFrameLength()))

{
    switch(aOptions.getMixingChannelMode())
    {
    case FractalDecoding::LPLUSR:
    default:
        this->_mixingChannels = new LPlusRMixing;
        break;
    case FractalDecoding::LMINUSR:
        this->_mixingChannels = new LMinusRMixing;
        break;
    case FractalDecoding::NONE:
        this->_mixingChannels = new NoneMixing;
        break;

    }



}

FractalDecoding::Audio_Fractal_Decoder::~Audio_Fractal_Decoder()
{
    if(_mixingChannels != nullptr)
        delete _mixingChannels;
}
