#ifndef EMAIL_H
#define EMAIL_H

/******************************************************************************
*
* File:    Email.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Larson (from a skeleton by John Park)
* Date:    12/03/2014
* Section: 7
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the Email class, which
* is derived from the Correspondence class.  It inherits many data and function
* members from Correspondence.
*
******************************************************************************/


#include <string>
#include "Correspondence.h"
#include "BadResponseException.h"



class Email : public Correspondence {
public:
    Email(int aID, std::string author, std::string subject,
	  std::string recipientName, std::string recipientEmail,
	  std::string textBody);
   
    std::string GetRecipientEmail();

 /****************************************************************
 * DisplayHeader():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   Returns: Prints the contents of the header section of the Email
 ****************************************************************/
    virtual void DisplayHeader();
   
   
 /****************************************************************
 * CreateResponse():
 * Preconditions: 
 *	  author, textBody, nextID
 * Postconditions:
 *   Returns: Creates a response to the selected Email in the form 
 * of a new document.
 ****************************************************************/
   virtual Email *CreateResponse(std::string author, std::string textBody, int nextID);

private:
   
    std::string m_recipientEmail;
};

#endif
