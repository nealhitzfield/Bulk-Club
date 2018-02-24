#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QTabWidget>
#include "membermodel.h"
#include "dbmanager.h"
#include "addmemberwindow.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();

private slots:
    void on_addMemberButton_clicked();
    void on_removeMemberButton_clicked();
    void updateView();
    void removeMember();
    void on_membersTable_clicked(const QModelIndex &index);

signals:
    void sendSelectedID(int id);
    void sendModel(MemberModel *mod);
private:
    Ui::AdminWindow *ui;
    MemberModel *model;
    DBManager bulkdb;
    int selectedID;
};

#endif // ADMINWINDOW_H
