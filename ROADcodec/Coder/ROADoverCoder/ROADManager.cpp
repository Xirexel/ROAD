#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADManager.h"
#include "ROAD_Encoder.h"
#include "ROADDataCollection.h"
#include "Class.h"
#include "ROADoverEncodingOptions.h"
#include "IROADDataCollection.h"
#include "IRawDataBuffer.h"

ROADoverEncoding::ROADManager::ROADManager(ROADoverEncoding::ROADoverEncodingOptions aOptions) {
}

ROADoverEncoding::IROADDataCollection* ROADoverEncoding::ROADManager::doEncoding(ROADoverEncoding::IRawDataBuffer* aBuffer) {
	throw "Not yet implemented";
}

