#ifndef BUNDLLE_H
#define BUNDLLE_H
#include "pet.h"
#include <QVector>

class Bundle : public Pet
{
public:
    Bundle(QString n, double p, QString d, QVector<Pet*>);
    virtual QString GetName() const;
    virtual QString GetType() const;
    virtual double GetWeight() const;
    virtual double GetPrice() const;
    virtual QString GetAnimal() const;

protected:

};

#endif // BUNDLLE_H
