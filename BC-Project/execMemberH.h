//***************************************************************************
// execMemberH.h - class executiveMember - derived from the regularMember class.
// Is used to __
//
// Functions.
//
//
// Constructors.
// executiveMember(): Sets default values for the executive member.
//
// executiveMember(double): Applies sent values to the executive member.
//***************************************************************************

#ifndef EXECMEMBERH_H
#define EXECMEMBERH_H
#include "header.h"

class executiveMember:public regularMember
{
    public:


        //Constructors.
        executiveMember();
        executiveMember(double);

    private:
        double rebateAmount;

};

#endif
