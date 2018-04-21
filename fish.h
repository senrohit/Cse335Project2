#ifndef FISH_H
#define FISH_H
#include "pet.h"
#include <QString>

class Fish:public Pet{
protected:
    // special data member only for fish
    QString _watertype;


public:
    // constructor for fish
    Fish(QString name, QString type, double price, double weight,
            QString watertype);
    // destructor
    ~Fish();
    //getter for name
    virtual QString GetName() const;
    //getter for type
    virtual QString GetType() const;
    //getter for weight
     virtual double GetWeight() const;
     //getter for price
    virtual double GetPrice() const;
    // getter for category
    QString GetWaterType() const;
    virtual void Accept(Visitor*);
    // getter for animal type
    virtual QString GetAnimal() const;
};
#endif // FISH_H
