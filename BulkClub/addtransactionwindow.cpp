#include "addtransactionwindow.h"
#include "ui_addtransactionwindow.h"

AddTransactionWindow::AddTransactionWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddTransactionWindow)
{
    ui->setupUi(this);
    QStringList itemNames;
    QSqlQuery query;
    int nameIndex;
    QString name;
    query.prepare("SELECT item_name FROM inventory");
    if(query.exec())
    {
        nameIndex = query.record().indexOf("item_name");
        while(query.next())
        {
            name = query.value(nameIndex).toString();
            itemNames.append(name);
        }
    }
    else
    {
        qDebug() << "Error getting items: " << query.lastError();
    }
    ui->comboBox->addItems(itemNames);
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
    QSqlQuery query;
    int priceIndex;

    transDate = ui->purchaseDate->date();
    id = memberID;

    transItemName = ui->comboBox->itemText(ui->comboBox->currentIndex());
    transQuantity = ui->purchaseQuantity->value();

    query.prepare("SELECT price FROM inventory WHERE item_name = :item_name");
    query.bindValue(":item_name", transItemName);
    if(query.next())
    {
        priceIndex = query.record().indexOf("price");
        transPrice = query.value(priceIndex).toDouble();
    }
    qDebug() << "Added " << transItemName << " at $" << transPrice;

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
