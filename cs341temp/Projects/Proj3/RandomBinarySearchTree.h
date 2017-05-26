#ifndef RANDOMBINARYSEARCHTREE_H
#define RANDOMBINARYSEARCHTREE_H
/******************************************************************************
*
* File:    RandomBinarySearchTree.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    03/24/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the RandomBinarySearchTree class
*
******************************************************************************/


#include "BinarySearchTree.h"
#include <fstream>
#include <cstdlib>
#include <string>

template <typename Comparable>
class RandomBinarySearchTree : public BinarySearchTree <Comparable>
{
	public:
	//these public functions exist to aid in calls from driver!
/****************************************************************
* RandomBinarySearchTree():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   constructs the random number generator
 ****************************************************************/

		RandomBinarySearchTree() : root(NULL)
		{
			srand(123456789);
		}
	
/****************************************************************
 * RandomBinarySearchTree(rhs):
 * Preconditions: 
 *	  rhs
 * Postconditions:
 *  
 ****************************************************************/
		RandomBinarySearchTree( const RandomBinarySearchTree & rhs ) : root( NULL )
		{
			*this = rhs;
		}
		
/****************************************************************
 * ~RandomBinarySearchTree():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   calls makeEmpty() which will clear the tree
 ****************************************************************/
		~RandomBinarySearchTree( )
		{
			makeEmpty( );
		}

/****************************************************************
 * makeEmpty():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   calls the one arg makeEmpty which will clear the tree from root
 ****************************************************************/		
		void makeEmpty( )
		{
			makeEmpty( root );
		}

/****************************************************************
 * insert(x):
 * Preconditions: 
 *	  a valid comparable element
 * Postconditions:
 *   will call the 2 arg insert constructor
 ****************************************************************/		
		virtual void insert( const Comparable & x )
		{
			insert( x, root );
		}

/****************************************************************
 * height():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   calls the one-arg height and will return the result minus one
 ****************************************************************/		
		int height()
		{
			//we subtract one because for some reason the program thinks
			//its funny to return the wrong height
			return height(root)-1;
		}

/****************************************************************
 * levelOrder(length,out):
 * Preconditions: 
 *	 int called length and an output object
 * Postconditions:
 *   will call the three arg constructor
 ****************************************************************/
		void levelOrder(int length,ostream &out=cout)
		{
			return levelOrder(root,length,out);
		}
		
	private:
		//this struct includes size of the current subtree, this is only
		//important in rbst
	    struct BinaryNode
		{
		Comparable element;
        BinaryNode *left;
        BinaryNode *right;
		int size;
		//size is always 1 in a single node
        BinaryNode( const Comparable & theElement, BinaryNode *lt, BinaryNode *rt )
            : element( theElement ), left( lt ), right( rt ) {size=1;}
		};

		BinaryNode *root;
		
/****************************************************************
 * insert(x,t):
 * Preconditions: 
 *	  a valid comparable element and node
 * Postconditions:
 *   this function ill generate a new random number and compare it to the
 *   size of the subtree.  If they are the same it will call insertAtRoot
 *   if not it will continue to move along the tree as if it were a regular bst
 ****************************************************************/	
		virtual void insert( const Comparable & x, BinaryNode * & t )
		{
			int r,n;
			//as long as we haven't found an empty node
			if(t!=NULL)
			{
				
			n = getSize(t);
			//needs to be n+1 to count for 0
			r = nextInt(n+1);
		
				//checking for equality		
				if(r==n)
				{		
					insertAtRoot(x,t);
				}
				else if(t->element>x)
				{
					insert(x,t->left);
				}
				else if(t->element<x)
				{
					insert(x,t->right);
				}
				else
				{
					//just in case
				}
			}
			//we found an empty node, making a new leaf node
			else
			{
				
				t = new BinaryNode(x,NULL,NULL);
				
			}
			//just to be safe
			updateSize(t);
			
		}

/****************************************************************
 * insertAtRoot(x,t):
 * Preconditions: 
 *	  a valid comparable element and binaryNode
 * Postconditions:
 *   this will be called if the insert function finds a match.  What is happening
 *	 here is we recursively call the function until we can create a new
 *   leaf node.  Once the leaf node is created we move back through the 
 *   tree, flipping the whole way.
 ****************************************************************/			
		void insertAtRoot(const Comparable & x, BinaryNode * & t)
		{
			if(t==NULL)
			{				
				t = new BinaryNode( x, NULL, NULL );
				
			}
			else if( x<t->element)
			{
				insertAtRoot(x,t->left);
				rotateLeft(t);
			}
			else
			{
				insertAtRoot(x,t->right);
				rotateRight(t);
			}
		}

/****************************************************************
 * rotateLeft(*k2):
 * Preconditions: 
 *	  a valid binaryNode
 * Postconditions:
 *   should be named rotateRight, but I'm not fixing it.  This will
 *	 rotate k2 with its left child and handle all relevant children
 ****************************************************************/		
	void rotateLeft( BinaryNode* & k2 )
	{
		BinaryNode *k1 = k2->left;
		k2->left = k1->right;
		k1->right = k2;
		k2 = k1;
		updateSize(k2);
	}

/****************************************************************
 * rotateRight(*k1):
 * Preconditions: 
 *	  a valid binaryNode
 * Postconditions:
 *   should be named rotateLeft, but I'm not fixing it.  This will
 *	 rotate k2 with its right child and handle all relevant children
 ****************************************************************/	
	void rotateRight( BinaryNode * & k1 )
    {
        BinaryNode *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1 = k2;
		updateSize(k1);
    }

/****************************************************************
 * height(*t):
 * Preconditions: 
 *	  a valid binaryNode
 * Postconditions:
 *   will return the height of the deepest node in the entire tree
 ****************************************************************/	
	int height ( BinaryNode *t )
	{
		if (t == NULL)
		{
			return 0;
		}
		else
		{
			int lSide = height(t->left);
			int rSide = height(t->right);
			if(lSide > rSide)
			{
				return lSide+1;
			}
			else
			{
				return rSide+1;
			}
		}
		
	}
	
	
/****************************************************************
 * levelOrder(*t,length,out):
 * Preconditions: 
 *	  a valid binaryNode, int length and ostream operator
 * Postconditions:
 *   will print the entirety of the tree level by level to a valid
 *   object of type ostream
 ****************************************************************/
	void levelOrder(BinaryNode *t,int length,ostream &out) {
		int count = 0;
		if (t==NULL) 
		{
			cout<<"Empty tree"<<endl;
			return;
		}
	
		queue<BinaryNode*> currentLevel;
		queue<BinaryNode*> nextLevel;
		currentLevel.push(t);
		out<<"Level "<<count<<": ";
		while (!currentLevel.empty()&&count<=length) {
			BinaryNode *current = currentLevel.front();
			currentLevel.pop();
			if (current!=NULL) 
			{
				out << current->element << " ";
				nextLevel.push(current->left);
				nextLevel.push(current->right);
			}
			if (currentLevel.empty()) 
			{
				out << endl;
				count++;
				if(!nextLevel.empty()&&count<=length)
				{
					if(height(t)>count)
					{
					out<<"Level "<<count<<": ";
					}
				}
				swap(currentLevel, nextLevel);
			}
		}
	}
	
/****************************************************************
 * getSize(*t):
 * Preconditions: 
 *	  a valid binaryNode
 * Postconditions:
 *   will return the number of nodes in a given subtree
 ****************************************************************/
	int getSize(BinaryNode* t)
	{
		if(t==NULL)
		{
			return 0;
		}
		else
		{
			return t->size;
		}
	}

/****************************************************************
 * updateSize(*t):
 * Preconditions: 
 *	  a valid binaryNode
 * Postconditions:
 *   Will add the values of the node and it's two children.  The
 *   children themselves should be already updated.
 ****************************************************************/	
	void updateSize(BinaryNode* t)
	{
		t->size = getSize(t->left)+getSize(t->right)+1;
	}
	
//from author's code	
    void makeEmpty( BinaryNode * & t )
    {
        if( t != NULL )
        {
            makeEmpty( t->left );
            makeEmpty( t->right );
            delete t;
        }
        t = NULL;
    }

/****************************************************************
 * nextInt(size):
 * Preconditions: 
 *	  a integer
 * Postconditions:
 *    will return a "random" number based on the size brought in
 ****************************************************************/	
	int nextInt(int size)
	{
		return (rand() % (size));
	}

};

#endif