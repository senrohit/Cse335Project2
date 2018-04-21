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
        for(int i = 0;i<mPets.size();i++){
            QStandardItem *petRowName = new QStandardItem(mPets[i]->GetName());
            QStandardItem *petRowAnimal = new QStandardItem(mPets[i]->GetAnimal());
            QStandardItem *petRowPrice = new QStandardItem(mPets[i]->GetPrice());
            QStandardItem *petRowType = new QStandardItem(mPets[i]->GetType());
            ui->petView->makeRow(i,0,petRowName);
            ui->petView->makeRow(i,1,petRowAnimal);
            ui->petView->makeRow(i,2,petRowPrice);
            ui->petView->makeRow(i,3,petRowType);
        }
        // stretches the table to fit the content
        ui->petView->setFixedHeight(115);
        // disable the load database button
        ui->loadDB->setEnabled(false);
    }

}
