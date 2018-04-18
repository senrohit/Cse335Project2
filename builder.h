#ifndef BUILDER_H
#define BUILDER_H
#include <QString>
#include "pet.h"
#include <QVector>
#include "bundle.h"

class Builder
{
public:
    Builder();
    virtual ~Builder();
    virtual void addDog(QStringList)=0;
    virtual void addCat(QStringList)=0;
    virtual void addFish(QStringList)=0;
    virtual void addBird(QStringList)=0;
    virtual void addBundle(QStringList)=0;
    virtual QVector<Pet*> getPets()const=0;

protected:
    QVector<Pet*> mPets;
};

#endif // BUILDER_H
