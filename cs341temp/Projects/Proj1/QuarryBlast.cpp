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

#include "QuarryBlast.h"

using namespace std;

QuarryBlast::QuarryBlast(){}
		
QuarryBlast::QuarryBlast(string time, string latitude, string longitude, string mag, string place) : SeismicEvent(time,latitude,longitude,mag,place)
{
	m_fileName = "QuarryBlast";
}

ostream& operator<<(ostream& out, QuarryBlast newObject)
	{
		out<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		out<<"time -> "<<newObject.getTime()<<endl;
		out<<"latitude -> "<<newObject.getLatitude()<<endl;
		out<<"longitude -> "<<newObject.getLongitude()<<endl;
		out<<"mag -> "<<newObject.getMag()<<endl;
		out<<"place -> "<<newObject.getPlace()<<endl;
		out<<"type -> "<<newObject.whatType(newObject.getType())<<endl;
		return out;
	}