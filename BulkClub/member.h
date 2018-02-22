#ifndef MEMBER_H
#define MEMBER_H

#include <QDate>

class Member
{
private:
    QString memberName;
    int memberID;
    QString membershipType;
    QDate membershipExpiration;
    double totalSpent;
    double rebate;
public:
    Member();
    Member(QString name, int id, QString mType, QDate expDate);

    int GetID() const;
    QString GetMembershipType() const;
    QDate GetExpirationDate() const;
    double GetTotalSpent() const;
    double GetRebate() const;
};

#endif // MEMBER_H
