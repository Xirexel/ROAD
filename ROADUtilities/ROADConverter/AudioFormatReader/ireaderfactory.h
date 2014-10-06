#ifndef IREADERFACTORY_H
#define IREADERFACTORY_H

#include <tuple>
#include <QString>


#include "audioformatreader_global.h"

class IReader;

class AUDIOFORMATREADERSHARED_EXPORT IReaderFactory
{
public:

    enum TypeAudioFile
    {
        NONE,
        WAVE
    };


    static IReaderFactory &getInstance();



    std::tuple<bool, IReader* > getIReader(QString aFilePath, TypeAudioFile aTypeAudioFile);

private:

    IReaderFactory();

    ~IReaderFactory();

    IReaderFactory(const IReaderFactory&);


    IReader *getWaveReader(QString aFilePath);

};

#endif // IREADERFACTORY_H
