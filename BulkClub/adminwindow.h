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
    void removeMember();
    void on_membersTable_clicked(const QModelIndex &index);
    void on_itemsTable_clicked(const QModelIndex &index);
    void on_addItemButton_clicked();
    void on_removeItemButton_clicked();
    void removeItem();
    void updateItemView();
    void updateMemberView();
signals:
    void sendSelectedID(int id);
    void sendSelectedName(QString itemName);
    void sendModel(MemberModel *mod);
    void sendModel(ItemModel *mod);
private:
    Ui::AdminWindow *ui;
    MemberModel *mModel;
    ItemModel *iModel;
    int selectedID;
    QString selectedName;
};

#endif // ADMINWINDOW_H
