#include "fish.h"

// constructor for fish
Fish::Fish(QString name, QString type, double price, double weight,
        QString watertype){
    _name = name;
    _type = type;
    _weight = weight;
    _price = price;
    _watertype = watertype;
}
// destructor
Fish::~Fish(){}
//getter for name
QString Fish::GetName() const{
    return this->_name;
}
//getter for type
QString Fish::GetType() const{
    return this->_type;
}
//getter for weight
unsigned int Fish::GetWeight() const{
    return this->_weight;
}
 //getter for price
float Fish::GetPrice() const{
    return this->_price;
}
// getter for category
QString Fish::GetWaterType() const{
    return this->_watertype;
}
