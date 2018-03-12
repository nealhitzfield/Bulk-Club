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
    void on_pushButton_clicked();

private:
    Ui::StoreManagerWindow *ui;
    DBManager bulkdb;
    TransactionModel *tModel;
    ProxyModel *pModel;
};

#endif // STOREMANAGERWINDOW_H
