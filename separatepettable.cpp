#include "separatepettable.h"

void SeparatePetTable::makeRow(int i, int j, QStandardItem* obj){
    model->setItem(i,j,obj);
    this->setModel(model);
    this->resizeRowsToContents();
}
