#ifndef REPORT_H
#define REPORT_H

/******************************************************************************
*
* File:    Report.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Larson (from a skeleton by John Park)
* Date:    12/03/2014
* Section: 7
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the Report class, which
* is derived from the Document class.  It inherits many data and function
* members from Document.
******************************************************************************/


#include <string>
#include "Document.h"
#include "BadResponseException.h"

class Report : public Document {
public:
	Report();
	virtual ~Report();
    Report(int aID, std::string author, std::string title,
	   std::string textBody);
    std::string GetTitle();
    virtual void DisplayHeader();

 /****************************************************************
 * CreateResponse():
 * Preconditions: 
 *	  author, textBody, nextID
 * Postconditions:
 *   Returns: This just tells the user they are doing something illegal
 * and they should probably stop before the authorities are called.
 ****************************************************************/
    virtual Report *CreateResponse(std::string author, std::string textBody, int nextID);

private:
    std::string m_title;
};

#endif
