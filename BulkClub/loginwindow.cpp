#include "loginwindow.h"
#include "smwindow.h"
#include "adminwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow),
    bulkdb(DBManager("bulkclub.db"))
{
    ui->setupUi(this);

    if(!bulkdb.isOpen())
    {
        ui->label_status->setText("Failed to connect to database");
    }
    else
    {
        ui->label_status->setText("Please sign in");
    }
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_pushButton_clicked()
{
    QString employeeType;
    SMWindow smWin;
    AdminWindow adminWin;

    if(bulkdb.VerifyLogin(Credentials(ui->lineEdit_username->text(),
                                      ui->lineEdit_password->text()), employeeType))
    {
        if(employeeType == "administrator")
        {
            adminWin.setModal(true);
            adminWin.exec();
        }
        else if(employeeType == "store manager")
        {
            smWin.setModal(true);
            smWin.exec();
        }
    }
    else
    {
        ui->label_status->setText("Invalid username/password");
    }
}
