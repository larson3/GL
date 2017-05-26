/******************************************************************************
*
* File:    Calculate.cpp
* Project: CMSC 341 Project 2, Spring 2015
* Author:  John Larson
* Date:    02/25/2015
* Section: 4
* E-mail:  larson3@umbc.edu 
*
*   This file contains the definition of the Calculate class, which
* is the file which contains the main functions and logic for proj 2
*
******************************************************************************/

#include "Calculate.h"

using namespace std;

Calculate::Calculate(){}

float Calculate::popAndProcess()
{
	//we take the top operator and store it, then pop it off the stack
	tempOp = op.top();
	op.pop();
	tempDigit=value.top();
	//it needs to be a float, not a string to do math with it
	//we take B first, because A and B need to be reversed from their order in the stack 
	// and this is more simple than a swap function
	B=atof(tempDigit.c_str());
	value.pop();
	tempDigit=value.top();
	A=atof(tempDigit.c_str());
	value.pop();
	
	if(tempOp=="+")
	{
		C=A+B;
		return C;
	}
	
	else if(tempOp=="-")
	{
		C=A-B;
		return C;
	}
	
	else if(tempOp=="*")
	{
		C=A*B;
		return C;
	}
	
	else if(tempOp=="/")
	{
		C=A/B;
		return C;
	}
	
	else if(tempOp=="%")
	{
		//fmod and pow are from cmath
		C= fmod(A,B);
		return C;
	}
	
	else if(tempOp=="^")
	{
		C=pow(A,B);
		return C;
	}
	//this should never occur
	return 0;
}
		
void Calculate::push(std::string input)
{
	priority.push(stackPriority[input]);

	op.push(input);
}

void Calculate::readFile(string inFile)
{
	//a long list of mapped keys and values
	inputPriority["+"]=1;
	inputPriority["-"]=1;
	inputPriority["*"]=2;
	inputPriority["/"]=2;
	inputPriority["%"]=2;
	inputPriority["^"]=5;
	inputPriority["("]=6;
	stackPriority["+"]=1;
	stackPriority["-"]=1;
	stackPriority["*"]=2;
	stackPriority["/"]=2;
	stackPriority["%"]=2;
	stackPriority["^"]=4;
	stackPriority["("]=0;
	stackPriority["$"]=-1;
	
	//here we are adding the default values to the stack
	op.push("$");
	value.push("$");
	priority.push(-1);
	
	//creating our ifstream object of the file to be read
	ifstream fileName(inFile.c_str(), ios_base::in);
	bool parenFlag;
	
	//this is deleting any previous text in results.txt
	if( remove( "results.txt" ) != 0 )
		{
			cout<<"";
		}
		else
		{
			cout<<"";
		}
	//parsing the data
	while(getline(fileName, line))
	{
		ss << line;
		
		while(getline(ss,rel,' '))
		{
			//parenFlag is set to default, will only be set to false
			//if there is a problem with parentheses
			parenFlag = true;
			if(inputPriority.find(rel)!=inputPriority.end())
			{
				if(inputPriority[rel]>stackPriority[op.top()])
				{
					//pushing if the input is higher than stack
					push(rel);
					
				}
				else
				{
					//if not we pop, process then push
					temp = popAndProcess();
					stringstream ss1;
					ss1 << temp;
					string tempStr(ss1.str());
					value.push(tempStr);
					
					//checking to see if there's another higher operator
					if(inputPriority[rel]<stackPriority[op.top()])
					{
						
						temp = popAndProcess();
						stringstream ss1;
						ss1 << temp;
						string tempStr(ss1.str());
						value.push(tempStr);
						push(rel);
					}
					else
					{
					push(rel);
					
					}
				}
							
			}
			//popping until we find the end of parentheses
			else if(rel==")")
			{
				while(op.top()!="(")
				{
					if(op.top()=="$")
					{
						parenFlag=false;
						break;
					}
					temp = popAndProcess();
					stringstream ss1;
					ss1 << temp;
					string tempStr(ss1.str());
					value.push(tempStr);
				
				}
				if(parenFlag!=false)
				{
					op.pop();
					priority.pop();
				}
			}
			else
			{
				//pushing a value
				value.push(rel);
			}
					
		}
		//here we will do the final pop and push to the $
		while(op.top()!="$")
		{
			if(op.top()=="(")
			{
				parenFlag = false;
			}
			//turning a float back to a string requires a stringstream
			temp = popAndProcess();
			stringstream ss1;
			ss1 << temp;
			string tempStr(ss1.str());
			value.push(tempStr);
		}
		if(parenFlag!=false)
		{
		writeResultingData(value.top());
		}
		else
		{
			//there was an issue with parentheses
			writeResultingData("invalid");
		}
		//clearing up our stack and stringstream
		value.pop();
		ss.clear();
		
	}
	
	
	fileName.close();

}

void Calculate::writeResultingData(string input)
	{
		//writing a single line to output file
		ofstream outFile("results.txt", ios::app);
		outFile<<input<<endl;
		outFile.close();
	}
	