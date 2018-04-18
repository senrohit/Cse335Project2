#include "pet.h"
#include <QVector>

Pet::~Pet(){}

QVector<Pet*> Pet::GetPets() const {return mPets;}
QString Pet::GetDiscount() const {return mDiscount;}
