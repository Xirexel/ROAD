#include <string>
#include <vector>
#include <exception>
using namespace std;

#include "ROADFractalOrderFactory.h"
#include "ROADFractalFirstOrderBuilderFactory.h"


ROADdecoder::ROAD::IROADFractalBuilderFactory* ROADdecoder::ROAD::ROADFractalOrderFactory::getIROADFractalBuilderFactory(unsigned int aOrder) {

    ROADdecoder::ROAD::IROADFractalBuilderFactory *result = nullptr;

    if(aOrder == 1)
    {
        result = new ROADFractalFirstOrderBuilderFactory();
    }

    return result;
}
