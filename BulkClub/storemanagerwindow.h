/** @file storemanagerwindow.h
*	@brief Displays a window which lists data for the store manager.
*
* Data includes a list of transactions, profit information, member expiration dates, and member rebate.
* Provides search options to list particular sales as well.
*/

#ifndef STOREMANAGERWINDOW_H
#define STOREMANAGERWINDOW_H

#include <QDialog>
#include "dbmanager.h"
#include "models.h"

namespace Ui {
class StoreManagerWindow;
}

class StoreManagerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StoreManagerWindow(QWidget *parent = 0);
    ~StoreManagerWindow();

private slots:
    void on_dateFilterButton_clicked();
    void on_itemFilterButton_clicked();
    void on_memberIDFilterButton_clicked();
    void on_resetButton_clicked();
    void updateSalesTotals(double);
    void updateMembersTotals(int, int);
    void on_memberNameFilterButton_clicked();
    void on_memberTypeFilterButton_clicked();

    void on_getMemberExpirationButton_clicked();

    void on_SMTabs_tabBarClicked();

private:
    Ui::StoreManagerWindow *ui;
    TransactionModel *tModel;
    ProxyModel *pModel;
    ProxyModel *pRModel;
    ExpModel *eModel;
    RebateModel *rModel;
    QDate minDate;
    QDate maxDate;
};

#endif // STOREMANAGERWINDOW_H
