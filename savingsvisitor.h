#ifndef SAVINGSVISITOR_H
#define SAVINGSVISITOR_H

#include "visitor.h"

class SavingsVisitor : public Visitor
{
public:
    virtual void VisitBird(Bird*);
    virtual void VisitCat(Cat*);
    virtual void VisitDog(Dog*);
    virtual void VisitFish(Fish*);
    virtual void VisitBundle(Bundle*);
    double GetResult() const;

protected:
    double mSum;
    double mDiscount;
};

#endif // SAVINGSVISITOR_H
