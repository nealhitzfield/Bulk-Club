#include "models.h"

MemberModel::MemberModel(QObject *parent) : QAbstractTableModel(parent){}

MemberModel::MemberModel(QList<Member> memberList, QObject *parent) : QAbstractTableModel(parent)
{
    modMemberList = memberList;
}

void MemberModel::setList(const QList<Member> memberList)
{
    beginResetModel();
    modMemberList = memberList;
    endResetModel();
}

int MemberModel::rowCount(const QModelIndex & /*parent*/) const
{
    return modMemberList.length();
}

int MemberModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 6;
}

QVariant MemberModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(role == Qt::DisplayRole)
    {
        Member member = modMemberList.at(index.row());

        switch(index.column())
        {
        case 0:
            return member.GetMemberName();
            break;
        case 1:
            return member.GetID();
            break;
        case 2:
            return member.GetMembershipTypeString();
            break;
        case 3:
            return member.GetExpirationDateString();
            break;
        case 4:
            return QString::number(member.GetTotalSpent(), 'f', 2);
            break;
        case 5:
            return QString::number(member.GetRebate(), 'f', 2);
            break;
        }
    }
    return QVariant();
}

QVariant MemberModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
        case 0:
            return tr("Name");
            break;
        case 1:
            return tr("Member ID");
            break;
        case 2:
            return tr("Member Type");
            break;
        case 3:
            return tr("Expiration Date");
            break;
        case 4:
            return tr("Total Spent");
            break;
        case 5:
            return tr("Rebate");
            break;
        }
    }
    return QVariant();
}

ItemModel::ItemModel(QObject *parent) : QAbstractTableModel(parent){}

ItemModel::ItemModel(QList<Item> itemList, QObject *parent) : QAbstractTableModel(parent)
{
    modItemList = itemList;
}

void ItemModel::setList(const QList<Item> itemList)
{
    beginResetModel();
    modItemList = itemList;
    endResetModel();
}

int ItemModel::rowCount(const QModelIndex & /*parent*/) const
{
    return modItemList.length();
}

int ItemModel::columnCount(const QModelIndex & /*parent*/) const
{
    return 2;
}

QVariant ItemModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(role == Qt::DisplayRole)
    {
        Item item = modItemList.at(index.row());

        switch(index.column())
        {
        case 0:
            return item.GetItemName();
            break;
        case 1:
            return QString::number(item.GetItemPrice(), 'f', 2);
            break;
        }
    }
    return QVariant();
}

QVariant ItemModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
    {
        return QVariant();
    }

    if(orientation == Qt::Horizontal)
    {
        switch(section)
        {
        case 0:
            return tr("Item Name");
            break;
        case 1:
            return tr("Item Price");
            break;
        }
    }
    return QVariant();
}
