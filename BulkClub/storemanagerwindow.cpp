#include "storemanagerwindow.h"
#include "ui_storemanagerwindow.h"

StoreManagerWindow::StoreManagerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreManagerWindow)
{
    QDate minDate;
    QDate maxDate;
    ui->setupUi(this);
    if(bulkdb.isOpen())
    {
       ui->label_status->setText("Enter Transaction Date");
    }
    else
    {
        ui->label_status->setText("Cannot connect to database");
    }

    if(bulkdb.GetValidDates(minDate, maxDate))
    {
        ui->dateEdit->setMinimumDate(minDate);
        ui->dateEdit->setMaximumDate(maxDate);
    }
    else
    {
        qDebug() << "Error setting min/max dates";
    }
}

StoreManagerWindow::~StoreManagerWindow()
{
    delete ui;
}
