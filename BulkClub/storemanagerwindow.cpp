#include "storemanagerwindow.h"
#include "ui_storemanagerwindow.h"

StoreManagerWindow::StoreManagerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreManagerWindow),
    tModel(new TransactionModel(DBManager::instance().GetAllTransactions())),
    pModel(new ProxyModel)
{
    ui->setupUi(this);

    if(DBManager::instance().GetValidDates(minDate, maxDate))
    {
        ui->dateEdit->setMinimumDate(minDate);
        ui->dateEdit->setMaximumDate(maxDate);
    }
    else
    {
        qDebug() << "Error setting min/max dates";
        ui->dateEdit->setEnabled(false);
    }

    pModel->setSourceModel(tModel);
    ui->dailyView->setModel(pModel);
    ui->dailyView->setSortingEnabled(true);
    ui->dailyView->sortByColumn(0, Qt::AscendingOrder);
    updateTotals(DBManager::instance().CalcGrossSales());
}

StoreManagerWindow::~StoreManagerWindow()
{
    delete ui;
}

void StoreManagerWindow::on_dateFilterButton_clicked()
{
    QDate dateFilter;

    dateFilter = ui->dateEdit->date();
    pModel->setTransactionDate(dateFilter);
    updateTotals(DBManager::instance().CalcGrossSalesByDate(dateFilter));
}

void StoreManagerWindow::on_itemFilterButton_clicked()
{
    QString itemFilter;

    itemFilter = ui->lineEdit_item->text();
    pModel->setItemName(itemFilter);
    updateTotals(DBManager::instance().CalcGrossSalesByItem(itemFilter));
}

void StoreManagerWindow::on_memberIDFilterButton_clicked()
{
    int idFilter;

    idFilter = ui->memberID->value();
    pModel->setBuyersID(idFilter);
    updateTotals(DBManager::instance().CalcGrossSalesByMember(idFilter));
}

void StoreManagerWindow::on_resetButton_clicked()
{
    pModel->resetFilter();
    updateTotals(DBManager::instance().CalcGrossSales());
}

void StoreManagerWindow::updateTotals(double grossSales)
{
    double taxAmt, netSales;

    taxAmt = grossSales * TAX_RATE;
    netSales = grossSales + taxAmt;

    ui->subtotal->setText(QString::number(grossSales, 'f', 2));
    ui->tax->setText(QString::number(taxAmt, 'f', 2));
    ui->total->setText(QString::number(netSales, 'f', 2));
}
