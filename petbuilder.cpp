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

    Dog newPet(name, type, price, weight, special);
    mPets.append(&newPet);
}
void PetBuilder::addCat(QStringList l){
    QString name = l[1];
    QString type = l[2];
    double weight = l[3].toDouble();
    double price = l[4].toDouble();
    bool special = (l[5].toLower() == "true") ? true : false;

    Cat newPet(name, type, price, weight, special);
    mPets.append(&newPet);
}
void PetBuilder::addFish(QStringList l){
    QString name = l[1];
    QString type = l[2];
    double weight = l[3].toDouble();
    double price = l[4].toDouble();
    QString special = l[5];

    Fish newPet(name, type, price, weight, special);
    mPets.append(&newPet);
}
void PetBuilder::addBird(QStringList l){
    QString name = l[1];
    QString type = l[2];
    double weight = l[3].toDouble();
    double price = l[4].toDouble();
    bool special = (l[5].toLower() == "true") ? true : false;

    Bird newPet(name, type, price, weight, special);
    mPets.append(&newPet);
}
void PetBuilder::addBundle(QStringList l){}
QVector<Pet*> PetBuilder::getPets(){
    QVector<Pet*> temp = mPets;
    while(mPets.size() > 0){
        mPets.pop_back();
    }
    return temp;
}
