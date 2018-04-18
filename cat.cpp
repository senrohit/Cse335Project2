#include "cat.h"

// constructor for cat
Cat::Cat(QString name, QString type, double price, double weight,
        bool fluffy){
    _name = name;
    _type = type;
    _weight = weight;
    _price = price;
    _fluffy = fluffy;
}
//Destructor
Cat::~Cat(){}
//getter for name
QString Cat::GetName() const{
    return this->_name;
}
//getter for type
QString Cat::GetType() const{
    return this->_type;
}
//getter for weight
double Cat::GetWeight() const{
    return this->_weight;
}
//getter for price
double Cat::GetPrice() const{
    return this->_price;
}
// getter for fluffy
bool Cat::GetFluffy() const{
    return this->_fluffy;
}
