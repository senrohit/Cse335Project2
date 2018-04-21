#ifndef CAT_H
#define CAT_H
#include "pet.h"
#include <QString>

class Cat:public Pet{
protected:
    // special data member only for cat
    bool _fluffy;

public:
    // constructor for cat
    Cat(QString name, QString type, double price, double weight,
            bool fluffy);
    //Destructor
    ~Cat();
    //getter for name
    virtual QString GetName() const;
    //getter for type
    virtual QString GetType() const;
    //getter for weight
     virtual double GetWeight() const;
    //getter for price
    virtual double GetPrice() const;
    // getter for fluffy
    bool GetFluffy() const;
    // getter for animal type
    virtual QString GetAnimal() const;
};

#endif // CAT_H
