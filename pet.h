#ifndef PET_H
#define PET_H

#include <QString>

// base class Pet
class Pet{
protected:
    // protected data members so that the client can't access them
    QString _name;
    QString _type;
    unsigned int _weight;
    double _price;

public:
    Pet();
    // virtual getters for the protected data members
    virtual QString GetName() const = 0;
    virtual QString GetType() const = 0;
    virtual unsigned int GetWeight() const = 0;
    virtual float GetPrice() const = 0;
};

#endif // PET_H
