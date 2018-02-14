//***************************************************************************
// regMemberF.cpp - Contains functions for the regularMember class.
//***************************************************************************

#include "header.h"

//Function purpose.
/*
void functName()
{

    return;
}
*/

//Constructors.
//Sets default values for the regular member.
regularMember::regularMember()
{
    memberName = "";
    membershipNumber = 99999;
    type = REGULAR;
    expierationDate = "00/00/0000";
    totalAmountSpent = 0.00;

    return;
}

//Applies sent values to the regular member.
regularMember::regularMember(string newName, int newMNumber, string newType,
                             string newExpiration, double newTotalSpent)
{
    memberName = newName;
    membershipNumber = newMNumber;

    if (newType == "Regular" || newType == "regular")
    {
        type = REGULAR;
    }

    if (newType == "Executive" || newType == "executive")
    {
        type = EXECUTIVE;
    }

    expierationDate = newExpiration;
    totalAmountSpent = newTotalSpent;

    return;
}
