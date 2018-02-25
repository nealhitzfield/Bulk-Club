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

Member::Member(QString name, int id, MemberType mType, QDate expDate, double totSpent, double rebateAmt)
{
    memberName      = name;
    memberID        = id;
    membership      = mType;
    expirationDate  = expDate;
    totalSpent      = totSpent;
    rebate          = rebateAmt;
}

QString Member::GetMemberName() const
{
    return memberName;
}

int Member::GetID() const
{
    return memberID;
}

QString Member::GetMembershipTypeString() const
{
    QString membershipType;

    switch(membership)
    {
    case REGULAR:
        membershipType = "Regular";
        break;
    case EXECUTIVE:
        membershipType = "Executive";
        break;
    };

    return membershipType;
}

QString Member::GetExpirationDateString() const
{
    return expirationDate.toString("MM/dd/yyyy");
}

double Member::GetTotalSpent() const
{
    return totalSpent;
}

double Member::GetRebate() const
{
    return rebate;
}

