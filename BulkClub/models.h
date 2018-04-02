/** @file models.h
*	@brief Manages the user interface as well as information that is displayed to the user.
*/

#ifndef MEMBERMODEL_H
#define MEMBERMODEL_H

#include <QAbstractTableModel>
#include <QSortFilterProxyModel>
#include <QStyledItemDelegate>
#include <QList>
#include <QDebug>
#include <QObject>
#include "member.h"
#include "item.h"
#include "transaction.h"
#include "dbmanager.h"

/**
* @brief Model used to display Member information
*/
class MemberModel : public QAbstractTableModel
{
public:
    MemberModel(QList<Member> memberList, QObject *parent = 0);

    void setList(const QList<Member> memberList);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QList<Member> modMemberList;
};

/**
* @brief Model used to display Item information
*/
class ItemModel : public QAbstractTableModel
{
public:
    ItemModel(QList<Item> itemList, QObject *parent = 0);

    void setList(const QList<Item> itemList);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QList<Item> modItemList;
};

/**
* @brief Model used to display Transaction information
*/
class TransactionModel : public QAbstractTableModel
{
public:
    TransactionModel(QList<Transaction> transList, QObject *parent = 0);

    void setList(const QList<Transaction> transList);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QList<Transaction> modTransList;
};


enum Filter {NO_FILTER, DATE, ITEM, MEMBER_ID, MEMBER_NAME, MEMBERSHIP_TYPE};

/**
* @brief Proxy Model used for sorting/filtering
*/
class ProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
public:
    ProxyModel(QObject* parent = 0);
    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

public slots:
    void setTransactionDate(QDate transDate);
    void setBuyersID(int buyersID);
    void setBuyersName(QString buyersName);
    void setItemName(QString itemName);
    void setMemberType(MemberType memberType);
    void resetFilter();

signals:
    void updateTotal(double price);

private:
    Filter filterType;
    QDate tDate;
    int bID;
    QString iName;
    QString bName;
    MemberType mType;
};

/**
* @brief Model used to display upgrade suggestions
*/
class UpgradeModel : public QAbstractTableModel
{
public:
    UpgradeModel(QList<Member> upgradeList, QObject *parent = 0);

    void setList(const QList<Member> upgradeList);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QList<Member> modUpgradeList;
};

/**
* @brief Model used to display downgrade suggestions
*/
class DowngradeModel : public QAbstractTableModel
{
public:
    DowngradeModel(QList<Member> downgradeList, QObject *parent = 0);

    void setList(const QList<Member> downgradeList);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QList<Member> modDowngradeList;
};

/**
* @brief Handles display of membership experiation data.
*/
class ExpModel : public QAbstractTableModel
{
public:
    ExpModel(QList<Member> expList, QObject *parent = 0);

    void setList(const QList<Member> expList);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QList<Member> modExpList;
};

/**
* @brief Handles display of membership rebate data.
*/
class RebateModel : public QAbstractTableModel
{
public:
    RebateModel(QList<Member> rebateList, QObject *parent = 0);

    void setList(const QList<Member> rebateList);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QList<Member> modRebateList;
};


#endif // MEMBERMODEL_H
