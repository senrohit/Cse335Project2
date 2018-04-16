#include "separatepettable.h"

void SeparatePetTable::makeRow(int i, QStandardItem* obj){
    model->setItem(i,0,obj);
    this->setModel(model);
    this->resizeRowsToContents();

}
