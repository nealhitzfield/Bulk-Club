#include "storemanagerwindow.h"
#include "ui_storemanagerwindow.h"

StoreManagerWindow::StoreManagerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreManagerWindow)
{
    QDate minDate;
    QDate maxDate;
    QString grossSales;

    ui->setupUi(this);
    if(DBManager::instance().isOpen())
    {
       ui->label_status->setText("Enter Transaction Date");
    }
    else
    {
        ui->label_status->setText("Cannot connect to database");
    }

    if(DBManager::instance().GetValidDates(minDate, maxDate))
    {
        ui->dateEdit->setMinimumDate(minDate);
        ui->dateEdit->setMaximumDate(maxDate);
    }
    else
    {
        qDebug() << "Error setting min/max dates";
    }

    tModel = new TransactionModel(DBManager::instance().GetAllTransactions());
    pModel = new ProxyModel;
    pModel->setSourceModel(tModel);

    ui->dailyView->setModel(pModel);
    ui->dailyView->setSortingEnabled(true);
    ui->dailyView->sortByColumn(0, Qt::AscendingOrder);

    grossSales = QString::number(DBManager::instance().CalcGrossSales(), 'f', 2);
    ui->gross_sales->setText(grossSales);
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
    ui->gross_sales->setText(QString::number(DBManager::instance().CalcGrossSalesByDate(dateFilter), 'f', 2));
}

void StoreManagerWindow::on_itemFilterButton_clicked()
{
    QString itemFilter;

    itemFilter = ui->lineEdit_item->text();
    pModel->setItemName(itemFilter);
    ui->gross_sales->setText(QString::number(DBManager::instance().CalcGrossSalesByItem(itemFilter), 'f', 2));
}

void StoreManagerWindow::on_memberFilterButton_clicked()
{
    int idFilter;

    idFilter = ui->memberID->value();
    pModel->setBuyersID(idFilter);
    ui->gross_sales->setText(QString::number(DBManager::instance().CalcGrossSalesByMember(idFilter), 'f', 2));
}

void StoreManagerWindow::on_resetButton_clicked()
{
    pModel->resetFilter();
    ui->gross_sales->setText(QString::number(DBManager::instance().CalcGrossSales(), 'f', 2));
}
