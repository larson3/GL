/******************************************************************************
*
* File:    Earthquake.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/14/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the Earthquake class, which
* is derived from the SeismicEvent class.  It inherits many data and function
* members from SeismicEvent.
*
******************************************************************************/

#ifndef EARTHQUAKE_H
#define EARTHQUAKE_H
#include <iostream>
#include <string>
#include "SeismicEvent.h"

class Earthquake : public SeismicEvent
{
	public:
	
	/****************************************************************
 * AcousticNoise():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
		Earthquake();
		
/****************************************************************
 * AcousticNoise(string time, string latitude, string longitude, string mag, int magType, string place, int type):
 * Preconditions: 
 *	  requires valid time, lat, long, mg, magtype, place and type
 * Postconditions:
 *   Creates a new AcousticNoise object with all of those values
 ****************************************************************/	
		Earthquake(string time, string latitude, string longitude, string mag, string place, string depth);
	
/****************************************************************
 * getDepth():
 * Preconditions: 
 *	  requires a valid object with an m_depth data member
 * Postconditions:
 *   returns m_depth
 ****************************************************************/
	
		float getDepth();
		
/****************************************************************
 * setDepth():
 * Preconditions: 
 *	  requires a valid object with an m_depth data member and a depth of type
 *    float
 * Postconditions:
 *   sets m_depth to depth
 ****************************************************************/
		void setDepth(float depth);
		
	private:
		float m_depth;
	
};

/****************************************************************
 *operator<<(ostream& out, Earthquake newObject)
 * Preconditions: 
 *	  requires a valid object of type Earthquake
 * Postconditions:
 *   prints all of the fields associated with earthquakes
 ****************************************************************/
ostream& operator<<(ostream& out, Earthquake newObject);

#endif