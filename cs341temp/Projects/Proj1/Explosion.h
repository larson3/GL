/******************************************************************************
*
* File:    Explosion.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/14/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the Explosion class, which
* is derived from the SeismicEvent class.  It inherits many data and function
* members from SeismicEvent.
*
******************************************************************************/

#ifndef EXPLOSION_H
#define EXPLOSION_H
#include <iostream>
#include <string>
#include "SeismicEvent.h"


class Explosion : public SeismicEvent{
	public:
	
/****************************************************************
 * Explosion():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
		Explosion();
		
/****************************************************************
 * Explosion(string time, string latitude, string longitude, string mag, int magType, string place, int type):
 * Preconditions: 
 *	  requires valid time, lat, long, mg, magtype, place and type
 * Postconditions:
 *   Creates a new Explosion object with all of those values
 ****************************************************************/	
		Explosion(string time, string latitude, string longitude, string mag, string place);
	
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
 *operator<<(ostream& out, Explosion newObject)
 * Preconditions: 
 *	  requires a valid object of type Explosion
 * Postconditions:
 *   prints all of the fields associated with Explosions
 ****************************************************************/
ostream& operator<<(ostream& out, Explosion newObject);

#endif