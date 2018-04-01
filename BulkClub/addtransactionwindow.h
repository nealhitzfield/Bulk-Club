/** @file addtransactionwindow.h
*	@brief Displays a window which lets the user add a member's transactions.
*
* Features for a member's transactions include purchase date, item type, and quantity.
*/

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
    void on_purchaseCancelButton_clicked();
    void on_purchaseAddButton_clicked();

signals:
    void transactionAdded();

private:
    Ui::AddTransactionWindow *ui;
    int memberID;
};

#endif // ADDTRANSACTIONWINDOW_H
