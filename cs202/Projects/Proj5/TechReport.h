#ifndef TECHREPORT_H
#define TECHREPORT_H
/******************************************************************************
*
* File:    TechReport.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Larson (from a skeleton by John Park)
* Date:    12/03/2014
* Section: 7
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the TechReport class, which
* is derived from the Report class.  It inherits many data and function
* members from Report.
*
******************************************************************************/

#include <string>
#include <vector>
#include "Report.h"
#include "BadResponseException.h"


class Comment;

#define DOC_TYPE_TECHREPORT 4

class TechReport : public Report {
public:

/***************************************************************
 * TechReport():
 * No arg constructor
 * Preconditions: 
	none
 * Postconditions: 
	none
 ****************************************************************/
	TechReport();
 /***************************************************************
 * TechReport():
 * Standard constructor
 * Preconditions: ID, author, title, body
 * Postconditions: constructs a TechReport with all of the above data members
 ****************************************************************/
    TechReport(int aID, std::string author, std::string title,
	       std::string textBody);
   
 /****************************************************************
 * CreateResponse():
 * Preconditions: 
 *	  author, textBody, nextID
 * Postconditions:
 *   Returns: Creates a response to the selected TechReport in the form 
 * of a comment.  No new document is created.
 ****************************************************************/
    virtual TechReport *CreateResponse(std::string author, std::string textBody, int nextID);

/****************************************************************
 * DisplayBody():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   Returns: The data member m_textBody
 ****************************************************************/	
	
	virtual void DisplayBody();
	
/****************************************************************
 * Search():
 * Preconditions: 
 *	  searchString
 * Postconditions:
 *   Returns: A boolean value of true if the contents of searchString
 * are found within the TechReport or it's comments.
 ****************************************************************/
	virtual bool Search(std::string searchString);
	
private:
    std::vector<Comment> m_comments;

};


class Comment {
 public:
    std::string m_author;
    std::string m_textBody;

    //-------------------------------------------------------------------------
    // Name: Comment (constructor)
    // PreCondition:  None.
    // PostCondition: Initializes the author and textBody fields
    //-------------------------------------------------------------------------
    Comment(std::string author = "", std::string textBody = "")
	: m_author(author), m_textBody(textBody) {}
	
	
	
};

#endif
