#include "bird.h"

// constructor for bird
Bird::Bird(QString name, QString type, double price, double weight,
        bool nocturnal){
    _name = name;
    _type = type;
    _weight = weight;
    _price = price;
    _nocturnal = nocturnal;
}
Bird::~Bird(){}
//getter for name
QString Bird::GetName() const{
    return this->_name;
}
// getter for type
QString Bird::GetType() const{
    return this->_type;
}
double Bird::GetWeight() const{
    return this->_weight;
}
 //getter for price
double Bird::GetPrice() const{
    return this->_price;
}
// getter for nocturnal
bool Bird::GetNocturnal() const{
    return this->_nocturnal;
}
//visitor hook
void Bird::Accept(Visitor* v) {
    v->VisitBird(this);
}
