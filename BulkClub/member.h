#ifndef MEMBER_H
#define MEMBER_H

#include <QDate>

class Member
{
private:
    string memberName;
    int memberID;
    string membershipType;
    QDate membershipExpiration;
    double totalSpent;
    double rebate;
public:
    Member();
    Member(string name, int id, string mType, QDate expDate);

    int GetID() const;
    string GetMembershipType() const;
    QDate GetExpirationDate() const;
    double GetTotalSpent() const;
    double GetRebate() const;
};

#endif // MEMBER_H
