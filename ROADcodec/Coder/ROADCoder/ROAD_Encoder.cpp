#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROAD_Encoder.h"
#include "FractalEncoder.h"
#include "ROADEncodingOptions.h"

ROADEncoding::ROAD_Encoder::ROAD_Encoder(ROADEncoding::ROADEncodingOptions aOptions)
    : _fractalEncoder(FractalEncoder(aOptions))
{

}

ROADEncoding::IROADDataContainer *ROADEncoding::ROAD_Encoder::doEncoding(double *aData) {

    IROADDataContainer* lptrRawROADdata = _fractalEncoder.encode(aData);

    return lptrRawROADdata;
}
