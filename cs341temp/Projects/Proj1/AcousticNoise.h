/******************************************************************************
*
* File:    AcousticNoise.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/14/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the AcousticNoise class, which
* is derived from the SeismicEvent class.  It inherits many data and function
* members from SeismicEvent.
*
******************************************************************************/

#ifndef ACOUSTICNOISE_H
#define ACOUSTICNOISE_H
#include <iostream>
#include <string>
#include "SeismicEvent.h"

using namespace std;


class AcousticNoise : public SeismicEvent{
	public:
	
/****************************************************************
 * AcousticNoise():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
		AcousticNoise();
		
/****************************************************************
 * AcousticNoise(string time, string latitude, string longitude, string mag, int magType, string place, int type):
 * Preconditions: 
 *	  requires valid time, lat, long, mg, magtype, place and type
 * Postconditions:
 *   Creates a new AcousticNoise object with all of those values
 ****************************************************************/	
		AcousticNoise(string time, string latitude, string longitude, string mag, string place);
	
/****************************************************************
 * getMagType():
 * Preconditions: 
 *	  requires a valid object with an m_magType data member
 * Postconditions:
 *   returns m_magType
 ****************************************************************/
		enum magTypeNum getMagType();

};

/****************************************************************
 *operator<<(ostream& out, AcousticNoise newObject)
 * Preconditions: 
 *	  requires a valid object of type AcousticNoise
 * Postconditions:
 *   prints all of the fields associated with Acoustic Noises
 ****************************************************************/
ostream& operator<<(ostream& out, AcousticNoise newObject);

#endif