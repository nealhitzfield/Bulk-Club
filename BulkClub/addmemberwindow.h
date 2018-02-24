#ifndef ADDMEMBERWINDOW_H
#define ADDMEMBERWINDOW_H

#include <QDialog>
#include "dbmanager.h"
#include "addtransactionwindow.h"

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
    void lockInputs();
    void enableInputs();
private slots:
    void on_addButton_clicked();
    void checkInput(const QString& text);
    void on_noButton_clicked();
    void on_yesButton_clicked();

signals:
    void windowClosed();
    void sendID(int id);

private:
    Ui::AddMemberWindow *ui;
    DBManager bulkdb;
};

#endif // ADDMEMBERWINDOW_H
