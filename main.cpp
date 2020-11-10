/*
CS202
Program 3
Written by Joshua Lee

This is my main implementation file that acts purely as a menu that makes calls to the data structure
linear linked list of balanced trees. The user can ask to display specific data or remove specific data 
as well as display all data.
*/
#include "linkedlist.h"
#include <iostream>

using namespace std;

void menu(linkedlist & studyguide);//Menu for the list

int main()
{
	linkedlist studyguide;
	studyguide.insert();//Reads in from file and inserts into data structure

	cout << "Study guide loaded." << endl << endl;
	
	menu(studyguide);//Calls menu

	return 0;
}

void menu(linkedlist & studyguide)
{
	int choice = 0;
	int max_size = 150;
	char answer[max_size];
	int temp = 0;
	
	do{
		cout << "1) Display Entire study guide" << endl;
		cout << "2) Display materials for a single topic" << endl;
		cout << "3) Display a specific question for a topic" << endl;
		cout << "4) Remove a topic from the study guide" << endl;
		cout << "5) Remove a specific question from a topic" << endl; //Doesn't work :[
		cout << "6) Quit" << endl << endl;
		cout << "What would you like to do? :" << endl;
		cin >> choice;
		cin.ignore();

		switch(choice){
			case 1:
				studyguide.display();//Display all
				break;
			case 2:
				cout << "What topic would you like to retrieve?: " << endl;//Find out what the user wants to get
				cin.get(answer,max_size);
				cin.ignore();

				studyguide.retrieve(answer);//Calls linkedlist retrieve function
				break;
			case 3:
				cout << "From which topic is your question?: " << endl;//Find out where the user's desired question is
				cin.get(answer,max_size);
				cin.ignore();
				
				cout << "What is the importance of your question?(1-5): " << endl;//search by rank for the item
				cin >> temp;
				cin.ignore();
				
				studyguide.retrieve(answer,temp);
				break;
			case 4:
				cout << "What topic would you like to delete?: " << endl;// find out what the user wants to delete
				cin.get(answer,max_size);
				cin.ignore();

				studyguide.remove(answer);//calls remove function
				break;
			case 5:
				cout << "From which topic is your question?: " << endl;//find out where the user's desired question is
				cin.get(answer,max_size);
				cin.ignore();
				
				cout << "What is the importance of your question?(1-5): " << endl;//search by rank for the item
				cin >> temp;
				cin.ignore();
				
				//studyguide.remove(answer,temp);//calls remove function //**Commented out because it doesnt work
				break;
			case 6: 
				cout << "Exiting program . . . ." << endl;
				break;
			default:
				cout << "Invalid option" << endl << endl;
				break;

			}
	}while(choice != 6);
}
