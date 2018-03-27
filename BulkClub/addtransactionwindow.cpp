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
    double  transSubtotal;
    double  taxAmt;
    double  transTotal;

    transDate = ui->purchaseDate->date();
    id = memberID;
    transItemName = ui->comboBox->itemText(ui->comboBox->currentIndex());
    transQuantity = ui->purchaseQuantity->value();
    itemPrice = DBManager::instance().GetItemPrice(transItemName);
    transSubtotal = itemPrice * transQuantity;
    taxAmt = transSubtotal * TAX_RATE;
    transTotal = transSubtotal + taxAmt;
    ui->label_item_price->setText(QString::number(itemPrice, 'f', 2));
    ui->qty_purchased->setText(QString::number(transQuantity));
    ui->label_subtotal->setText(QString::number(transSubtotal, 'f', 2));
    ui->label_tax->setText(QString::number(taxAmt, 'f', 2));
    ui->label_trans_total->setText(QString::number(transTotal, 'f', 2));
    qDebug() << "Added " << transItemName << " at $" << itemPrice;

    Item transItem(transItemName, itemPrice);
    if (!DBManager::instance().TransactionExists(Transaction(transDate, id, transItem, transQuantity, transSubtotal, transTotal)))
    {
        if (DBManager::instance().AddTransaction(Transaction(transDate, id, transItem, transQuantity, transSubtotal, transTotal)))
        {
            ui->label_status->setText("Success.");
            emit transactionAdded();
        }
        else
        {
            ui->label_status->setText("Failed to add.");
        }
    }
}
