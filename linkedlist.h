/*
CS202
Program 3
Written by Joshua Lee

This is the header file for both my linked list and ll_node class which holds together
my linear linked list of balanced trees. My ll_node class contains the balanced trees 
as well as the pointer to the next node in the linear linked list, and I've implemented the retrieve, display, insert, remove, and remove all functions.
*/

#include "tree.h"

class ll_node
{
	public:
		ll_node();
		~ll_node();

		void retrieve(ll_node *& next, char * toretrieve);//Looks for a single item to display
		void display(ll_node * head);//Recursive display all function
		bool remove(ll_node *& head,char * toremove);//Removes only 1 node
		void remove_all(ll_node *& head);//Recursively delete list

		//char * getTopic();
		ll_node *& getNext(); //Gets the next pointer for a node
		void heapify(ll_node * head);//heap sorts the trees

		bool remove(ll_node *& head, char * toremove, int find);
		void retrieve(ll_node * head, char * toretrieve, int find);
	
		void insert(ll_node *& head, problem *& toadd); //Inserts data into list
		void inserttree(t_node *& root,problem *& toadd);//Wrapper function to insert tree
	private:
		ll_node * next; 
		t_node * root; //Root for the tree
		char * topicname; //Saves the topic in the linked list to know where to input
		
		void setNext(ll_node * value); //Sets the next pointer for a node
};

class linkedlist
{
	public:
		linkedlist();
		~linkedlist();
		
		void insert();//Insert function to read from file
		void retrieve(char * toretrieve);//Displays user specified topic
		void display();//Displays all content
		void remove_all(ll_node * head);//Deletes entire list
		void remove(char * toremove);//Removes user specified topic data

		void retrieve(char* toretrieve, int find);//retrieve from the balanced tree
		void remove(char * toretrieve, int find);//remove from the balanced tree
	private:
		ll_node * head;
};
