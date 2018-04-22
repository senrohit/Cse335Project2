#ifndef PETBUNDLETABLEVIEW_H
#define PETBUNDLETABLEVIEW_H

#include <QObject>
#include <QTableView>
#include <QStandardItemModel>
#include <QHeaderView>
#include <QStandardItem>

class PetBundleTableView : public QTableView
{
    Q_OBJECT
public:
    // Separate PetBundle Table Constructor
    PetBundleTableView(QWidget* qw):QTableView(qw){
        bundleModel = new QStandardItemModel(0,3,this);
        this->setSelectionBehavior(QAbstractItemView::SelectRows);
        this->setEditTriggers(QAbstractItemView::NoEditTriggers);
        this->setFixedHeight(23);
        // setting header data
        bundleModel->setHorizontalHeaderItem(0, new QStandardItem(QString("Bundle")));
        bundleModel->setHorizontalHeaderItem(1, new QStandardItem(QString("Price")));
        bundleModel->setHorizontalHeaderItem(2, new QStandardItem(QString("Savings")));
        // sets model according to visual specs given
        this->setModel(bundleModel);
        this->horizontalHeader()->setSectionResizeMode(0,QHeaderView::Stretch);
        this->verticalHeader()->hide();
        this->setShowGrid(false);
    }
    void makeBundleRow(int,int,QStandardItem*);
    QStandardItemModel* getModel();
private:
    QStandardItemModel *bundleModel;
};

#endif // PETBUNDLETABLEVIEW_H
