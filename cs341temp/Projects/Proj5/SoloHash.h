/******************************************************************************
*
* File:   SoloHash.h
* Project: CMSC 341 Project 5, Spring 2015
* Author:  John Larson
* Date:    5/8/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the SoloHash class.  This class
*	exists to provide an object to store a hash table and a name for that
*	hash table.  It has a lot of setters and getters.
*
******************************************************************************/

#ifndef SOLOHASH_H
#define SOLOHASH_H

#include <string.h>
#include <iostream>
#include "QuadraticProbing.h"
using namespace std;

class SoloHash
{
	public:

/****************************************************************
 * SoloHash():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
		SoloHash();
		
/****************************************************************
 * ~SoloHash():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   runs makeEmpty() on the existing hashTable
 ****************************************************************/
		~SoloHash();
		
/****************************************************************
 * setWord(string):
 * Preconditions: 
 *	  valid string
 * Postconditions:
 *   places the string arg into the hash table
 ****************************************************************/
		void setWord(string word);
		
/****************************************************************
 * getContains():
 * Preconditions: 
 *	  valid interval heap
 * Postconditions:
 *   Returns the size of the current interval heap
 ****************************************************************/

		string getName();
 /****************************************************************
 * getName():
 * Preconditions: 
 *	  none
 * Postconditions:
 *    Returns the value m_name from the current SoloHash object
 ****************************************************************/	


		void setName(string);
/****************************************************************
 * setName(string):
 * Preconditions: 
 *	  valid string arg
 * Postconditions:
 *   Will set the data member m_name to the string arg
 ****************************************************************/
		

		HashTable<string> getHash();
/****************************************************************
 * getHash():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   Returns the data member m_hashTable from the SoloHash object
 ****************************************************************/
	
	bool getHash(string test);
	
	private:
		string m_name;
		HashTable<string> m_hashTable;

		
};
#endif