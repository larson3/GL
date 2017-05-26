#include <iostream>
#include "SeismicEvent.h"

using namespace std;

SeismicEvent::SeismicEvent(){}

SeismicEvent::SeismicEvent(string time, string latitude, string longitude, string mag, string place)
{
	//constructor using c_str() because otherwise atof wouldn't work
	m_time = time;
	m_latitude = atof(latitude.c_str());
	m_longitude = atof(longitude.c_str());
	m_mag = atof(mag.c_str());
	m_place = place;
	
}

void SeismicEvent::setTime(string time)
{
	m_time = time;
}
		
string SeismicEvent::getTime()
{
	return m_time;
}
		
float SeismicEvent::getLatitude()
{
	return m_latitude;
}
		
void SeismicEvent::setLatitude(float latitude)
{
	m_latitude = latitude;
}

float SeismicEvent::getLongitude()
{
	return m_longitude;
}
		
		
void SeismicEvent::setLongitude(float longitude)
{
	m_longitude = longitude;
}
				
float SeismicEvent::getMag()
{
	//shut up mag
	return m_mag;
}
		
void SeismicEvent::setMag(float mag)
{
	m_mag = mag;
}
		
enum magTypeNum SeismicEvent::getMagType()
{
	return m_magType;
}
		
void SeismicEvent::setMagType(magTypeNum magType)
{
	m_magType = magType;
}
		
string SeismicEvent::getPlace()
{
	return m_place;
}
		
void SeismicEvent::setPlace(string place)
{
	m_place = place;
}
		
enum typeNum SeismicEvent::getType()
{
	return m_type;
}
		
void SeismicEvent::setType(typeNum type)
{
	m_type = type;
}

float SeismicEvent::getDepth()
{
	//it wanted me to return something, so I did.  This is never going to 
	//be called so it's cool
	return 2.0;
}

string SeismicEvent::whatMagType(int magType)
{
	//kind of the opposite of the whichMagType, sometimes you need 
	//a string to print to make things look pretty
	switch(magType)
	{
		case 0:
			return "md";
		case 1:
			return "ml";
		case 2:
			return "mb";
		case 3:
			return "mb_lg";
	}
	return "error";
}

string SeismicEvent::whatType(int type)
{//see above
	switch(type)
	{
		case 0:
			return "acoustic noise";
		case 1:
			return "anthropogenic event";
		case 2:
			return "explosion";
		case 3:
			return "mining explosion";
		case 4:
			return "quarry blast";
		case 5:
			return "earthquake";
		

	}
	return 0;
}

ostream& operator<<(ostream& out, SeismicEvent newObject)
	{
		//just a simple overloaded cout
		out<<"%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
		out<<"time -> "<<newObject.getTime()<<endl;
		out<<"latitude -> "<<newObject.getLatitude()<<endl;
		out<<"longitude -> "<<newObject.getLongitude()<<endl;
		out<<"mag -> "<<newObject.getMag()<<endl;
		out<<"place -> "<<newObject.getPlace()<<endl;
		out<<"type -> "<<newObject.whatType(newObject.getType())<<endl;
		return out;
	}
