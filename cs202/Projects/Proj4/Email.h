/****************************************************************
 * File:    Email.h
 * Project: CMSC 202 Project 4, Spring 2014
 * Author:  John Larson
 * Date:    11/22/2014
 * Section: all
 * E-mail:  larson3@umbc.edu 
 *
 *
 ****************************************************************/

#ifndef EMAIL_H
#define EMAIL_H

#include <string>
#include <cstdlib>
#include "Document.h"

const int DOC_TYPE_EMAIL = 0;

using namespace std;

class Email : public Document
{
	public:
	/****************************************************************
     * Email():
     * Default constructor
     * Preconditions: none
     * Postconditions: A bunch of empty strings
     ****************************************************************/
	Email();
		
	/****************************************************************
     * Email():
     * Standard constructor
     * Preconditions: ID, author, subject, recipient, dist list, body
     * Postconditions: constructs a Email with all of the above data members
     ****************************************************************/
	Email(int ID,string author,string subject,string recipientName, string recipientEmail,string textBody);
	  
	 /****************************************************************
     * DisplayHeader():
     * Preconditions: 
	 *	  none
     * Postconditions:
     *   Prints the values available in the Email class
     ****************************************************************/
	void DisplayHeader();

	  
	private:
	string m_subjectLine;
	string m_primary;
	string m_recipEmail;
		
};
#endif