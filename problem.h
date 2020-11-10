/*
CS202
Program 3
Written by Joshua Lee

This is the problem  header file. The problem class holds the question for the
topic and also includes a rank and comfortablity level. The rank lets me know how 
important the question is and where it should be sorted in its data structure.
*/
#include "topic.h"

class problem: public topic
{
	public:
		problem();
		problem(const problem & obj);
		problem(char * totopic, char * toquestion, int torank, int tocomfort);
		~problem();

		void display();//Displays all the information for the topic
		int getRank();//Returns the rank number

		problem& operator=(const problem & obj);//Overloaded assignment operator
		bool operator==(const problem & obj) const;//Comparison operator overloaded
		
	private:
		char * question;
		int rank;
		int comfort;
};
