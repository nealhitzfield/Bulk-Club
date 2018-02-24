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
