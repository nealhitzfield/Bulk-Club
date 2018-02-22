#include "member.h"

Member::Member(QString name, int id, MemberType mType, QDate expDate)
{
    memberName      = name;
    memberID        = id;
    membership      = mType;
    expirationDate  = expDate;
    totalSpent      = 0.00;
    rebate          = 0.00;
}

QString Member::GetMemberName() const
{
    return memberName;
}

int Member::GetID() const
{
    return memberID;
}

MemberType Member::GetMembershipType() const
{
    return membership;
}

QDate Member::GetExpirationDate() const
{
    return expirationDate;
}

double GetTotalSpent() const
{
    return totalSpent;
}

double GetRebate() const
{
    return rebate;
}
