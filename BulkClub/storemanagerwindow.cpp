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
    pModel->setSortRole(Qt::UserRole);
    ui->dailyView->setModel(pModel);
    ui->dailyView->setSortingEnabled(true);
    ui->dailyView->sortByColumn(0, Qt::AscendingOrder);
    ui->memberTypeComboBox->addItem("Regular");
    ui->memberTypeComboBox->addItem("Executive");

    updateSalesTotals(DBManager::instance().CalcGrossSales());
    updateMembersTotals(DBManager::instance().GetTotalShoppers(REGULAR),
                        DBManager::instance().GetTotalShoppers(EXECUTIVE));
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
    updateSalesTotals(DBManager::instance().CalcGrossSalesByDate(dateFilter));
    updateMembersTotals(DBManager::instance().GetTotalShoppersByDate(dateFilter, REGULAR),
                        DBManager::instance().GetTotalShoppersByDate(dateFilter, EXECUTIVE));
}

void StoreManagerWindow::on_itemFilterButton_clicked()
{
    QString itemFilter;

    itemFilter = ui->lineEdit_item->text();
    pModel->setItemName(itemFilter);
    updateSalesTotals(DBManager::instance().CalcGrossSalesByItem(itemFilter));
    updateMembersTotals(DBManager::instance().GetTotalShoppersByItem(itemFilter, REGULAR),
                        DBManager::instance().GetTotalShoppersByItem(itemFilter, EXECUTIVE));
}

void StoreManagerWindow::on_memberIDFilterButton_clicked()
{
    int idFilter;

    idFilter = ui->memberID->value();
    pModel->setBuyersID(idFilter);
    updateSalesTotals(DBManager::instance().CalcGrossSalesByMember(idFilter));
    ui->label_reg_shoppers->setText("");
    ui->label_ex_shoppers->setText("");
}

void StoreManagerWindow::on_resetButton_clicked()
{
    pModel->resetFilter();
    updateSalesTotals(DBManager::instance().CalcGrossSales());
    updateMembersTotals(DBManager::instance().GetTotalShoppers(REGULAR),
                        DBManager::instance().GetTotalShoppers(EXECUTIVE));
}

void StoreManagerWindow::updateSalesTotals(double grossSales)
{
    double taxAmt, netSales;

    taxAmt = grossSales * TAX_RATE;
    netSales = grossSales + taxAmt;

    ui->subtotal->setText(QString::number(grossSales, 'f', 2));
    ui->tax->setText(QString::number(taxAmt, 'f', 2));
    ui->total->setText(QString::number(netSales, 'f', 2));
}

void StoreManagerWindow::updateMembersTotals(int regShoppers, int exShoppers)
{
    ui->label_ex_shoppers->setText(QString::number(exShoppers));
    ui->label_reg_shoppers->setText(QString::number(regShoppers));
}

void StoreManagerWindow::on_memberNameFilterButton_clicked()
{
    QString mName;

    mName = ui->lineEdit_memberName->text();
    pModel->setBuyersName(mName);
    updateSalesTotals(DBManager::instance().CalcGrossSalesByMember(mName));
    ui->label_reg_shoppers->setText("");
    ui->label_ex_shoppers->setText("");
}

void StoreManagerWindow::on_memberTypeFilterButton_clicked()
{
    MemberType mType;

    if(ui->memberTypeComboBox->currentText() == "Regular")
    {
        mType = REGULAR;
        updateMembersTotals(DBManager::instance().GetTotalShoppers(REGULAR), 0);
    }
    else
    {
        mType = EXECUTIVE;
        updateMembersTotals(0, DBManager::instance().GetTotalShoppers(EXECUTIVE));
    }

    pModel->setMemberType(mType);
    updateSalesTotals(DBManager::instance().CalcGrossSalesByMember(mType));
}
