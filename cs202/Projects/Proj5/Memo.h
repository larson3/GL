#ifndef MEMO_H
#define MEMO_H

/******************************************************************************
*
* File:    Memo.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Larson (from a skeleton by John Park)
* Date:    12/03/2014
* Section: 7
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the Memo class, which
* is derived from the Correspondence class.  It inherits many data and function
* members from Correspondence.
*
******************************************************************************/


#include <string>
#include <vector>
#include "Correspondence.h"
#include "BadResponseException.h"



class Memo : public Correspondence {
public:
    Memo(int aID, std::string author, std::string subject,
	 std::string recipientName, std::vector<std::string> distributionList,
	 std::string textBody);
   
    std::vector<std::string> GetDistributionList();
    virtual void DisplayHeader();
	
 /****************************************************************
 * CreateResponse():
 * Preconditions: 
 *	  author, textBody, nextID
 * Postconditions:
 *   Returns: Creates a response to the selected Memo in the form 
 * of a new document.
 ****************************************************************/
    virtual Memo *CreateResponse(std::string author, std::string textBody, int nextID);

private:
 
    std::vector<std::string> m_distributionList;
};

#endif
