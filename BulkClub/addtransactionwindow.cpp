#include "addtransactionwindow.h"
#include "ui_addtransactionwindow.h"

AddTransactionWindow::AddTransactionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTransactionWindow)
{
    ui->setupUi(this);

    ui->comboBox->addItems(DBManager::instance().GetAllItemNames());
}

AddTransactionWindow::~AddTransactionWindow()
{
    delete ui;
}

void AddTransactionWindow::receiveID(int id)
{
    memberID = id;
}

void AddTransactionWindow::on_purchaseCancelButton_clicked()
{
    close();
}

void AddTransactionWindow::on_purchaseAddButton_clicked()
{
    QDate   transDate;
    int     id;
    QString transItemName;
    double  itemPrice;
    int     transQuantity;

    transDate = ui->purchaseDate->date();
    id = memberID;
    transItemName = ui->comboBox->itemText(ui->comboBox->currentIndex());
    transQuantity = ui->purchaseQuantity->value();
    itemPrice = DBManager::instance().GetItemPrice(transItemName);

    qDebug() << "Added " << transItemName << " at $" << itemPrice;

    Item transItem(transItemName, itemPrice);
    if (!DBManager::instance().TransactionExists(Transaction(transDate, id, transItem, transQuantity, itemPrice)))
    {
        if (DBManager::instance().AddTransaction(Transaction(transDate, id, transItem, transQuantity, itemPrice)))
        {
            ui->label_status->setText("Success.");
        }
        else
        {
            ui->label_status->setText("Failed to add.");
        }
    }
}
