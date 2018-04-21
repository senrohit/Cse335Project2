#include "bundlebuilder.h"
#include "pet.h"
#include <QVector>
#include <QDebug>

BundleBuilder::BundleBuilder(QVector<Pet*> v)
{
    mAllPets = v;
}

BundleBuilder::~BundleBuilder(){
    //delete bundle objects in mBundles
    if (mBundles.size() > 0){
        for (int i = 0; i < mBundles.size(); i++) {
            delete mBundles[i];
        }
    }
}

void BundleBuilder::addDog(QStringList){}
void BundleBuilder::addCat(QStringList){}
void BundleBuilder::addFish(QStringList){}
void BundleBuilder::addBird(QStringList){}

void BundleBuilder::addBundle(QStringList l){
    //get attributes for bundle from list and set up variables that will be used
    QString name = l[0];
    double price = l[1].toDouble();

    QVector<Pet*> petsToAdd;
    //find pets to add to bundle
    for(int i = 2; i < l.size(); i++){
        QString currName = l[i];
        bool found = false;
        //loop through all pets looking for currName
        for (int j = 0; !found; j++){
            //found pet, add to vector of pets to add and add pet price to sum
            if (mAllPets[j]->GetName() == currName){
                petsToAdd.append(mAllPets[j]);
                found = true;
            }
            //pet not found end loop
            else if (j == mAllPets.size()){
                found = true;
            }
        }
    }

    //create new bundle and add it to vector of bundles
    Bundle* newBundle = new Bundle(name, price, petsToAdd);
    mBundles.append(newBundle);
}

QVector<Pet*> BundleBuilder::getPets() const{
    return mBundles;
}
