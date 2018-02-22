#include "smwindow.h"
#include "ui_smwindow.h"

SMWindow::SMWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SMWindow)
{
    ui->setupUi(this);
}

SMWindow::~SMWindow()
{
    delete ui;
}
