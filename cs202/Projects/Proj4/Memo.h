/****************************************************************
 * File:    Memo.h
 * Project: CMSC 202 Project 4, Spring 2014
 * Author:  John Larson
 * Date:    11/22/2014
 * Section: all
 * E-mail:  larson3@umbc.edu 
 *
 *
 ****************************************************************/

#ifndef MEMO_H
#define MEMO_H

#include <string>
#include <cstdlib>
#include "Document.h"

const int DOC_TYPE_MEMO = 1;

using namespace std;

class Memo : public Document
{
	public:
	/****************************************************************
     * Memo():
     * Default constructor
     * Preconditions: none
     * Postconditions: A bunch of empty strings
     ****************************************************************/
	Memo();
		
	/****************************************************************
     * Memo():
     * Standard constructor
     * Preconditions: ID, author, subject, recipient, dist list, body
     * Postconditions: constructs a Document with all of the above data members
     ****************************************************************/
	Memo(int ID, string author, string subject, string recipientName, string distributionList, string textBody);
	  
	 /****************************************************************
     * DisplayHeader():
     * Preconditions: 
	 *	  none
     * Postconditions:
     *   Prints the values available in the Memo class
     ****************************************************************/
	void DisplayHeader();

	  
	private:
	string m_subjectLine;
	string m_primary;
	string m_distList;
		
};
#endif