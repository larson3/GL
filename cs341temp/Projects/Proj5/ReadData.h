/******************************************************************************
*
* File:   ReadData.h
* Project: CMSC 341 Project 5, Spring 2015
* Author:  John Larson
* Date:    5/8/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the ReadData class.  This class
*	contains the main logic for the program.  It will read in a file then
*	save that file's parsed words in to hash tables for each document it
*	reads.  It will then compare those hash tables and compute the Jaccard
*	similarity for the two.  It will print these results and the highest
*	similarity to an output file named results.txt
*
******************************************************************************/

#ifndef READDATA_H
#define READDATA_H

#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "SoloHash.h"
#include "QuadraticProbing.h"

using namespace std;

class ReadData
{
	public:

/****************************************************************
 * ReadData():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   Basic no arg-constructor
 ****************************************************************/
		ReadData();
		
/****************************************************************
 * ~ReadData():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base destructor
 ****************************************************************/
		~ReadData();
		
/****************************************************************
 * toLower(basic_string<char>&):
 * Preconditions: 
 *	  single char data type
 * Postconditions:
 *   will change the value of any captials it encounters to lower
 ****************************************************************/
		void toLower(basic_string<char>& s);

/****************************************************************
 * openDirectory(char const *):
 * Preconditions: 
 *	  a valid path to directory
 * Postconditions:
 *   will return with an error and exit the program if not valid
 *	 otherwise will open the requested directory and parse the data.
 *   It will then place the parsed data into a vector of hash tables.
 ****************************************************************/
		void openDirectory(char const *dir_name);
		
/****************************************************************
 * calculateJaccard():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   Will create a new outFile, and then iterate through the hashed
 *   vector.  It will compare each element of the vector to every 
 *   other element, including itself.  Will write the resulting highest
 *   match to the outfile.
 ****************************************************************/
		void calculateJaccard();
		
/****************************************************************
 * compare(SoloHash,SoloHash,ostream&):
 * Preconditions: 
 *	  Two valid SoloHash objects, one valid output file
 * Postconditions:
 *    Will calculate the intersection and union of two hash tables by
 *    comparing them using the contains function and then putting them
 *    into a single hash table.  It then calculates the jaccard ratio
 *    by dividing intersection by union.  Finally it will write the
 *	  individual results to an outFile.
 ****************************************************************/
		void compare(SoloHash a, SoloHash b, ostream &out);
	

	private:
		vector<SoloHash>hashList;
		int m_totalSize;
		stringstream ss;
		string rel;
		string line;
		string temp;
		HashTable<string> m_intersection;
		HashTable<string> m_union;
		float m_highestNum;
		string m_highestPairA;
		string m_highestPairB;

};
#endif