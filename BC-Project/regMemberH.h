//***************************************************************************
// regMemberH.h - class regularMember
// Is used to __
//
// Functions.
//
//
// Constructors.
// regularMember(): Sets default values for the regular member.
//
// regularMember(string, int, string, string, double): Applies sent values
// to the regular member.
//***************************************************************************

#ifndef REGMEMBERH_H
#define REGMEMBERH_H

#include "header.h"

class regularMember
{
    public:


        //Constructors.
        regularMember();
        regularMember(string, int, string, string, double);

    private:
        string memberName;
        int membershipNumber;
        memberType type;
        string expierationDate;
        double totalAmountSpent;
};

#endif
