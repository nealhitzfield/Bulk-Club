#include "adminwindow.h"
#include "ui_adminwindow.h"
#include "confirmremoval.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminWindow),
    mModel(new MemberModel(DBManager::instance().GetAllMembers())),
    iModel(new ItemModel(DBManager::instance().GetAllItems())),
    uModel(new UpgradeModel(DBManager::instance().GetUpgrades())),
    dModel(new DowngradeModel(DBManager::instance().GetDowngrades())),
    selectedID(0),
    selectedName("")
{
    ui->setupUi(this);
    ui->membersTable->setModel(mModel);
    ui->itemsTable->setModel(iModel);
    ui->UpgradeTable->setModel(uModel);
    ui->DowngradeTable->setModel(dModel);
    ui->membersTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->itemsTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->removeMemberButton->setEnabled(false);
    ui->removeItemButton->setEnabled(false);
}

AdminWindow::~AdminWindow()
{
    delete ui;
    delete mModel;
    delete iModel;
}

void AdminWindow::on_addMemberButton_clicked()
{
    AddMemberWindow *addWin;
    addWin = new AddMemberWindow(this);
    connect(addWin, SIGNAL(memberAdded()), this, SLOT(updateMemberView()));
    connect(addWin, SIGNAL(transactionAdded()), this, SLOT(updateMemberView()));
    addWin->setModal(true);
    addWin->exec();
    delete addWin;
}

void AdminWindow::on_removeMemberButton_clicked()
{
    ConfirmRemoval *remWin;
    QList<Member> mList;
    MemberModel *tempModel;

    if(selectedID != 0 && DBManager::instance().MemberExists(selectedID))
    {
        mList.append(Member(DBManager::instance().GetMember(selectedID)));
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

void AdminWindow::removeMember()
{

    if(DBManager::instance().MemberExists(selectedID))
    {
        if(DBManager::instance().RemoveMember(DBManager::instance().GetMember(selectedID)))
        {
            updateMemberView();
        }
    }
}

void AdminWindow::on_membersTable_clicked(const QModelIndex &index)
{
    QModelIndex idIndex;

    idIndex = ui->membersTable->model()->index(index.row(), 1);
    selectedID = ui->membersTable->model()->data(idIndex).toInt();
    ui->removeMemberButton->setEnabled(true);
}

void AdminWindow::on_itemsTable_clicked(const QModelIndex &index)
{
    QModelIndex nameIndex;
    nameIndex = ui->itemsTable->model()->index(index.row(), 0);
    selectedName = ui->itemsTable->model()->data(nameIndex).toString();
    qDebug() << selectedName;
    ui->removeItemButton->setEnabled(true);
}

void AdminWindow::removeItem()
{

    if(DBManager::instance().RemoveItem(DBManager::instance().GetItem(selectedName)))
    {
        updateItemView();
    }
}

void AdminWindow::on_removeItemButton_clicked()
{
    ConfirmRemoval *remWin;
    QList<Item> iList;
    ItemModel *tempModel;

    if(selectedName != "")
    {
        iList.append(Item(DBManager::instance().GetItem(selectedName)));
        tempModel = new ItemModel(iList);
        remWin = new ConfirmRemoval(this);
        connect(this, SIGNAL(sendModel(ItemModel*)), remWin, SLOT(setItemView(ItemModel*)));
        connect(remWin, SIGNAL(removalConfirmed()), this, SLOT(removeItem()));
        emit sendModel(tempModel);
        remWin->exec();
        delete tempModel;
        delete remWin;
    }
}

void AdminWindow::on_addItemButton_clicked()
{
    additemwindow *addWin;
    addWin = new additemwindow(this);
    connect(addWin, SIGNAL(itemAdded()), this, SLOT(updateItemView()));
    addWin->setModal(true);
    addWin->exec();
    delete addWin;
}

void AdminWindow::updateItemView()
{
    qDebug() << "Received signal, updating item view";
    iModel->setList(DBManager::instance().GetAllItems());
}

void AdminWindow::updateMemberView()
{
    qDebug() << "Received signal, updating member view";
    mModel->setList(DBManager::instance().GetAllMembers());
}

void AdminWindow::on_tabWidget_tabBarClicked()
{
    qDebug() << "Received signal, updating upgrades/downgrades";
    uModel->setList(DBManager::instance().GetUpgrades());
    dModel->setList(DBManager::instance().GetDowngrades());
}
