#ifndef BUNDLEBUILDER_H
#define BUNDLEBUILDER_H
#include "builder.h"
#include "pet.h"
#include "bundle.h"
#include <QVector>
#include "bundle.h"

class BundleBuilder : public Builder
{
public:
    BundleBuilder(QVector<Pet*>);
    virtual ~BundleBuilder();
    virtual void addDog(QStringList);
    virtual void addCat(QStringList);
    virtual void addFish(QStringList);
    virtual void addBird(QStringList);
    virtual void addBundle(QStringList);
    virtual QVector<Pet*> getPets() const;

protected:
    QVector<Pet*> mBundles;
    QVector<Pet*> mAllPets;
};

#endif // BUNDLEBUILDER_H
