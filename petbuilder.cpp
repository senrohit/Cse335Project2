#include "petbuilder.h"
#include <QVector>
#include "dog.h"
#include "cat.h"
#include "fish.h"
#include "bird.h"

PetBuilder::PetBuilder()
{

}

void PetBuilder::addDog(QStringList l){
    QString name = l[1];
    QString type = l[2];
    double weight = l[3].toDouble();
    double price = l[4].toDouble();
    QString special = l[5];

    Dog newDog(name, type, price, weight, special);
}
void PetBuilder::addCat(QStringList l){}
void PetBuilder::addFish(QStringList l){}
void PetBuilder::addBird(QStringList l){}
void PetBuilder::addBundle(QStringList l){}
QVector<Pet*> PetBuilder::getPets(){
    QVector<Pet*> temp = mPets;
    while(mPets.size() > 0){
        mPets.pop_back();
    }
    return temp;
}
