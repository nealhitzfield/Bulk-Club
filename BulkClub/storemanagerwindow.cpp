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

    tModel = new TransactionModel(bulkdb.GetAllTransactions());
    pModel = new ProxyModel;
    pModel->setSourceModel(tModel);

    ui->dailyView->setModel(pModel);
    ui->dailyView->setSortingEnabled(true);
    ui->dailyView->sortByColumn(0, Qt::AscendingOrder);
}

StoreManagerWindow::~StoreManagerWindow()
{
    delete ui;
}

void StoreManagerWindow::on_dateFilterButton_clicked()
{
    pModel->setTransactionDate(ui->dateEdit->date());
}

void StoreManagerWindow::on_itemFilterButton_clicked()
{
    pModel->setItemName(ui->lineEdit_item->text());
}

void StoreManagerWindow::on_memberFilterButton_clicked()
{
    pModel->setBuyersID(ui->memberID->value());
}
