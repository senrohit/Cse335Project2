#include "shoppingcarttableview.h"

void ShoppingCartTableView::makeCartRow(int i, int j, QStandardItem* obj){
    model->setItem(i,j,obj);
    this->setModel(model);
    this->resizeRowsToContents();
}

QStandardItemModel* ShoppingCartTableView::getModel(){
    return this->model;
}

