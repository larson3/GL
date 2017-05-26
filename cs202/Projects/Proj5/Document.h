#ifndef DOCUMENT_H
#define DOCUMENT_H

/****************************************************************
 * File:    Document.h
 * Project: CMSC 202 Project 5, Spring 2014
 * Author:  John Larson (From a skeleton by John Park)
 * Date:    12/6/2014
 * Section: all
 * E-mail:  larson3@umbc.edu 
 *
 * This file contains the header for the Document class.  The majority
 * of which was written by John Park.  Most of the changes were done 
 * to the functions which are not listed a virtual, in order to make
 * them work as polymorphic functions.
 *
 *
 ****************************************************************/

#include <string>


class Document {
public:
    Document();
	virtual ~Document();
    Document(int aID, std::string author, std::string textBody);
	//I moved a lot of these functions into this file so they could be 
	//inherited.  I won't write headers for though,
	// as I did not write them.
    int GetID();
    std::string GetAuthor();
    std::string GetBody();
	//I made two of these functions pure virtual, but I feel that a header
	//would be unnecessary and clutter the code
	virtual void DisplayHeader()=0;
	virtual void DisplayBody();
	virtual bool Search(std::string searchString);
	virtual Document *CreateResponse(std::string author, std::string textBody, 
		int m_nextID)=0;
private:
    int m_type;
    int m_ID;
    std::string m_author;
    std::string m_textBody;
};

#endif
