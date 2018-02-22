#ifndef MEMBER_H
#define MEMBER_H

#include <QDate>

enum MemberType {REGULAR, EXECUTIVE};

class Member
{
private:
    QString     memberName;
    int         memberID;
    MemberType  membership;
    QDate       expirationDate;
    double      totalSpent;
    double      rebate;
public:
    Member(QString name, int id, MemberType mType, QDate expDate);

    QString GetMemberName() const;
    int GetID() const;
    MemberType GetMembershipType() const;
    QDate GetExpirationDate() const;
    double GetTotalSpent() const;
    double GetRebate() const;
};

#endif // MEMBER_H
