#ifndef BIRD_H
#define BIRD_H
#include "pet.h"
#include <QString>

class Bird:public Pet{
protected:
    // special data member only for bird
    bool _nocturnal;

public:
    // constructor for bird
    Bird(QString name, QString type, double price, double weight,
            bool nocturnal);
    ~Bird();
    //getter for name
    virtual QString GetName() const;
    // getter for type
    virtual QString GetType() const;
    virtual double GetWeight() const;
     //getter for price
    virtual double GetPrice() const;
    // getter for nocturnal
    bool GetNocturnal() const;
    // getter for animal type
    virtual QString GetAnimal() const;
};

#endif // BIRD_H
