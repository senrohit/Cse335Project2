#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "separatepettable.h"
#include "loadbutton.h"
#include "petbuilder.h"
#include "csvparser.h"
#include <QDebug>
#include "pet.h"
#include "dog.h"
#include "bundlebuilder.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // base table
    //SeparatePetTable *petTable = new SeparatePetTable(parent);
    // connecting load db button with the table
    connect(ui->loadDB,SIGNAL(clicked()),ui->loadDB,SLOT(buildMyDatabase()));
    connect(ui->loadDB,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));

    //parser to read in csv files
    CSVParser parser;

    //create pet builder, set the builder in parser, parse file and then grab vector of pets
    PetBuilder pb;
    parser.setBuilder(&pb);
    parser.ParsePet("Pets.csv");
    mPets = pb.getPets();

    //create bundle builder, set the builder in parser, parse file and then grab vector of bundles
    BundleBuilder bb(mPets);
    parser.setBuilder(&bb);
    parser.ParseBundle("Bundles.csv");
    mBundles = bb.getPets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actByYourChange(QObject* senderObj){
    if (senderObj==ui->loadDB){
        QStandardItem *firstRow = new QStandardItem(QString("ONE"));
        QStandardItem *secondRow = new QStandardItem(QString("TWO"));
        QStandardItem *thirdRow = new QStandardItem(QString("THREE"));
        QStandardItem *fourthRow = new QStandardItem(QString("FOUR"));
        ui->petView->makeRow(0,firstRow);
        ui->petView->makeRow(1,secondRow);
        ui->petView->makeRow(2,thirdRow);
        ui->petView->makeRow(3,fourthRow);
        ui->petView->setFixedHeight(115);
        ui->loadDB->setEnabled(false);
    }

}
