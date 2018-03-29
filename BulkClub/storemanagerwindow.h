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
    void on_memberFilterButton_clicked();
    void on_resetButton_clicked();
    void updateTotals(double);

private:
    Ui::StoreManagerWindow *ui;
    TransactionModel *tModel;
    ProxyModel *pModel;
    QDate minDate;
    QDate maxDate;
};

#endif // STOREMANAGERWINDOW_H
