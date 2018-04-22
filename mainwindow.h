#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "pet.h"
#include "shoppingcart.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void actByYourChange(QObject*);

private slots:
    void on_show_cart_clicked();

    void on_addCart_clicked();

private:
    Ui::MainWindow *ui;
    ShoppingCart* observerCart;
    QVector<Pet*> mPets;
    QVector<Pet*> mBundles;
};

#endif // MAINWINDOW_H
