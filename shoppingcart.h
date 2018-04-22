#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <QDialog>

namespace Ui {
class ShoppingCart;
}

class ShoppingCart : public QDialog
{
    Q_OBJECT

public:
    explicit ShoppingCart(QWidget *parent = 0);
    Ui::ShoppingCart* getUi() const {return ui;}
    ~ShoppingCart();



private slots:
    void on_del_clicked();

    void on_checkout_clicked();

private:
    Ui::ShoppingCart *ui;
};

#endif // SHOPPINGCART_H
