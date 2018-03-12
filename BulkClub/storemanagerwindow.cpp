#include "storemanagerwindow.h"
#include "ui_storemanagerwindow.h"

StoreManagerWindow::StoreManagerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StoreManagerWindow)
{
    ui->setupUi(this);
}

StoreManagerWindow::~StoreManagerWindow()
{
    delete ui;
}
