#include "petbundletableview.h"

void PetBundleTableView::makeBundleRow(int i, int j, QStandardItem* obj){
    bundleModel->setItem(i,j,obj);
    this->setModel(bundleModel);
    this->resizeRowsToContents();
}

QStandardItemModel* PetBundleTableView::getModel(){
    return this->bundleModel;
}
