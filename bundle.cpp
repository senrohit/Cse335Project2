#include "bundle.h"


Bundle::Bundle(QString n, double p, QVector<Pet*> v)
{
    _name = n;
    _price = p;
    mDiscount = "";
    mPets = v;
}

QString Bundle::GetName() const {return _name;}
QString Bundle::GetType() const{return "";}
double Bundle::GetWeight() const{return 0.0;}
double Bundle::GetPrice() const{return _price;}

void Bundle::Accept(Visitor* v){
    v->VisitBundle(this);
}
QString Bundle::GetAnimal() const {return "";}
