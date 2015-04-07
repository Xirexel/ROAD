#ifndef ROADOVERCODERFACTORY_H
#define ROADOVERCODERFACTORY_H

#include "../../ListItem/interfaces.h"

class ROADoverCoderFactory : public IROADoverCoderFactory
{
public:
    explicit ROADoverCoderFactory();

    virtual ~ROADoverCoderFactory();

    virtual IROADoverCoder* createIROADoverCoder(IROADoverRawReader* ptrReader,
                                                 std::unique_ptr<ROADcoder::ROADoverCoder::IROADoverEncodingOptions>
                                                 &aIROADoverCoderOptions,
                                                 IOriginalAudioStreamOptions *aOriginalAudioStreamOptions,
                                                 QString outputFile);


    virtual QString name() const;

    virtual QWidget *getLowFormatOptionsWidget();
};

#endif // ROADOVERCODERFACTORY_H
