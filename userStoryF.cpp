//***************************************************************************
// userStoryF.cpp - Contains functions for the userStory class.
//***************************************************************************

#include "userStoryH.h"

//Changes the stored user type for a user.
void userStory::setUserType(string newType)
{
	userType = newType;
	return;
}

//Changes the stored goal for a user.
void userStory::setGoal(string newGoal)
{
	goal = newGoal;
	return;
}

//Changes the stored purpose for a user.
void userStory::setPurpose(string newPurpose)
{
	purpose = newPurpose;
	return;
}

//Forms the full user story using stored strings.
void userStory::writeFullStory()
{
	fullStory = "As a " + userType + ", I want to " + goal 
		+ " so that I can " + purpose + ".";
	return;
}

//Prints the full user story.
void userStory::printFullStory() const
{
	cout << fullStory;
	return;
}

//Constructors.
//Sets default values for the user story.
userStory::userStory()
{
	userType = "<User Type>";
	goal = "<Goal>";
	purpose = "<Purpose>";
	writeFullStory();
	return;
}

//Applies sent values to the user story.
userStory::userStory(string newType, string newGoal, string newPurpose)
{
	userType = newType;
	goal = newGoal;
	purpose = newPurpose;
	writeFullStory();
	return;
}