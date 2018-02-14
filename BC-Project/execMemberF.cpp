//***************************************************************************
// execMemberF.cpp - Contains functions unique to the executiveMember class.
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
//Sets default values for the executive member.
executiveMember::executiveMember(): regularMember()
{
    rebateAmount = 0.00;

    return;
}

//Applies sent values to the executive member.
executiveMember::executiveMember(double newRebateAmount): regularMember()
{
    rebateAmount = newRebateAmount;

    return;
}
