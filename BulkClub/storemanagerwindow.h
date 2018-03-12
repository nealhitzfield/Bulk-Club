#ifndef STOREMANAGERWINDOW_H
#define STOREMANAGERWINDOW_H

#include <QDialog>

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
};

#endif // STOREMANAGERWINDOW_H
