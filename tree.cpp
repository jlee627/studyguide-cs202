/*
CS202 
Program 3
Written by Joshua Lee

This is the balanced tree implementation file. I implemented my balanced tree as a heap, always inserting from the left node till the level is full and then heapifying the contents to order them correctly. This data structure actually holds the data gathered from file. I've implemented the insert,display,remove all, and retrieve functions for my tree but my single remove function I couldn't figure out how to work
*/

#include "tree.h"
#include "string.h"
#include <iostream>
#include <cmath>

using namespace std;

t_node::t_node():left(NULL),right(NULL),parent(NULL)
{
}


t_node::t_node(problem *& toadd)
{
	study = new problem;
	study = toadd;

	importance = toadd->getRank();
}

/*
t_node::t_node(char * totopic, char * toquestion, int torank, int tocomfort)
{
	study = new problem(totopic, toquestion, torank, tocomfort);
	
	importance = torank;
}
*/

t_node::~t_node()
{
	

	delete study;
	left = NULL;
	right = NULL;
	parent = NULL;
}

bool t_node::insert(t_node *& root, problem *& toadd, int lvl, int curlvl)//Inserts data into the tree
{
	if(curlvl != lvl){//Find the right level to insert at
		
		//insert at left most node
		bool check = insert(root->left, toadd, lvl, curlvl+1);
		
		//making sure to insert at right node when available 
		if(check == false)//Checks to see if left node was already inserted
			check = insert(root->right, toadd, lvl, curlvl+1);//insert right
		return check;
	}
	if(!root->left && curlvl == lvl){//Insert left if at the right level
		t_node * temp = new t_node(toadd);//new node

		root->setLeft(temp);//set info
		temp->setParent(root);
		temp->setLeft(NULL);
		temp->setRight(NULL);
		return true;//Let us know it inserted left
	}
	else if(!root->right && curlvl == lvl){//Insert at the lowest level
		t_node * temp = new t_node(toadd);//new node

		root->setRight(temp);//set info
		temp->setParent(root);
		temp->setLeft(NULL);
		temp->setRight(NULL);
		return true;//let us know it inserted right
	}

	return false;//Didn't insert return fail 
/*
	if(!root){//no tree
		//t_node * temp = new t_node(totopic,toquestion,torank,tocomfort);
		t_node * temp = new t_node(toadd);
		temp->setRight(NULL);
		temp->setLeft(NULL);
	}
	
	if(root->left == NULL){//Insert left
		t_node * temp = new t_node(toadd);

		root->setLeft(temp);
		temp->setParent(root);
		temp->setLeft(NULL);
		temp->setRight(NULL);

		//++heapsize;//Increment counter to keep track of num nodes
		}
	else if(root->right==NULL){//Insert right
		t_node * temp = new t_node(toadd);

		root->setRight(temp);
		temp->setParent(root);
		temp->setLeft(NULL);
		temp->setRight(NULL);

		//++heapsize;//increment counter to keep track of num nodes
		}

	else if(checkLeafs(root->left) == true){//Insert on left side first if it has an empty leaf
		insert(root->left,toadd,levels);	
		}
	else if(checkLeafs(root->right) == true){//Insert if right has room and left is full
		insert(root->right,toadd,levels);
		}
*/	
}

void t_node::retrieve(t_node * root,int find)//Search the tree for a specific node
{

	if(!root)//nothing here
		return;
	if(root->importance == find)//found the right one
		root->study->display();//display info
	
	//Go down list to find it
	retrieve(root->getLeft(),find);
	retrieve(root->getRight(),find);

}

void t_node::display(t_node * root)//recursive display function to display tree
{
	if(!root)//nothing here
		return;

	root->study->display();//display contents
	
	//Recursively call display on left and right leafs
	display(root->getLeft());
	display(root->getRight());
	
	
}

void t_node::remove(t_node *& root)//recursive remove function to delete tree
{
	if(!root)//nothing here
		return;

	remove(root->getRight());//go down tree
	remove(root->getLeft());

	delete root;//delete tree
	root = NULL;
}

//Copy everything but the item and delete the one we don't want
void t_node::remove(t_node *& root, t_node *& dest, int find)
{
/*
	if(!root)
		return;

	if(!dest && root->importance != find){//If there is no tree 
		problem temp = new problem(root->study);
		dest = new t_node(temp);

		dest->setRight(NULL);
		dest->setLeft(NULL);
		
		remove(root->getLeft(),dest->getLeft(),find);
		remove(root->getRight(),dest->getRight(),find);
	}
	else if(!dest &&
	else{
		int levels = root->findHeight(root);//Count the levels in the tree
		int curlvl = 0;//Set starting level of implementation
		root->insert(root,toadd,levels,curlvl); //Then insert via the tree insert function
	if(root->importance == find){//found node		
		t_node * temp = root;
		}


	remove(root->getRight(),dest->getRight(),find);
	remove(root->getLeft(),dest->getLeft(),find);
	
	}
*/
}

int t_node::findHeight(t_node * root)//Recursively counts the height of the tree
{
	if(!root)
		return -1;//return -1 in case of null

	int leftHeight = findHeight(root->left);//go down tree to count levels
	int rightHeight = findHeight(root->right);
	
	if(leftHeight < rightHeight)
		return leftHeight + 1;
	else
		return rightHeight + 1;
}
/*
bool t_node::checkLeafs(t_node * root)//Checks to see if right or left leafs are empty
{
	if(root->left == NULL || root->right == NULL)
		return true;
	
	return false;
}
*/
		
t_node *& t_node::getLeft()//get left pointer
{
	return left;
}

t_node *& t_node::getRight()//get right pointer
{
	return right;
}

t_node *& t_node::getParent() //gets parent pointer
{
	return parent;
}

void t_node::setRight(t_node * value) //Sets the right pointer
{
	right = value;
}

void t_node::setLeft(t_node * value) //Sets the left pointer
{
	left = value;
}

void t_node::setParent(t_node * value) //Sets the parent pointer
{
	parent = value;
}

void t_node::heapify(t_node *& root)//Heap sort the tree going all the way down and working up
{
	if(!root)//no  tree
		return;

	heapify(root->left);
	heapify(root->right);

	if(root->left){
		if(root->importance > root->getLeft()->importance){//If roots importance is less than its left leaf
			t_node * temp = root->getLeft();//new parent
			t_node * temp2 = root;//old parent
			t_node * tempright = root->getRight();//old parents right node

			if(root->parent){
				temp->setParent(root->parent);
		
				
			}
			//swap info
			temp2->setLeft(temp->getLeft());
			temp2->setRight(temp->getRight());
			temp2->setParent(temp);			

			temp->setLeft(temp2);
			temp->setRight(tempright);
			root = temp;
		}

	}

	if(root->right){
		if(root->importance > root->getRight()->importance){//Compare to right side now
			t_node * temp = root->getRight();//new parent
			t_node * temp2 = root;//old parent
			t_node * templeft = root->getLeft();//old parent left node

			if(root->parent)
				temp->setParent(root->parent);

		
			//swap info
			temp2->setLeft(temp->getLeft());
			temp2->setRight(temp->getRight());
			temp2->setParent(temp);			

			temp->setLeft(templeft);
			temp->setRight(temp2);
			root = temp;
		}
	}



/*	
	if(root->importance < root->parent->importance){//If this node is less than parents swap it
		t_node * temp = root->parent;
		//t_node * temp2 = root;
		
		if(temp->getLeft() == root){//The left node is the correct one to swap
			if(temp){
				parent->setRight(root->getRight());
				parent->setLeft(root->getLeft());
				parent->setParent(root);
			}

			root = temp;
			root->setRight(temp->getRight());
			root->setLeft(parent);
			root->setParent(temp->getParent());

			if(root->getRight())//Correct right leaf's parent too
				root->getRight()->setParent(root);
		
		}
		else{ //The right node is the correct one to swap
			parent->setRight(root->getRight());
			parent->setLeft(root->getLeft());
			parent->setParent(root);

			root = temp;
			root->setRight(parent);
			root->setLeft(temp->getLeft());
			root->setParent(temp->getParent());
			
			if(root->getLeft())//Fix left leaf's parent too
				root->getLeft()->setParent(root);
		}
	}
*/
}
