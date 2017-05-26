#ifndef BADRESPONSEEXCEPTION_H
#define BADRESPONSEEXCEPTION_H

/******************************************************************************
*
* File:    BadResponseException.h
* Project: CMSC 202 Project 5, Fall 2014
* Author:  John Larson (from a skeleton by John Park)
* Date:    12/03/2014
* Section: 7
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the BadResponseException class,
* This class handles exceptions when the user puts in bad input.
* It will catch mistakes, and throw them up a level or two and inform
* the user how they messed up.
*
******************************************************************************/


#include <string>

class BadResponseException {
	public:
 /****************************************************************
 * BadResponseException():
 * Preconditions: 
 *	  none
 * Postconditions:
 *  Just a generic no arg constructor
 ****************************************************************/
		BadResponseException();

 /****************************************************************
 * BadResponseException():
 * Preconditions: 
 *	  parameter
 * Postconditions:
 *   Returns: The selected message informing the user how they messed
 * up.
 ****************************************************************/
		BadResponseException(std::string parameter);

 /****************************************************************
 * GetMessage():
 * Preconditions: 
 *	  none
 * Postconditions:
 *  Returns: the string contents of m_message
 ****************************************************************/
		std::string GetMessage();
	private:
		std::string m_message;


};

#endif
