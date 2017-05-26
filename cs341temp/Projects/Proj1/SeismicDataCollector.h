
#ifndef SEISMICDATACOLLECTOR_H
#define SEISMICDATACOLLECTOR_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "SeismicEvent.h"
#include "AcousticNoise.h"
#include "AnthropogenicEvent.h"
#include "Earthquake.h"
#include "Explosion.h"
#include "MiningExplosion.h"
#include "QuarryBlast.h"

/******************************************************************************
*
* File:    SeismicDataCollector.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/14/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the SeismicDataCollector class
*   this is the secondary file, and contains the declarations for the main
*	methods in this program
*
******************************************************************************/

using namespace std;

class SeismicDataCollector
{
	public:
/****************************************************************
 * SeismicDataCollector():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
		SeismicDataCollector();

/****************************************************************
 * readFile():
 * Preconditions: 
 *	  valid string
 * Postconditions:
 *   this method does, oh so much.  It take in, parse data, then save it into one of
 *	 several vectors, and then write it to a corresponding output file
 ****************************************************************/
		void readFile(string fileName);
		
/****************************************************************
 * getFileName():
 * Preconditions: 
 *	  valid string
 * Postconditions:
 *   will return the string m_fileName
 ****************************************************************/		
		string getFileName();

/****************************************************************
 * setFileName():
 * Preconditions: 
 *	  valid string object
 * Postconditions:
 *   for some reason this useless function will change the name of
 *	 m_fileName
 ****************************************************************/		
		bool setFileName(string fileName);
		
/****************************************************************
 * writeResultingData():
 * Preconditions: 
 *	  valid object of type SeismicEvent
 * Postconditions:
 *   will write the contents of the object s in a visually pleasing
 *	 manner
 ****************************************************************/
		void writeResultingData();
		
/****************************************************************
 * whichMagType(string magType):
 * Preconditions: 
 *	  string object which has a corresponding magType
 * Postconditions:
 *   will make the string into magTypeNum form, useful for switching
 ****************************************************************/		
		magTypeNum whichMagType(string magType);
		
/****************************************************************
 * whichType(string type):
 * Preconditions: 
 *	  valid string with corresponding type
 * Postconditions:
 *   is similar to the above function, useful for switch
 ****************************************************************/
		typeNum whichType(string type);
		
	
	private:
		vector<AcousticNoise>acousticNoiseVector;
		vector<AnthropogenicEvent> anthropogenicEventVector;
		vector<Explosion> explosionVector;
		vector<MiningExplosion> miningExplosionVector;
		vector<QuarryBlast> quarryBlastVector;
		vector<Earthquake> earthquakeVector;
		
		string temptime;
		string templatitude;
		string templongitude;
		string tempdepth;
		string tempmag;
		magTypeNum tempmagType;
		string tempplace;
		string tempplace1;
		typeNum temptype;
		string m_fileName;

};

#endif