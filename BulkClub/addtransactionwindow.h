#ifndef ADDTRANSACTIONWINDOW_H
#define ADDTRANSACTIONWINDOW_H

#include <QDialog>
#include "dbmanager.h"

namespace Ui {
class AddTransactionWindow;
}

class AddTransactionWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddTransactionWindow(QWidget *parent = 0);
    ~AddTransactionWindow();

private slots:
    void receiveID(int id);
private:
    Ui::AddTransactionWindow *ui;
    DBManager bulkdb;
    int memberID;
};

#endif // ADDTRANSACTIONWINDOW_H