/******************************************************************************
*
* File:    Calculate.h
* Project: CMSC 341 Project 1, Spring 2015
* Author:  John Larson
* Date:    02/25/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the Calculate class
*
******************************************************************************/

#ifndef CALCULATE_H
#define CALCULATE_H
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <stack>
#include <stdlib.h>
#include <cmath>

class Calculate
{
	public:

/****************************************************************
 * Calculate():
 * Preconditions: 
 *	  none
 * Postconditions:
 *   none, base constructor
 ****************************************************************/
		Calculate();
		
/****************************************************************
 * popAndProcess(string):
 * Preconditions: 
 *	  valid string
 * Postconditions:
 *   This method will pop two digits and an operator and return a result float
 ****************************************************************/
		float popAndProcess();

/****************************************************************
 * push(string):
 * Preconditions: 
 *	  valid string
 * Postconditions:
 *   This method will push a string onto the operator stack as well
 *	 as an int to the priority stack
 ****************************************************************/
		void push(std::string input);
		
/****************************************************************
 * readFile(string):
 * Preconditions: 
 *	  valid string
 * Postconditions:
 *   This method will take in, parse data, then place the info into stacks
 *   will perform operations and then write it to a corresponding output file
 ****************************************************************/
		
		void readFile(std::string inFile);
		
/****************************************************************
 * writeResultingData(string):
 * Preconditions: 
 *	  valid string
 * Postconditions:
 *  This method will take a string and append it to an existing data file
 *  it will ONLY append, deletion of existing text needs to be handled outside!
 ****************************************************************/
		void writeResultingData(std::string input);
		
		
		
	private:
		float temp;
		float A;
		float B;
		float C;
		float result;
		std::string tempDigit;
		std::string tempOp;
		std::stringstream ss;
		std::string line;
		std::string rel;
		std::map<std::string, int> inputPriority;
		std::map<std::string, int> stackPriority;
		std::stack<std::string>op;
		std::stack<int>priority;
		std::stack<std::string>value;
		
		
	
};
#endif