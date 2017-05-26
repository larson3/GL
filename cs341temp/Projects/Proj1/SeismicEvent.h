#ifndef SEISMICEVENT_H
#define SEISMICEVENT_H
#include <iostream>
#include <string>
#include <stdlib.h>

/******************************************************************************
*
* File:    SeismicEvent.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/14/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the SeismicEvent class, which
* is derived from the SeismicEvent class.  It inherits many data and function
* members from SeismicEvent.
*
******************************************************************************/

using namespace std;

enum magTypeNum {md = 0 , ml , mb , mb_lg};
enum typeNum {acoustic_noise = 0 , anthropogenic_event , explosion,
mining_explosion, quarry_blast, earthquake};

class SeismicEvent
{
	

	public:
	
/****************************************************************
 * SeismicEvent():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   base contructor
 ****************************************************************/
		SeismicEvent();
		
/****************************************************************
 * SeismicEvent(string time, string latitude, string longitude, string mag, string place):
 * Preconditions: 
 *	  none
 * Postconditions:
 *   creates a SeismicEvent object with a ton of things in it
 ****************************************************************/
		SeismicEvent(string time, string latitude, string longitude, string mag, string place);
		
/****************************************************************
 * setTime(string time):
 * Preconditions: 
 *	  requires a valid object with an m_time data member and a type of string
 * Postconditions:
 *   sets m_time to time
 ****************************************************************/
		void setTime(string time);
		
/****************************************************************
 * getTime():
 * Preconditions: 
 *	  requires a an object with a data member m_time
 * Postconditions:
 *   returns m_time
 ****************************************************************/
		string getTime();
		
/****************************************************************
 * getLatitude():
 * Preconditions: 
 *	  requires a valid object with an m_latitude data member and a type of float
 * Postconditions:
 *   returns m_latitude
 ****************************************************************/
		float getLatitude();
		
/****************************************************************
 * setLatitude(float latitude):
 * Preconditions: 
 *	  requires a valid object with an m_latitude data member and a type of float
 * Postconditions:
 *   sets m_latitude to latitude
 ****************************************************************/
		void setLatitude(float latitude);

/****************************************************************
 * getLongitude():
 * Preconditions: 
 *	  requires a valid object with an m_latitude data member
 * Postconditions:
 *   sets m_latitude to latitude
 ****************************************************************/
		float getLongitude();

/****************************************************************
 * setLongitude(float longitude):
 * Preconditions: 
 *	  requires a valid object with an m_longitude data member
 * Postconditions:
 *   sets m_longitude to longitude
 ****************************************************************/
		void setLongitude(float longitude);

/****************************************************************
 * getMag():
 * Preconditions: 
 *	  requires a valid object with an m_Mag data member
 * Postconditions:
 *   returns m_Mag
 ****************************************************************/
		float getMag();
		
/****************************************************************
 * setMag(float mag):
 * Preconditions: 
 *	  requires a valid object with an m_mag data member and a float mag
 * Postconditions:
 *   returns m_mag
 ****************************************************************/
		void setMag(float mag);
		
/****************************************************************
 * getMagType():
 * Preconditions: 
 *	  requires a valid object with an m_magType data member
 * Postconditions:
 *   returns m_magType
 ****************************************************************/
		virtual enum magTypeNum getMagType();

/****************************************************************
 * setMagType(magType):
 * Preconditions: 
 *	  requires a valid object with an m_magType data member and an
 *	  argument of type magTypeNum
 * Postconditions:
 *   sets m_magType to magType
 ****************************************************************/		
		void setMagType(enum magTypeNum magType);
		
/****************************************************************
 * getPlace():
 * Preconditions: 
 *	  requires a valid object with an m_place
 * Postconditions:
 *   returns m_place
 ****************************************************************/
		string getPlace();
		
/****************************************************************
 * setPlace():
 * Preconditions: 
 *	  requires a valid object with an m_place and a string arg
 * Postconditions:
 *   sets m_place to place
 ****************************************************************/
		void setPlace(string place);

/****************************************************************
 * getType():
 * Preconditions: 
 *	  requires a valid object with an m_type
 * Postconditions:
 *   i'm getting pretty sick of saying the same thing.
 ****************************************************************/
		enum typeNum getType();
		
/****************************************************************
 * setType():
 * Preconditions: 
 *	  requires a valid object with an m_type and an appropriate arg
 * Postconditions:
 *   sets m_type to type
 ****************************************************************/
		void setType(typeNum type);
		
/****************************************************************
 * whatType():
 * Preconditions: 
 *	  takes in an int type
 * Postconditions:
 *   will return a typeNum... type
 ****************************************************************/
		string whatType(int type);
		
/****************************************************************
 * whatMagType():
 * Preconditions: 
 *	  takes in an int type
 * Postconditions:
 *   will return a magTypeNum... type
 ****************************************************************/
		string whatMagType(int magType);
		
		
/****************************************************************
 * getDepth():
 * Preconditions: 
 *	  
 * Postconditions:
 *   this is virtual and should never be called
 ****************************************************************/
		virtual float getDepth();
		
	protected:
		string m_time;
		float m_latitude;
		float m_longitude;
		float m_mag;
		enum magTypeNum m_magType;
		string m_place;
		enum typeNum m_type;
		float m_depth;
		string m_fileName;
};
/****************************************************************
 *operator<<(ostream& out, SeismicEvent newObject)
 * Preconditions: 
 *	  requires a valid object of type SeismicEvent
 * Postconditions:
 *   prints all of the fields associated with events
 ****************************************************************/
	ostream& operator<<(ostream& out, SeismicEvent newObject);
	
#endif