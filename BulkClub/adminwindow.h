#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QDialog>
#include <QTabWidget>
#include "models.h"
#include "dbmanager.h"
#include "addmemberwindow.h"
#include "additemwindow.h"

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

    void on_addItemButton_clicked();

signals:
    void sendSelectedID(int id);
    void sendModel(MemberModel *mod);
private:
    Ui::AdminWindow *ui;
    MemberModel *mModel;
    ItemModel *iModel;
    DBManager bulkdb;
    int selectedID;
};

#endif // ADMINWINDOW_H
