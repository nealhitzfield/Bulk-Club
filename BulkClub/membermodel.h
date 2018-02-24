#ifndef MEMBERMODEL_H
#define MEMBERMODEL_H

#include <QAbstractTableModel>
#include <QList>
#include "member.h"

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

#endif // MEMBERMODEL_H
