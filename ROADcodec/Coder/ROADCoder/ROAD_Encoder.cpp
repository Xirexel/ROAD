#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROAD_Encoder.h"
#include "IRawDataReader.h"
#include "IRawDataWriter.h"
#include "DataBuffer.h"
#include "FractalEncoder.h"
#include "ROADEncodingOptions.h"
#include "ReadResult.h"

ROADEncoding::ROAD_Encoder::ROAD_Encoder(ROADEncoding::IRawDataReader* aReader, ROADEncoding::IRawDataWriter* aWriter, ROADEncoding::ROADEncodingOptions aOptions)
    : _reader(aReader),
      _writer(aWriter),
      _buffer(DataBuffer(aOptions.getFrameSampleLength() * aOptions.getSuperFrameLength())),
      _fractalEncoder(FractalEncoder(aOptions))
{

}

ROADEncoding::ReadResult ROADEncoding::ROAD_Encoder::doEncoding() {
    ROADEncoding::ReadResult result = ERROR;

    result = _reader->readData(_buffer.getData(), _buffer.getLength());

    IFractalDataContainer* lptrRawROADdata = _fractalEncoder.encode(_buffer.getData());

    _writer->writeData(lptrRawROADdata);

    return result;
}
