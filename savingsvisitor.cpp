#include "savingsvisitor.h"
#include "pet.h"
#include "bird.h"
#include "cat.h"
#include "dog.h"
#include "fish.h"
#include "bundle.h"

void SavingsVisitor::VisitBird(Bird* b){
    mSum += b->GetPrice();
}

void SavingsVisitor::VisitCat(Cat* c){
    mSum += c->GetPrice();
}

void SavingsVisitor::VisitDog(Dog* d){
    mSum += d->GetPrice();
}

void SavingsVisitor::VisitFish(Fish* f){
    mSum += f->GetPrice();
}

void SavingsVisitor::VisitBundle(Bundle* b){
    QVector<Pet*> pets = b->GetPets();
    for(int i =0; i < pets.size(); i++){
        pets[i]->Accept(this);
    }

    //calculate discount by finding difference between sum of pets in bundle and bundle price, then divide by sum
    double diff = mSum - b->GetPrice();
    double percent_d = diff/mSum;
    percent_d *= 100;
    QString percent_s = QString::number((int)percent_d);
    mDiscount = percent_s + "%";

}

QString SavingsVisitor::GetResult() const{
    return mDiscount;
}
