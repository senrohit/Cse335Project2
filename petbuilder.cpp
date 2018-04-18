#include "petbuilder.h"
#include <QVector>
#include "dog.h"
#include "cat.h"
#include "fish.h"
#include "bird.h"
#include <QDebug>

PetBuilder::PetBuilder()
{

}

PetBuilder::~PetBuilder() {
    //delete pet objects in mpets
    if (mPets.size() > 0){
        for(int i =0; i < mPets.size(); i++){
            delete mPets[i];
        }
    }
}

void PetBuilder::addDog(QStringList l){
    //get pet attributes from list and construct new pet, then append to list of pets
    QString name = l[1];
    QString type = l[2];
    double weight = l[3].toDouble();
    double price = l[4].toDouble();
    QString special = l[5];

    Dog* newPet = new Dog(name, type, price, weight, special);
    mPets.append(newPet);
}
void PetBuilder::addCat(QStringList l){
    //get pet attributes from list and construct new pet, then append to list of pets
    QString name = l[1];
    QString type = l[2];
    double weight = l[3].toDouble();
    double price = l[4].toDouble();
    bool special = (l[5].toLower() == "true") ? true : false;

    Cat* newPet = new Cat(name, type, price, weight, special);
    mPets.append(newPet);
}
void PetBuilder::addFish(QStringList l){
    //get pet attributes from list and construct new pet, then append to list of pets
    QString name = l[1];
    QString type = l[2];
    double weight = l[3].toDouble();
    double price = l[4].toDouble();
    QString special = l[5];

    Fish* newPet = new Fish(name, type, price, weight, special);
    mPets.append(newPet);
}
void PetBuilder::addBird(QStringList l){
    //get pet attributes from list and construct new pet, then append to list of pets
    QString name = l[1];
    QString type = l[2];
    double weight = l[3].toDouble();
    double price = l[4].toDouble();
    bool special = (l[5].toLower() == "true") ? true : false;

    Bird* newPet = new Bird(name, type, price, weight, special);
    mPets.append(newPet);
}
void PetBuilder::addBundle(QStringList){}

QVector<Pet*> PetBuilder::getPets() const{
   // creates a copy of  mPets
   QVector<Pet*> temp(mPets);
   // TODO: need to figure out how to delete pet objects created using new keyword
//    while(mPets.size() > 0){
//        Pet* p = mPets.back();
//        mPets.pop_back();
//        delete p;
//    }

    return temp;
}

