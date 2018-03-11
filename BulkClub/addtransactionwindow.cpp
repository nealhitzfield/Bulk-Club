#include "addtransactionwindow.h"
#include "ui_addtransactionwindow.h"

AddTransactionWindow::AddTransactionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTransactionWindow)
{
    ui->setupUi(this);
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
    double  transPrice;
    int     transQuantity;

    transDate = ui->purchaseDate->date();
    id = memberID;
    transItemName = ui->purchaseItem->text();
    transPrice = ui->purchasePrice->value();
    transQuantity = ui->purchaseQuantity->value();

    Item transItem(transItemName, transPrice);

    if (!bulkdb.TransactionExists(Transaction(transDate, id, transItem, transQuantity, transPrice)))
    {
        if (bulkdb.AddTransaction(Transaction(transDate, id, transItem, transQuantity, transPrice)))
        {
            ui->label_status->setText("Success.");
        }
        else
        {
            ui->label_status->setText("Failed to add.");
        }
    }
}

