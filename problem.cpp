/*
CS202
Program 3
Written by Joshua Lee

This is the implementation file for the problem class. It's primary function is to
hold and display information while also containing the overloaded assignment and comparison
operators to set new data.

*/
#include "problem.h"
#include "string.h"
#include <iostream>

using namespace std;

problem::problem()
:question(0),rank(0),comfort(0)
{}

problem::problem(const problem & obj)//Copy constructor
{
	question = new char[strlen(obj.question)+1];
	strcpy(question,obj.question);	

	rank = obj.rank;
	comfort = obj.comfort;
}

problem::problem(char * toname, char * toquestion, int torank, int tocomfort)
:topic(toname)//overloaded constructor
{
	question = new char[strlen(toquestion) + 1];
	strcpy(question,toquestion);
	
	rank = torank;
	comfort = tocomfort;
}

problem::~problem()//destructor
{
	delete [] question;
}

void problem::display()//Displays the information
{
	cout << "Topic:\t\t\t" << name << endl;
	cout << "Question:\t\t" << question << endl;
	cout << "Importance:\t\t" << rank << endl;
	cout << "Comfort level:\t\t" << comfort << endl << endl;
}		

int problem::getRank()//returns rank number for reference
{
	return rank;
}

problem& problem::operator=(const problem & obj)//Overloaded assignment operator that sets data
{
	if(this == &obj)//Makes sure no duplicates get through
		return *this;

	if(this->question)//deletes stuff if its there
		delete [] question;

	//copies stuff
	this->question = new char[strlen(obj.question)+1];
	strcpy(this->question,obj.question);

	this->rank = obj.rank;
	this->comfort = obj.comfort;

	topic::operator=(obj);//call topic class overloaded assignment operator

	return *this;
}

bool problem::operator==(const problem & obj) const //Overloaded to check to see if it is already occupied
{
	if(strcmp(this->question,obj.question) == 0)
		return true;

	return false;
}



