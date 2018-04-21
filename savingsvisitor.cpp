#include "savingsvisitor.h"
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

}

double SavingsVisitor::GetResult() const{
    return 0.0;
}
