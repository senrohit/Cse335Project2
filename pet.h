#ifndef PET_H
#define PET_H

#include <QString>
#include <QVector>

#include "visitor.h"

// base class Pet
class Pet{
protected:
    // protected data members so that the client can't access them
    QString _name;
    QString _type;
    double _weight;
    double _price;
    QVector<Pet*> mPets;
    QString mDiscount;
    QString mAnimal;

public:
    virtual ~Pet();

    // virtual getters for the protected data members
    virtual QString GetName() const = 0;
    virtual QString GetType() const = 0;
    virtual double GetWeight() const = 0;
    virtual double GetPrice() const = 0;
    virtual QString GetAnimal() const=0;
    virtual QVector<Pet*> GetPets() const;
    virtual void SetDiscount(QString);
    virtual QString GetDiscount() const;
    virtual void Accept(Visitor*)=0;
};

#endif // PET_H
