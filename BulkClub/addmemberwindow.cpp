#include "addmemberwindow.h"
#include "ui_addmemberwindow.h"

AddMemberWindow::AddMemberWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddMemberWindow)
{
    ui->setupUi(this);
    ui->mTypes->addItem("Regular");
    ui->mTypes->addItem("Executive");
    ui->mID->setMinimum(10000);
    ui->mID->setMaximum(99999);
    connect(ui->lineEdit_mName, SIGNAL(textChanged(QString)), this, SLOT(checkInput(QString)));
    ui->addButton->setDisabled(true);
    ui->expiration_date->setMinimumDate(QDate::currentDate());
    ui->yesButton->setDisabled(true);
    ui->noButton->setDisabled(true);
}

AddMemberWindow::~AddMemberWindow()
{
    delete ui;
}

void AddMemberWindow::lockInputs()
{
    ui->lineEdit_mName->setDisabled(true);
    ui->mID->setDisabled(true);
    ui->mTypes->setDisabled(true);
    ui->expiration_date->setDisabled(true);
}

void AddMemberWindow::enableInputs()
{
    ui->lineEdit_mName->setEnabled(true);
    ui->mID->setEnabled(true);
    ui->mTypes->setEnabled(true);
    ui->expiration_date->setEnabled(true);
}

void AddMemberWindow::checkInput(const QString &text)
{
    ui->addButton->setEnabled(!text.isEmpty());
}

void AddMemberWindow::on_addButton_clicked()
{
    QString name;
    int id;
    QString mType;
    MemberType memberType;
    QDate expDate;

    name = ui->lineEdit_mName->text();
    id = ui->mID->value();
    mType = ui->mTypes->currentText();
    expDate = ui->expiration_date->date();

   if(mType == "Regular")
   {
       memberType = REGULAR;
   }
   else if(mType == "Executive")
   {
       memberType = EXECUTIVE;
   }
   if(!bulkdb.MemberExists(Member(name, id, memberType, expDate)))
   {
       if(bulkdb.AddMember(Member(name, id, memberType, expDate)))
       {
           emit memberAdded();
           ui->label_status->setText("Add Transactions?");
           lockInputs();
           ui->addButton->setEnabled(false);
           ui->yesButton->setEnabled(true);
           ui->noButton->setEnabled(true);
       }
       else
       {
           ui->label_status->setText("Failed to add");
       }
   }
   else
   {
       ui->label_status->setText("Member ID exists");
   }
}

void AddMemberWindow::on_noButton_clicked()
{
    enableInputs();
    ui->label_status->setText("Enter New Member");
    ui->yesButton->setDisabled(true);
    ui->noButton->setDisabled(true);
}

void AddMemberWindow::on_yesButton_clicked()
{
    AddTransactionWindow *transWin;
    int id;

    transWin = new AddTransactionWindow;
    id = ui->mID->value();
    connect(this, SIGNAL(sendID(int)), transWin, SLOT(receiveID(int)));
    emit sendID(id);
    transWin->setModal(true);
    transWin->exec();
    delete transWin;
}
