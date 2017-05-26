/******************************************************************************
*
* File:    Earthquake.cpp
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

#include "Earthquake.h"

using namespace std;

Earthquake::Earthquake(){}
		
Earthquake::Earthquake(string time, string latitude, string longitude, string mag, string place, string depth) : SeismicEvent(time,latitude,longitude,mag,place)
{
	//these are two things which are special in earthquakes
	m_depth = atof(depth.c_str());
	m_fileName = "Earthquake";
}

float Earthquake::getDepth()
{
	return m_depth;
}

void Earthquake::setDepth(float depth)
{
	m_depth = depth;
}

ostream& operator<<(ostream& out, Earthquake newObject)
	{
	//so... many... things
		out<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		out<<"time -> "<<newObject.getTime()<<endl;
		out<<"latitude -> "<<newObject.getLatitude()<<endl;
		out<<"longitude -> "<<newObject.getLongitude()<<endl;
		out<<"depth -> "<<newObject.getDepth()<<endl;
		out<<"mag -> "<<newObject.getMag()<<endl;
		out<<"magType -> "<<newObject.whatMagType(newObject.getMagType())<<endl;
		out<<"place -> "<<newObject.getPlace()<<endl;
		out<<"type -> "<<newObject.whatType(newObject.getType())<<endl;
		return out;
	}
