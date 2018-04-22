#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_shoppingcart.h"
#include "shoppingcart.h"
#include "separatepettable.h"
#include "loadbutton.h"
#include "petbuilder.h"
#include "csvparser.h"
#include <QDebug>
#include "pet.h"
#include "dog.h"
#include "bundlebuilder.h"
#include "savingsvisitor.h"
#include "petbundletableview.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // dialog window
    observerCart = new ShoppingCart(this);
    // connecting load db button with the tables
    connect(ui->loadDB,SIGNAL(clicked()),ui->loadDB,SLOT(buildMyDatabase()));
    connect(ui->loadDB,SIGNAL(iChanged(QObject*)),this,SLOT(actByYourChange(QObject*)));
    // disable mainwindow after on click checkout
    connect(observerCart->getUi()->checkout,SIGNAL(clicked(bool)),ui->centralWidget,SLOT(setEnabled(bool)));
    // on close of observer window change text of button in mainwindow to showcart
    connect(observerCart,SIGNAL(rejected()),ui->show_cart,SLOT(click()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// using mediator pattern to load database
void MainWindow::actByYourChange(QObject* senderObj){
    if (senderObj==ui->loadDB){
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

        //use visitor pattern to visiti each bundle and calculate the discount percentage
        for(int i =0; i< mBundles.size(); i++){
            SavingsVisitor sv;
            mBundles[i]->Accept(&sv);
            mBundles[i]->SetDiscount(sv.GetResult());
        }

        // fill the table with pet data
        for(int i = 0;i<mPets.size();i++){
            QStandardItem *petRowName = new QStandardItem(mPets[i]->GetName());
            QStandardItem *petRowAnimal = new QStandardItem(mPets[i]->GetAnimal());
            QStandardItem *petRowPrice = new QStandardItem(QString::number(mPets[i]->GetPrice()));
            QStandardItem *petRowType = new QStandardItem(mPets[i]->GetType());
            ui->petView->makeRow(i,0,petRowName);
            ui->petView->makeRow(i,1,petRowAnimal);
            ui->petView->makeRow(i,2,petRowPrice);
            ui->petView->makeRow(i,3,petRowType);
        }

        // stretches the table to fit the content
        ui->petView->setFixedHeight(115);

        // fill the table with bundle data
        for(int j = 0; j<mBundles.size();j++){
            QStandardItem *petBundleName = new QStandardItem(mBundles[j]->GetName());
            QStandardItem *petBundlePrice = new QStandardItem(QString::number(mBundles[j]->GetPrice()));
            QStandardItem *petBundleSavings = new QStandardItem(mBundles[j]->GetDiscount());
            ui->bundleView->makeBundleRow(j,0,petBundleName);
            ui->bundleView->makeBundleRow(j,1,petBundlePrice);
            ui->bundleView->makeBundleRow(j,2,petBundleSavings);
        }
        // stretches the table to fit the content
        ui->bundleView->setFixedHeight(75);

        // disable the load database button
        ui->loadDB->setEnabled(false);
    }

}

// observer pattern for showing cart
void MainWindow::on_show_cart_clicked()
{
    if (ui->show_cart->text() == "Hide Cart"){
        observerCart->hide();
        ui->show_cart->setText("Show Cart");
    }
    else{
        observerCart->show();
        ui->show_cart->setText("Hide Cart");
    }
}

// add the selected item to cart
void MainWindow::on_addCart_clicked()
{
    // check for selection in the first pet table
    if(ui->petView->selectionModel()->isSelected(ui->petView->currentIndex())){
        QList<QStandardItem *> items;
        int selectedRow = ui->petView->selectionModel()->currentIndex().row();
        QStandardItem *item_name = new QStandardItem(ui->petView->getModel()->item(selectedRow,0)->text());
        QStandardItem *item_price = new QStandardItem(ui->petView->getModel()->item(selectedRow,2)->text());
        items.append(item_name);
        items.append(item_price);
        observerCart->getUi()->cartDialogView->getModel()->appendRow(items);
        ui->petView->selectionModel()->select(ui->petView->currentIndex(), QItemSelectionModel::Deselect);
        ui->petView->clearSelection();
    }
    // check for selection in the bundle table
    if(ui->bundleView->selectionModel()->isSelected(ui->bundleView->currentIndex())){
        QList<QStandardItem *> bundle_items;
        int selectedRow_bundle = ui->bundleView->selectionModel()->currentIndex().row();
        QStandardItem *bundle_name = new QStandardItem(ui->bundleView->getModel()->item(selectedRow_bundle,0)->text());
        QStandardItem *bundle_price = new QStandardItem(ui->bundleView->getModel()->item(selectedRow_bundle,1)->text());
        bundle_items.append(bundle_name);
        bundle_items.append(bundle_price);
        observerCart->getUi()->cartDialogView->getModel()->appendRow(bundle_items);
        ui->bundleView->selectionModel()->select(ui->bundleView->currentIndex(), QItemSelectionModel::Deselect);
        ui->bundleView->clearSelection();
    }


}
