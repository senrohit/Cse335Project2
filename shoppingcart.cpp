#include "shoppingcart.h"
#include "ui_shoppingcart.h"
#include "shoppingcarttableview.h"
#include <QDir>
#include <QTextStream>

ShoppingCart::ShoppingCart(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShoppingCart)
{
    ui->setupUi(this);
}

ShoppingCart::~ShoppingCart()
{
    delete ui;
}

// delete item on click of delete button
void ShoppingCart::on_del_clicked()
{
    int selectedRow = ui->cartDialogView->selectionModel()->currentIndex().row();
    ui->cartDialogView->getModel()->removeRow(selectedRow);
}

// checkout button on click, calculate total price and write to csv file
void ShoppingCart::on_checkout_clicked()
{
    // specifying file path
    QString filepath = "checkout.csv";
    QFile file(filepath);
    double result = 0;
    const int column = 1;

    // open file
    if (file.open(QFile::WriteOnly|QFile::Truncate)){
        QTextStream stream(&file);

        // iterating over rows
        for (int row = 0; row < ui->cartDialogView->getModel()->rowCount(); ++row) {

            // adding up the total checkout price
            result += ui->cartDialogView->getModel()->item(row, column)->text().toDouble();

            // writing output to file
            stream << ui->cartDialogView->getModel()->item(row, 0)->text() << "," <<
                       ui->cartDialogView->getModel()->item(row, column)->text() << "\n";
        }

        //close file
        file.close();
    }

    // show sum in label
    ui->label->setText( "Total:"+QString::number(result) );

    // disable the functionality of the observer window
    ui->cartDialogView->setEnabled(false);
    ui->checkout->setEnabled(false);
    ui->del->setEnabled(false);
}


