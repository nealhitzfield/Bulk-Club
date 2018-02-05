//***************************************************************************
// Names: _
//		  _
//		  _
//		  _
//		  _
//
// Team: 
// Product Owner: 
// Scurm Master: 
//
// Class: CS-1C
// Assignment 3: Agile
// Due date: 2/5/2018
//***************************************************************************

//***************************************************************************
// Source.cpp: This program _
//***************************************************************************

#include "Header.h"
#include "userStoryH.h"

int main()
{
	//Variables.
	userStory user[NUM_WORKERS];
	string input;

	//Recieves user input for the user stories.
	cout << "Enter information for the following catagories." << endl;
	cout << "Be sure to begin inputs with a lowercase letter; omit periods at the end." << endl << endl;

	for (int count = 0; count < NUM_WORKERS; ++count)
	{
		cout << "User " << count + 1 << ". " << endl;

		cout << "User Type: ";
		getline(cin, input);
		user[count].setUserType(input);

		cout << "Goal: ";
		getline(cin, input);
		user[count].setGoal(input);

		cout << "Purpose: ";
		getline(cin, input);
		user[count].setPurpose(input);

		user[count].writeFullStory();
		cout << endl;
	}

	//Print user stories.
	for (int count = 0; count < NUM_WORKERS; ++count)
	{
		cout << "User " << count + 1 << ". " << endl;
		user[count].printFullStory();
		cout << endl << endl;
	}

	//
	string endRun;
	getline(cin, endRun);
	//
	return 0;
}