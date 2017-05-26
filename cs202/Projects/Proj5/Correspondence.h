#ifndef CORRESPONDENCE_H
#define CORRESPONDENCE_H

/******************************************************************************
*
* File:    Correspondence.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Larson (from a skeleton by John Park)
* Date:    12/03/2014
* Section: 7
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the Correspondence class, it is the
* parent class to both Memo and Email and passes a few functions to them
*
******************************************************************************/


#include <string>
#include "Document.h"



class Correspondence : public Document {
public:
   
    Correspondence(int aID, std::string author,
		   std::string textBody, std::string subject, std::string recipientName);
		   
	
	std::string GetSubject();
	std::string GetRecipientName();
	

private:
	std::string m_subject;
	std::string m_recipientName;
};

#endif
