#include "additemwindow.h"
#include "ui_additemwindow.h"

additemwindow::additemwindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::additemwindow)
{
    ui->setupUi(this);
}

additemwindow::~additemwindow()
{
    delete ui;
}

void additemwindow::on_addButton_clicked()
{
    QString name;
    double price;

    name = ui->itemName->text();
    price = ui->itemPrice->value();

    if(!DBManager::instance().ItemExists(Item(name,price)))
    {
        if(DBManager::instance().AddItem(Item(name, price)))
        {
            ui->outputLabel->setText("Item Added");
            emit itemAdded();
        }
        else
        {
            ui->outputLabel->setText("Failed To Add Item'");
        }
    }
    else
    {
        ui->outputLabel->setText("Item already exists");
    }
}
