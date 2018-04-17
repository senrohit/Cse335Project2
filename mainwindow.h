#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "pet.h"

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

private:
    Ui::MainWindow *ui;
    QVector<Pet*> mPets;
};

#endif // MAINWINDOW_H
