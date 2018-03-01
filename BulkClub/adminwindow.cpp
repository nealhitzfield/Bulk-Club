#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "confirmremoval.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    mModel = new MemberModel(bulkdb.GetAllMembers());
    iModel = new ItemModel(bulkdb.GetAllItems());
    ui->membersTable->setModel(mModel);
    ui->itemsTable->setModel(iModel);
    ui->membersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->itemsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->removeMemberButton->setEnabled(false);
    selectedID = 0;
}

AdminWindow::~AdminWindow()
{
    delete ui;
    delete mModel;
}

void AdminWindow::on_addMemberButton_clicked()
{
    AddMemberWindow *addWin;
    addWin = new AddMemberWindow(this);
    connect(addWin, SIGNAL(windowClosed()), this, SLOT(updateView()));
    addWin->setModal(true);
    addWin->exec();
    delete addWin;
}

void AdminWindow::on_removeMemberButton_clicked()
{
    ConfirmRemoval *remWin;
    QList<Member> mList;
    MemberModel *tempModel;

    if(selectedID != 0)
    {
        mList.append(Member(bulkdb.GetMember(selectedID)));
        tempModel = new MemberModel(mList);
        remWin = new ConfirmRemoval(this);
        connect(this, SIGNAL(sendModel(MemberModel*)), remWin, SLOT(setMemberView(MemberModel*)));
        connect(remWin, SIGNAL(removalConfirmed()), this, SLOT(removeMember()));
        emit sendModel(tempModel);
        remWin->exec();
        delete tempModel;
        delete remWin;
    }
}

void AdminWindow::updateView()
{
    mModel->setList(bulkdb.GetAllMembers());
}

void AdminWindow::removeMember()
{
    if(bulkdb.RemoveMember(bulkdb.GetMember(selectedID)))
    {
        updateView();
    }
}

void AdminWindow::on_membersTable_clicked(const QModelIndex &index)
{
    QModelIndex idIndex;

    idIndex = ui->membersTable->model()->index(index.row(), 1);
    selectedID = ui->membersTable->model()->data(idIndex).toInt();
    ui->removeMemberButton->setEnabled(true);
}

void AdminWindow::on_addItemButton_clicked()
{
    additemwindow *addWin;
    addWin = new additemwindow(this);
    //connect(addWin, SIGNAL(windowClosed()), this, SLOT(updateView()));
    addWin->setModal(true);
    addWin->exec();
    delete addWin;
}
