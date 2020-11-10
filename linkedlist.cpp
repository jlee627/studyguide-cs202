/*
CS202
Program 3
Written by Joshua Lee

This is the implementation file for both my linked list and ll_node class which holds together
my linear linked list of balanced trees. My ll_node class contains the balanced trees 
as well as the pointer to the next node in the linear linked list, and I've implemented the retrieve, display, insert, remove, and remove all functions.
*/

#include "linkedlist.h"
#include "string.h"
#include <iostream>
#include <fstream>

using namespace std;

ll_node::ll_node():topicname(0),next(NULL),root(NULL)//Default Constructor
{}

ll_node::~ll_node()//Destructor
{
	delete [] topicname;
	next = NULL;
	
	if(root)
		root->remove(root);//calls delete on whole tree
	
	root = NULL;

}

void ll_node::insert(ll_node *& head, problem *& toadd)//Inserts into the linked list
{
	if(!head){//No list
		ll_node * temp = new ll_node;//Make new linkedlist node
		temp->setNext(NULL);//set next to null

		//Set the topic for the node
		temp->topicname = new char[strlen(toadd->getTopic()) + 1];
		strcpy(temp->topicname,toadd->getTopic());
		
		head = temp;//set head to temp

		inserttree(temp->root,toadd);//Add to the tree stored in the linked list
		
	}

	if(strcmp(head->topicname,toadd->getTopic())== 0){//If the topic is the same insert in tree
		int levels = head->root->findHeight(head->root);//Count the levels in the tree
		int curlvl = 0;//Set starting level of implementation
		head->root->insert(head->root,toadd,levels,curlvl);
		
		head->root->heapify(head->root);
	}

	else if(head->next == NULL){//End of list - make new node and insert there
		ll_node * temp = new ll_node;//Make a new linkedlist node
		head->setNext(temp); //connect new node to list
		temp->setNext(NULL); //set end of list

		//Set the topic for the node
		temp->topicname = new char[strlen(toadd->getTopic()) + 1];
		strcpy(temp->topicname,toadd->getTopic());

		inserttree(temp->root,toadd);//Insert to tree
	}

	else
		insert(head->next,toadd);//Next node if no match/not empty
}

void ll_node::inserttree(t_node *& root, problem *& toadd)//Wrapper function to make a tree 
{
	if(!root){//If there is no tree make one
		t_node * temp = new t_node(toadd);//Add node
		temp->setRight(NULL);
		temp->setLeft(NULL);

		root = temp;//Set root to temp
	}
	else{
		int levels = root->findHeight(root);//Count the levels in the tree
		int curlvl = 0;//Set starting level of implementation
		root->insert(root,toadd,levels,curlvl); //Then insert via the tree insert function
	}
}	

void ll_node::retrieve(ll_node *& head, char * toretrieve)//Retrieves only a specific topic
{
	if(!head){//End of list/no list
		cout << "Information not found." << endl;
		return;
	}

	if(strcmp(head->topicname,toretrieve) == 0){//Object found
		int levels = head->root->findHeight(head->root);
		int curlvl = 0;		
		int counter = 0;
		head->root->display(head->root);
		}

	else
		retrieve(head->next,toretrieve);//Keep searching for item
}

void ll_node::display(ll_node * head)//Displays contents of whole list level by level
{
	if(!head)//If nothing here
		return;
	int levels = root->findHeight(root) + 1;//get tree height
	int curlvl = 0;//Set starting lvl
	int counter = 0;
	head->root->display(head->root);//Display contents in the tree
	display(head->next);//recursive call to traverse list
}

bool ll_node::remove(ll_node *& cur, char * toremove)//Recursively searches through list and removes specific node
{
	if(!cur){//If there is no list exit the remove function
		//cout << "Information not found." << endl;
		return false;//return failure
	}

	if(strcmp(cur->topicname,toremove) == 0){//The first node is a match
		ll_node * temp = cur;

		cur = cur->getNext();//Set head to next 
		//cur->setNext(cur->getNext());//Connect remains of list

		//temp->root->remove(temp->root);//Delete contents of tree for found node
		delete temp->root;
		temp->root = NULL;

		delete temp;//Delete temp
		temp = NULL;
		
		return true;//Return success
	}	

	if(!cur->next){//If next node is NULL return
		//cout << "Information not found." << endl;
		return false;//Return failure
	}
	
	if(strcmp(cur->next->topicname,toremove)==0){//Checks if next node has the information
		ll_node * temp = cur->next;//Sets cur to the next node and connects the list
		cur->next = temp->next;
		
		temp->root->remove(temp->root);//Delete tree first
		temp->root = NULL;
		
		delete temp; //Delete the node
		//temp = NULL;
		
		return true;	//exit the remove function
	}
	
	return remove(cur->getNext(),toremove); //Search next node
}

bool ll_node::remove(ll_node *& cur, char * toremove, int find)//Searches the linked list for right topic 
{
/*
	if(!cur)//not found or no list
		return false;

	if(strcmp(cur->topicname,toremove)==0){//found item
		t_node * tocopy;

		if(cur->root){

			if(cur->root->getImport
			

			 cur->root->remove(cur->root,tocopy, find);//Calls tree node removal 
		
			if(cur->root){
				cur->root->heapify(tocopy);//sorts after removing
				cur->root = tocopy;//sets root to the new list
					return true;
				}
		}
				return false;
	}

	return remove(cur->getNext(),toremove,find);//go through linked list to find right topic
*/
}


void ll_node::retrieve(ll_node * cur, char * toretrieve, int find)
{
	if(!cur)//topic not found or no list
		return;
	if(strcmp(cur->topicname,toretrieve)==0)//found item
		cur->root->retrieve(cur->root, find);

	retrieve(cur->getNext(), toretrieve, find);

}
/*
void ll_node::heapify(ll_node * head)//Heapsorts the list
{
	if(!head)//no list
		return;
		
	if(head->root)//if there's a root heap sort it
		head->root->heapify(head->root);

	heapify(head->getNext());// go to the next node in linked list
}*/

void ll_node::remove_all(ll_node *& head)
{

}
		
void ll_node::setNext(ll_node * value)//Sets next value of node
{
	next = value;
}

ll_node *& ll_node::getNext()//Returns next value of node
{
	return next;
}

////////////////////////////////////////////////////////////////
//////                  linkedlist                       ///////
////////////////////////////////////////////////////////////////

linkedlist::linkedlist():head(NULL)
{
}

linkedlist::~linkedlist()
{
/*
	if(head->getNext() != NULL){
		remove_all(head->getNext());
	}
	
	delete head;
	head = NULL;
*/
}

//Reads from file to insert into data structure
void linkedlist::insert()
{
	//Temp variables to read in the file
	int max_size = 150;
	char tempname[max_size];
	char tempquestion[max_size];
	int temprank = 0;
	int tempcomfort= 0;

	//Temp problem object to insert and use copy constructors
	problem * tempproblem;

	ifstream infile;
	infile.open("guide.txt");//Open file
	
	//Read from file
	if(infile){
		infile.get(tempname,max_size,';');
		infile.ignore(100,';');

		while(!infile.eof()){//Read in stuff while not end

			infile.get(tempquestion,max_size,';');
			infile.ignore(100,';');
			
			
			infile >> temprank;
			infile.ignore(100,';');

			infile >> tempcomfort;
			infile.ignore(100,'\n');

			tempproblem = new problem(tempname,tempquestion,
								temprank,tempcomfort);
			
			head->insert(head,tempproblem);//Calls node insert function

			infile.get(tempname,max_size,';');
			infile.ignore(100,';');
		}
	}

	//if(head)//Theres a list
}

void linkedlist::retrieve(char * toretrieve)//Finds and displays information for a specific information
{
	head->retrieve(head,toretrieve);//Wrapper calls ll_node retrieve function
}

void linkedlist::display()//Displays the contents of the whole list
{
	if(head)
		head->display(head);
	else 
		cout << "No list loaded." << endl;

}

void linkedlist::remove_all(ll_node * head)//Recursively remove all
{
	if(head->getNext() != NULL)
		remove_all(head->getNext());

	delete head;
	head = NULL;
}

void linkedlist::remove(char * toremove)//Removes a user specificed topic from the list 
{
	bool success = false;
	if(head){//If there is a list do stuff
		success = head->remove(head,toremove);

		if(success == true)//Success message if correctly done
			cout << "Information removed." << endl;
		else
			cout << "Unable to find/remove information." << endl;		

	}

	else//no list 
		cout << "No list loaded." << endl;
}

void linkedlist::retrieve(char * toretrieve, int find)
{
	head->retrieve(head,toretrieve,find);
}

void linkedlist::remove(char * toremove, int find)
{
	bool success = false;
	
	if(head){//if there is a list do stuff
		success = head->remove(head,toremove,find);//calls node remove function
	
		if(success = true)//success message based on whether or not removed
			cout << "Information removed." << endl;
		else
			cout << "Unable to find/remove information." << endl;
	}
}	
