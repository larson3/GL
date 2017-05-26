/******************************************************************************
*
* File:    MiningExplosion.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/14/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the MiningExplosion class, which
* is derived from the SeismicEvent class.  It inherits many data and function
* members from SeismicEvent.
*
******************************************************************************/

#ifndef MININGEXPLOSION_H
#define MININGEXPLOSION_H
#include <iostream>
#include <string>
#include "SeismicEvent.h"


using namespace std;
class MiningExplosion : public SeismicEvent{
	public:
	
/****************************************************************
 * MiningExplosion():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
		MiningExplosion();
		
/****************************************************************
 * MiningExplosion(string time, string latitude, string longitude, string mag, int magType, string place, int type):
 * Preconditions: 
 *	  requires valid time, lat, long, mg, magtype, place and type
 * Postconditions:
 *   Creates a new MiningExplosion object with all of those values
 ****************************************************************/	
		MiningExplosion(string time, string latitude, string longitude, string mag, string place);
	

};

/****************************************************************
 *operator<<(ostream& out, MiningExplosion newObject)
 * Preconditions: 
 *	  requires a valid object of type MiningExplosion
 * Postconditions:
 *   prints all of the fields associated with mining explosions
 ****************************************************************/
ostream& operator<<(ostream& out, MiningExplosion newObject);

#endif