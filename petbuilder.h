#ifndef PETBUILDER_H
#define PETBUILDER_H
#include "builder.h"
#include <QVector>
#include "pet.h"
#include "builder.h"

class PetBuilder:public Builder
{
public:
    PetBuilder();
    virtual void addDog(QStringList);
    virtual void addCat(QStringList);
    virtual void addFish(QStringList);
    virtual void addBird(QStringList);
    virtual void addBundle(QStringList);
    virtual QVector<Pet*> getPets();

protected:
    QVector<Pet*> mPets;
};

#endif // PETBUILDER_H
