#include "csvparser.h"

CSVParser::CSVParser(){}

void CSVParser::setBuilder(Builder* b){
    mBuilder = b;
}

void CSVParser::ParsePet(QString f) {
    QFile petFile(f);

    //error check opening file
    if (!petFile.open(QIODevice::ReadOnly)) {
        qDebug() << petFile.errorString();
    }

    //continue reading each line of file until end is reached
    while (!petFile.atEnd()) {
        QStringList list;
        QString line = petFile.readLine();

        //remove trailing characters of each line
        line.replace("\r\n", "");
        list.append(line.split(','));
        QString PetType = list[0];

        //call appropriate builder function
        if (PetType == "Dog"){
            mBuilder->addDog(list);
        }
        else if (PetType == "Cat"){
            mBuilder->addCat(list);
        }
        else if (PetType == "Bird"){
            mBuilder->addBird(list);
        }
        else if (PetType == "Fish"){
            mBuilder->addFish(list);
        }
    }
}

void CSVParser::ParseBundle(QString f) {
    QFile bundFile(f);

    //error check opening file
    if (!bundFile.open(QIODevice::ReadOnly)) {
        qDebug() << bundFile.errorString();
    }

    //continue reading each line of file until end is reached
    while (!bundFile.atEnd()) {
        QStringList list;
        QString line = bundFile.readLine();

        //removing trailing characcters at the end of each line
        line.replace("\r\n", "");
        list.append(line.split(','));

        //call use builder to construct bundle
        mBuilder->addBundle(list);
    }
}
