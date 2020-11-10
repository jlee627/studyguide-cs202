/*
CS202 
Program 3
Written by Joshua Lee

This is the balanced tree header file. I tried to implement my balanced tree as a heap this time, and while for the most part it worked, I couldn't figure out how to remove a single item from the tree. The nodes for my tree that have left,right, and parent pointers so that I can heapsort the tree and swap things around as necessary.  Along side the required insert,retrieve,display, and remove all functions I also have the findheight function that tells me the levels of the tree and the heapify function that heapsorts the tree, but I couldn't find out how to make my single remove to work with my structure. 
*/

#include "problem.h"

class t_node
{
	public:
		t_node();
		t_node(problem *& toadd);
		//t_node(char * totopic, char * toquestion, int torank, int tocomfort);
		~t_node();

		bool insert(t_node *& root, problem *& toadd,int levels,int curlvl);//Inserts data into tree
		void retrieve(t_node * root,int tofind);//Finds and displays content based on topic
		void display(t_node * root);//Displays contents of the tree
		void remove(t_node *& root);//Removes nodes from tree
		void remove(t_node *& root,t_node *& source, int tofind);//copies a new tree without the item specified for removal **DOESNT WORK** :[
	int findHeight(t_node * root);//Counts how many levels are in the tree
		
		void heapify(t_node *& root);//heapsorts the tree

		//setters and getters
		t_node *& getLeft(); 
		t_node *& getRight();
		t_node *& getParent();

		void setParent(t_node * value);
		void setRight(t_node * value);
		void setLeft(t_node * value);
	private:
		t_node * left;
		t_node * right;
		t_node * parent;
		
		int importance;
		problem * study;
};
