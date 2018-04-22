#ifndef SHOPPINGCARTTABLEVIEW_H
#define SHOPPINGCARTTABLEVIEW_H

#include <QObject>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QStandardItem>

class ShoppingCartTableView : public QTableView
{
    Q_OBJECT
public:
    // Separate Pet Table Constructor
    ShoppingCartTableView(QWidget* qw):QTableView(qw){
        model = new QStandardItemModel(0,2,this);
        this->setSelectionBehavior(QAbstractItemView::SelectRows);
        this->setEditTriggers(QAbstractItemView::NoEditTriggers);
        this->setFixedHeight(200);
        // setting header data
        model->setHorizontalHeaderItem(0, new QStandardItem(QString("Item")));
        model->setHorizontalHeaderItem(1, new QStandardItem(QString("Price")));
        // sets model according to visual specs given
        this->setModel(model);
        this->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
        this->verticalHeader()->hide();
        this->setShowGrid(false);
    }
    void makeCartRow(int,int,QStandardItem*);
    QStandardItemModel* getModel();
private:
    QStandardItemModel *model;
};

#endif // SHOPPINGCARTTABLEVIEW_H
