#ifndef BUNDLLE_H
#define BUNDLLE_H
#include "pet.h"
#include <QVector>

class Bundle : public Pet
{
public:
    Bundle(QString n, double p, QVector<Pet*>);
    virtual QString GetName() const;
    virtual QString GetType() const;
    virtual double GetWeight() const;
    virtual double GetPrice() const;
    virtual void Accept(Visitor*);
    virtual QString GetAnimal() const;

protected:

};

#endif // BUNDLLE_H
