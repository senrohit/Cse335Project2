#ifndef CSVPARSER_H
#define CSVPARSER_H
#include <QString>
#include <QFile>
#include <QDebug>
#include "builder.h"


class CSVParser
{
public:
    CSVParser();
    void setBuilder(Builder* b);
    void ParsePet(QString f);
    void ParseBundle(QString f);

protected:
    Builder* mBuilder;
};

#endif // CSVPARSER_H
