#ifndef SAVINGSVISITOR_H
#define SAVINGSVISITOR_H

#include "visitor.h"
#include <QString>

class SavingsVisitor : public Visitor
{
public:
    virtual void VisitBird(Bird*);
    virtual void VisitCat(Cat*);
    virtual void VisitDog(Dog*);
    virtual void VisitFish(Fish*);
    virtual void VisitBundle(Bundle*);
    QString GetResult() const;

protected:
    double mSum = 0;
    QString mDiscount;
};

#endif // SAVINGSVISITOR_H
