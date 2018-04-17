#ifndef CSVPARSER_H
#define CSVPARSER_H
#include <QString>
#include <QFile>
#include <QDebug>
#include "builder.h"
#include "petbuilder.h"

class CSVParser
{
public:
    CSVParser();
    void setBuilder(Builder* b);
    void ParsePet(QString f) {
        QFile petFile(f);
        if (!petFile.open(QIODevice::ReadOnly)) {
            qDebug() << petFile.errorString();
        }
        QStringList list;
        while (!petFile.atEnd()) {
            QString line = petFile.readLine();
            line.replace("\r\n", "");
            list.append(line.split(','));
//            QString PetType = list[0];

//            if (PetType == "Dog"){
//                mBuilder->addDog(list);
//            }
//            else if (PetType == "Cat"){
//                mBuilder->addCat(list);
//            }
//            else if (PetType == "Bird"){
//                mBuilder->addCat(list);
//            }
//            else if (PetType == "Fish"){
//                mBuilder->addFish(list);
//            }
        }
        qDebug() << list;
    }

protected:
    Builder* mBuilder;
};

#endif // CSVPARSER_H
