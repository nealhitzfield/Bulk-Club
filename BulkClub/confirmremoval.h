/** @file confirmremoval.h
*	@brief Prompts user to confirm their decision for deleting a member or inventory item.
*/

#ifndef CONFIRMREMOVAL_H
#define CONFIRMREMOVAL_H

#include <QDialog>
#include <QAbstractTableModel>
#include "models.h"

namespace Ui {
class ConfirmRemoval;
}

class ConfirmRemoval : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmRemoval(QWidget *parent = 0);
    ~ConfirmRemoval();

private slots:
    void setMemberView(MemberModel *model);
    void setItemView(ItemModel *model);
    void on_confirmButton_clicked();

    void on_cancelButton_clicked();

signals:
    void removalConfirmed();
private:
    Ui::ConfirmRemoval *ui;
};

#endif // CONFIRMREMOVAL_H
