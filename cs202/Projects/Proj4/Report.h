/****************************************************************
 * File:    Report.h
 * Project: CMSC 202 Project 4, Spring 2014
 * Author:  John Larson
 * Date:    11/22/2014
 * Section: all
 * E-mail:  larson3@umbc.edu 
 *
 *
 ****************************************************************/

#ifndef REPORT_H
#define REPORT_H

#include <string>
#include <cstdlib>
#include "Document.h"

const int DOC_TYPE_REPORT = 2;

using namespace std;

class Report : public Document
{
	public:
	/****************************************************************
     * Report():
     * Default constructor
     * Preconditions: none
     * Postconditions: A bunch of empty strings
     ****************************************************************/
	Report();
		
	/****************************************************************
     * Report():
     * Standard constructor
     * Preconditions: ID, author, subject, recipient, dist list, body
     * Postconditions: constructs a Document with all of the above data members
     ****************************************************************/
	Report(int ID, string author, string subject,string textBody);
	  
	 /****************************************************************
     * DisplayHeader():
     * Preconditions: 
	 *	  none
     * Postconditions:
     *   Prints the values available in the Report class
     ****************************************************************/
	void DisplayHeader();

	  
	private:
	string m_subjectLine;
		
};
#endif