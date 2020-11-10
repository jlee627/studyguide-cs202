/*
CS202
Program 3
Written by Joshua Lee

This is the implementation file for the topic class which is responsible 
for holding and setting the name of the topic. I also have overloaded
assignment and comparison operators to set data for the class and a 
getter to return the name of the class as well.
*/
#include "topic.h"
#include "string.h"

using namespace std;

topic::topic()
:name(0)
{}

topic::~topic()
{
	delete [] name;
}

topic::topic(char * toname)
{
	name = new char[strlen(toname)+1];
	strcpy(name,toname);
}

topic::topic(const topic & obj)
{
	name = new char[strlen(obj.name)+1];
	strcpy(name,obj.name);
}
		
topic& topic::operator=(const topic & obj)
{
	if(this == &obj)//Checks if duplicate information is in there
		return *this;

	if(this->name)//Allocate room to override old name
		delete [] name;

	this->name = new char[strlen(obj.name)+1];
	strcpy(this->name,obj.name);
	
	return *this;
}

bool topic::operator==(const topic & obj) const //Checks if content is already in there
{
	if(strcmp(this->name,obj.name)==0)
		return true;
	
	return false;
}

char * topic::getTopic()
{
	return name;
}
