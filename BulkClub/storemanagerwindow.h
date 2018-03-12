#ifndef STOREMANAGERWINDOW_H
#define STOREMANAGERWINDOW_H

#include <QDialog>
#include "dbmanager.h"

namespace Ui {
class StoreManagerWindow;
}

class StoreManagerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit StoreManagerWindow(QWidget *parent = 0);
    ~StoreManagerWindow();

private:
    Ui::StoreManagerWindow *ui;
    DBManager bulkdb;
};

#endif // STOREMANAGERWINDOW_H
