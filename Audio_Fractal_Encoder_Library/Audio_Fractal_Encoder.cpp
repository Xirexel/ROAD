#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "Audio_Fractal_Encoder.h"
#include "IRawDataReader.h"
#include "IRawDataWriter.h"
#include "IMixingChannels.h"
#include "DataBuffer.h"
#include "FractalEncoder.h"
#include "FractalEncodingOptions.h"
#include "ReadResult.h"
#include "LminusRMixing.h"
#include "LplusRMixing.h"
#include "NoneMixing.h"

FractalEncoding::Audio_Fractal_Encoder::Audio_Fractal_Encoder(FractalEncoding::IRawDataReader* aReader,
                                                              FractalEncoding::IRawDataWriter* aWriter,
                                                              FractalEncoding::FractalEncodingOptions aOptions)
    : _reader(aReader),
      _writer(aWriter),
      _mixingChannels(nullptr),
      _buffer(DataBuffer(aOptions.getFrameSampleLength() * aOptions.getSuperFrameLength())),
      _firstFractalEncoder(FractalEncoding::FractalEncoder(aOptions)),
      _secondFractalEncoder(FractalEncoding::FractalEncoder(aOptions))
{
    switch (aOptions.getMixingChannelsMode()) {
    case FractalEncoding::LPLUSR:
    default:
        _mixingChannels = new LplusRMixing();
        break;
    case FractalEncoding::LMINUSR:
        _mixingChannels = new LminusRMixing();
        break;
    case FractalEncoding::NONE:
        _mixingChannels = new NoneMixing();
        break;
    }



}

FractalEncoding::Audio_Fractal_Encoder::~Audio_Fractal_Encoder()
{
    if(_mixingChannels != nullptr)
        delete _mixingChannels;
}

FractalEncoding::ReadResult FractalEncoding::Audio_Fractal_Encoder::doEncoding() {
    FractalEncoding::ReadResult result = FractalEncoding::ERROR;

    result = _reader->readData(_buffer.getFirstChannel(), _buffer.getSecondChannel(), _buffer.getLength());

    _mixingChannels->compute(_buffer.getFirstChannel(), _buffer.getSecondChannel(), _buffer.getLength());

    FractalEncoding::IFractalDataContainer* lptrFirstChannelIFractalDataContainer = _firstFractalEncoder.encode(_buffer.getFirstChannel());

    FractalEncoding::IFractalDataContainer* lptrSecondChannelIFractalDataContainer = _secondFractalEncoder.encode(_buffer.getSecondChannel());

    _writer->writeData(lptrFirstChannelIFractalDataContainer, lptrSecondChannelIFractalDataContainer);

    return result;
}

