//***************************************************************************
// userStoryH.h - class userStory
// Is used to store and print user stories.
//
// Functions.
// setUserType(string): Changes the stored user type for a user.
//
// setGoal(string): Changes the stored goal for a user.
//
// setPurpose(string): Changes the stored purpose for a user.
//
// writeFullStory(string): Forms the full user story using stored strings.
//
// prtinFullStory() const: Prints the full user story.
//
// Constructors.
// userStory(): Sets default values for the user story.
//
// userStory(string, string, string): Applies sent values to the user story.
//***************************************************************************

#ifndef USERSTORY_H
#define USERSTORY_H
#include "Header.h"

class userStory
{
	public:
		void setUserType(string);
		void setGoal(string);
		void setPurpose(string);

		void writeFullStory();
		void printFullStory() const;

		//Constructors.
		userStory();
		userStory(string, string, string);

	private:
		string userType;
		string goal;
		string purpose;
		string fullStory;
};

#endif