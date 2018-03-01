#ifndef ADDITEMWINDOW_H
#define ADDITEMWINDOW_H

#include <QDialog>
#include <QDebug>
#include "dbmanager.h"

namespace Ui {
class additemwindow;
}

class additemwindow : public QDialog
{
    Q_OBJECT

public:
    explicit additemwindow(QWidget *parent = 0);
    ~additemwindow();

private slots:
    void on_addButton_clicked();

private:
    Ui::additemwindow *ui;
    DBManager db;
};

#endif // ADDITEMWINDOW_H
