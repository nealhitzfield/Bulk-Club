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
    ui->addButton->setEnabled(false);
    ui->expiration_date->setMinimumDate(QDate::currentDate());
}

AddMemberWindow::~AddMemberWindow()
{
    delete ui;
}

void AddMemberWindow::closeEvent(QCloseEvent *)
{
    emit windowClosed();
    qDebug() << "Emitting window closed";
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
           ui->label_status->setText("Member added");
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
