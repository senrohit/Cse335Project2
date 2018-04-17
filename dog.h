#ifndef DOG_H
#define DOG_H
#include "pet.h"
#include <QString>

class Dog:public Pet{
protected:
    // special data member only for dog
    QString _category;

public:
    // constructor for dog
    Dog(QString name, QString type, double price, double weight,
            QString category);
    // destructor
    ~Dog();
    //getter for name
    virtual QString GetName() const;
    //getter for type
    virtual QString GetType() const;
    //getter for weight
    virtual unsigned int GetWeight() const;
     //getter for price
    virtual float GetPrice() const;
    // getter for category
    QString GetCategory() const;
};

#endif // DOG_H