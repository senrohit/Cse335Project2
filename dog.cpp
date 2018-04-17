#include "dog.h"
#include <QDebug>

// constructor for dog
Dog::Dog(QString name, QString type, double price, double weight,
        QString category){
    _name = name;
    _type = type;
    _weight = weight;
    _price = price;
    _category = category;
}
// destructor
Dog::~Dog(){}
//getter for name
QString Dog::GetName() const{
    qDebug() << "inside dog get name";
    return this->_name;
}
//getter for type
QString Dog::GetType() const{
    return this->_type;
}
//getter for weight
unsigned int Dog::GetWeight() const{
    return this->_weight;
}
 //getter for price
float Dog::GetPrice() const{
    return this->_price;
}
// getter for category
QString Dog::GetCategory() const{
    return this->_category;
}
