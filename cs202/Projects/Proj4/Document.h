/****************************************************************
 * File:    Document.h
 * Project: CMSC 202 Project 4, Spring 2014
 * Author:  John Larson
 * Date:    11/22/2014
 * Section: all
 * E-mail:  larson3@umbc.edu 
 *
 *
 ****************************************************************/

#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <iostream>
#include <string>

using namespace std;

class Document {
public:
    Document();
	
    int GetType();

private:
    int m_type;

public:
	/****************************************************************
     * Document():
     * Standard constructor
     * Preconditions: ID, author, body, type
     * Postconditions: constructs a Document with all of the above data members
     ****************************************************************/
	Document(int ID, std::string author, std::string body, int type);

	/****************************************************************
     * GetAuthor():
     * Preconditions: 
	 *	  none
     * Postconditions:
     *   Returns: The data member m_author
     ****************************************************************/
	string GetAuthor();
	
	/****************************************************************
     * GetBody():
     * Preconditions: 
	 *	  none
     * Postconditions:
     *   Returns: The data member m_body
     ****************************************************************/
    string GetBody();
	
	/****************************************************************
     * GetID():
     * Preconditions: 
	 *	  none
     * Postconditions:
     *   Returns: The ID member m_author
     ****************************************************************/
	int GetID();
		
	/****************************************************************
     * DisplayHeader():
     * Preconditions: 
	 *	  none
     * Postconditions:
     *   Prints the values available in the document base class, should be overwritten
     ****************************************************************/
	void DisplayHeader();
	
	/****************************************************************
     * DisplayBody():
     * Preconditions: 
	 *	  none
     * Postconditions:
     *   Prints the document's body
     ****************************************************************/
	void DisplayBody();
	
private:
	std::string m_author;
	
	std::string m_body;

	int m_ID;

};

#endif
