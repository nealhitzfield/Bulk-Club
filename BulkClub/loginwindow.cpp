#include "loginwindow.h"
#include "smwindow.h"
#include "adminwindow.h"
#include "ui_loginwindow.h"

LoginWindow::LoginWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    myDb = QSqlDatabase::addDatabase("QSQLITE");
    myDb.setDatabaseName("bulkclub.db");

    if(!myDb.open())
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
    QString username;
    QString password;
    QString employeeType;
    QSqlQuery query;
    SMWindow smWin;
    AdminWindow adminWin;

    username = ui->lineEdit_username->text();
    password = ui->lineEdit_password->text();

    if(!myDb.open())
    {
        qDebug() << "Failed to verify credentials";
        return;
    }

    query.prepare("SELECT username, password, employee_type FROM credentials WHERE username = :username AND password = :password");
    query.bindValue(":username", username);
    query.bindValue(":password", password);

    if(query.exec())
    {
        if(query.next())
        {
            employeeType = query.value(2).toString();
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
            else
            {
                ui->label_status->setText("Unknown Employee Type");
            }

        }
        else
        {
            ui->label_status->setText("Invalid username/password");
        }
    }
    else
    {
        qDebug() << query.lastError();
    }
}
