/******************************************************************************
*
* File:    QuarryBlast.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/14/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the QuarryBlast class, which
* is derived from the SeismicEvent class.  It inherits many data and function
* members from SeismicEvent.
*
******************************************************************************/

#ifndef QUARRYBLAST_H
#define QUARRYBLAST_H
#include <iostream>
#include <string>
#include "SeismicEvent.h"


using namespace std;
class QuarryBlast : public SeismicEvent{
	public:
	
/****************************************************************
 * QuarryBlast():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
		QuarryBlast();
		
/****************************************************************
 * QuarryBlast(string time, string latitude, string longitude, string mag, int magType, string place, int type):
 * Preconditions: 
 *	  requires valid time, lat, long, mg, magtype, place and type
 * Postconditions:
 *   Creates a new QuarryBlast object with all of those values
 ****************************************************************/	
		QuarryBlast(string time, string latitude, string longitude, string mag, string place);
	

};

/****************************************************************
 *operator<<(ostream& out, QuarryBlast newObject)
 * Preconditions: 
 *	  requires a valid object of type QuarryBlast
 * Postconditions:
 *   prints all of the fields associated with quarry blasts
 ****************************************************************/
ostream& operator<<(ostream& out, QuarryBlast newObject);

#endif