#ifndef SEPARATEPETTABLE_H
#define SEPARATEPETTABLE_H

#include <QObject>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QStandardItem>

class SeparatePetTable : public QTableView
{
    Q_OBJECT
public:
    // Separate Pet Table Constructor
    SeparatePetTable(QWidget* qw):QTableView(qw){
        model = new QStandardItemModel(0,4,this);
        this->setEditTriggers(QAbstractItemView::NoEditTriggers);
        this->setFixedHeight(23);
        // setting header data
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Name")));
        model->setHorizontalHeaderItem(1, new QStandardItem(QString("Class")));
        model->setHorizontalHeaderItem(2, new QStandardItem(QString("Price")));
        model->setHorizontalHeaderItem(3, new QStandardItem(QString("Special Attribute")));
        // sets model according to visual specs given
        this->setModel(model);
        this->horizontalHeader()->setSectionResizeMode(3,QHeaderView::Stretch);
        this->verticalHeader()->hide();
        this->setShowGrid(false);
    }
    void makeRow(int,int,QStandardItem*);
private:
    QStandardItemModel *model;
};

#endif // SEPARATEPETTABLE_H
