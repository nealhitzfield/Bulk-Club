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

    qDebug() << name;
    qDebug() << price;

    if(!db.ItemExists(Item(name,price)))
    {
        qDebug() << "inside first if statement additemwindow.cpp";

        if(db.AddItem(Item(name, price)))
        {
            qDebug() << "inside second if statement additemwindow.cpp";
            ui->outputLabel->setText("Item Added");
        }
        else
        {
            qDebug() << "inside first else statement additemwindpw.cpp";
            ui->outputLabel->setText("Failed To Add Item'");
        }
    }
    else
    {
                    qDebug() << "inside second else statement additemwindow.cpp";
        ui->outputLabel->setText("Item already exists");
    }
}
