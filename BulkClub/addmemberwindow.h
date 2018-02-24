#ifndef ADDMEMBERWINDOW_H
#define ADDMEMBERWINDOW_H

#include <QDialog>
#include "dbmanager.h"

namespace Ui {
class AddMemberWindow;
}

class AddMemberWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AddMemberWindow(QWidget *parent = 0);
    ~AddMemberWindow();

    void closeEvent(QCloseEvent *);
private slots:
    void on_addButton_clicked();
    void checkInput(const QString& text);
signals:
    void windowClosed();

private:
    Ui::AddMemberWindow *ui;
    DBManager bulkdb;
};

#endif // ADDMEMBERWINDOW_H
