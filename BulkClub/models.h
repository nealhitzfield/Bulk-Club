#ifndef MEMBERMODEL_H
#define MEMBERMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include <QDebug>
#include "member.h"
#include "item.h"

class MemberModel : public QAbstractTableModel
{
public:
    MemberModel(QObject *parent = 0);
    MemberModel(QList<Member> memberList, QObject *parent = 0);

    void setList(const QList<Member> memberList);
    int rowCount(const QModelIndex & /*parent*/) const;
    int columnCount(const QModelIndex & /*parent*/) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

private:
    QList<Member> modMemberList;
};

class ItemModel : public QAbstractTableModel
{
public:
    ItemModel(QObject *parent = 0);
    ItemModel(QList<Item> itemList, QObject *parent = 0);

    void setList(const QList<Item> itemList);
    int rowCount(const QModelIndex & /*parent*/) const;
    int columnCount(const QModelIndex & /*parent*/) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
private:
    QList<Item> modItemList;
};
#endif // MEMBERMODEL_H
