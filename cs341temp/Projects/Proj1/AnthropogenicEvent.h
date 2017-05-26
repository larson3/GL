/******************************************************************************
*
* File:    AnthropogenicEvent.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/14/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the AnthropogenicEvent class, which
* is derived from the SeismicEvent class.  It inherits many data and function
* members from SeismicEvent.
*
******************************************************************************/

#ifndef ANTHROPOGENICEVENT_H
#define ANTHROPOGENICEVENT_H
#include <iostream>
#include <string>
#include "SeismicEvent.h"


using namespace std;
class AnthropogenicEvent : public SeismicEvent{
	public:
	
/****************************************************************
 * AnthropogenicEvent():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
		AnthropogenicEvent();
		
/****************************************************************
 * AnthropogenicEvent(string time, string latitude, string longitude, string mag, int magType, string place, int type):
 * Preconditions: 
 *	  requires valid time, lat, long, mg, magtype, place and type
 * Postconditions:
 *   Creates a new AnthropogenicEvent object with all of those values
 ****************************************************************/	
		AnthropogenicEvent(string time, string latitude, string longitude, string mag, string place);
	

};

/****************************************************************
 *operator<<(ostream& out, AnthropogenicEvent newObject)
 * Preconditions: 
 *	  requires a valid object of type AnthropogenicEvent
 * Postconditions:
 *   prints all of the fields associated with Anthro events
 ****************************************************************/
 ostream& operator<<(ostream& out, AnthropogenicEvent newObject);

#endif