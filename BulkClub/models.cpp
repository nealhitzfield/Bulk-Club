#include "models.h"

// MEMBER MODEL
MemberModel::MemberModel(QList<Member> memberList, QObject *parent):
    QAbstractTableModel(parent)
{
    modMemberList = memberList;
}

void MemberModel::setList(const QList<Member> memberList)
{
    beginResetModel();
    modMemberList = memberList;
    endResetModel();
}

int MemberModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return modMemberList.length();
}

int MemberModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 6;
}

QVariant MemberModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(index.row() >= modMemberList.size() || index.row() < 0)
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
        default:
            return QVariant();
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

// ITEM MODEL
ItemModel::ItemModel(QList<Item> itemList, QObject *parent):
    QAbstractTableModel(parent)
{
    modItemList = itemList;
}

void ItemModel::setList(const QList<Item> itemList)
{
    beginResetModel();
    modItemList = itemList;
    endResetModel();
}

int ItemModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return modItemList.length();
}

int ItemModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant ItemModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(index.row() >= modItemList.size() || index.row() < 0)
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
        default:
            return QVariant();
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

// TRANSACTION MODEL
TransactionModel::TransactionModel(QList<Transaction> transList, QObject *parent):
    QAbstractTableModel(parent)
{
    modTransList = transList;
}

void TransactionModel::setList(const QList<Transaction> transList)
{
    modTransList = transList;
}

int TransactionModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return modTransList.length();
}

int TransactionModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 5;
}

QVariant TransactionModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    if(index.row() >= modTransList.size() || index.row() < 0)
    {
        return QVariant();
    }
    if(role == Qt::DisplayRole)
    {
        const Transaction& trans = modTransList.at(index.row());
        switch(index.column())
        {
        case 0:
            return trans.GetTransactionDate().toString("MM/dd/yyyy");
            break;
        case 1:
            return trans.GetBuyersID();
            break;
        case 2:
            return trans.GetItemName();
            break;
        case 3:
            return trans.GetQuantityPurchased();
            break;
        case 4:
            return trans.GetTransactionPrice();
            break;
        default:
            return QVariant();
            break;
        }
    }
    return QVariant();
}

QVariant TransactionModel::headerData(int section, Qt::Orientation orientation, int role) const
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
            return tr("Transaction Date");
            break;
        case 1:
            return tr("Buyer's ID");
            break;
        case 2:
            return tr("Item Purchased");
            break;
        case 3:
            return tr("Qty Purchased");
            break;
        case 4:
            return tr("Transaction Total");
            break;
        default:
            return QVariant();
            break;
        }
    }
    return QVariant();
}

ProxyModel::ProxyModel(QObject *parent): QSortFilterProxyModel(parent),
    filterType(NO_FILTER), tDate(1900, 1, 1), bID(0), iName("")
{

}

void ProxyModel::setTransactionDate(QDate transDate)
{
    if(tDate != transDate)
    {
        tDate = transDate;
        filterType = DATE;
    }
    invalidateFilter();
}

void ProxyModel::setBuyersID(int buyersID)
{
    if(bID != buyersID)
    {
        bID = buyersID;
        filterType = MEMBER;
    }
    invalidateFilter();
}

void ProxyModel::setItemName(QString itemName)
{
    if(iName != itemName)
    {
        iName = itemName;
        filterType = ITEM;
    }
    invalidateFilter();
}

bool ProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    QModelIndex indDate;
    QModelIndex indID;
    QModelIndex indName;

    indDate = sourceModel()->index(source_row, 0, source_parent);
    indID = sourceModel()->index(source_row, 1, source_parent);
    indName = sourceModel()->index(source_row, 2, source_parent);

    switch(filterType)
    {
    case DATE:
        if(QDate::fromString(sourceModel()->data(indDate).toString(), "MM/dd/yyyy") != tDate)
            return false;
        break;
    case MEMBER:
        if(sourceModel()->data(indID).toInt() != bID)
            return false;
        break;
    case ITEM:
        if(sourceModel()->data(indName).toString() != iName)
            return false;
        break;
    case NO_FILTER:
        return true;
        break;
    default:
        return true;
        break;
    }

    return true;
}

QVariant ProxyModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    return sourceModel()->headerData(section, orientation, role);
}
